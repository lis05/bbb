#include "instr.h"
#include "util.h"

int instr_move_gpr_into_mem(cb_t *cb, int indent, gpr_reg_t reg, size_t len,
                            int64_t stack_offset, gpr_reg_t temp) {
    switch (len) {
    case 8:
        cb_add_back(cb, indent, "mov qword [%s], %s\n", fmt_stack_offset(stack_offset),
                    reg->qname);
        break;
    case 7:
        cb_add_back(cb, indent, "mov %s, %s\n", temp->qname, reg->qname);
        cb_add_back(cb, indent, "shr %s, 32\n", temp->qname);
        cb_add_back(cb, indent, "mov word [%s], %s\n", fmt_stack_offset(stack_offset + 4),
                    temp->wname);
        cb_add_back(cb, indent, "shr %s, 16\n", temp->dname);
        cb_add_back(cb, indent, "mov byte [%s], %s\n", fmt_stack_offset(stack_offset + 6),
                    temp->bname);
        goto jmp_4bytes;
    case 6:
        cb_add_back(cb, indent, "mov %s, %s\n", temp->qname, reg->qname);
        cb_add_back(cb, indent, "shr %s, 32\n", temp->qname);
        cb_add_back(cb, indent, "mov word [%s], %s\n", fmt_stack_offset(stack_offset + 4),
                    temp->wname);
        goto jmp_4bytes;
    case 5:
        cb_add_back(cb, indent, "mov %s, %s\n", temp->qname, reg->qname);
        cb_add_back(cb, indent, "shr %s, 32\n", temp->qname);
        cb_add_back(cb, indent, "mov byte [%s], %s\n", fmt_stack_offset(stack_offset + 4),
                    temp->bname);
    case 4:
        goto jmp_4bytes;  // shut up gcc, fallthrough is indended
    jmp_4bytes:
        cb_add_back(cb, indent, "mov dword [%s], %s\n", fmt_stack_offset(stack_offset),
                    reg->dname);
        break;
    case 3:
        cb_add_back(cb, indent, "mov %s, %s\n", temp->qname, reg->qname);
        cb_add_back(cb, indent, "shr %s, 8\n", temp->qname);
        cb_add_back(cb, indent, "mov word [%s], %s\n", fmt_stack_offset(stack_offset + 1),
                    temp->wname);
        goto jmp_1byte;
    case 2:
        cb_add_back(cb, indent, "mov word [%s], %s\n", fmt_stack_offset(stack_offset),
                    reg->wname);
        break;
    case 1:
    jmp_1byte:
        cb_add_back(cb, indent, "mov byte [%s], %s\n", fmt_stack_offset(stack_offset),
                    reg->bname);
        break;
    default:
        return -1;
    }
    return 0;
}

int instr_move_sse_into_mem(cb_t *cb, int indent, sse_reg_t reg, size_t len,
                            int64_t stack_offset, gpr_reg_t temp1, gpr_reg_t temp2) {
    if (len > 8) {
        return -1;
    } else if (len == 8) {
        cb_add_back(cb, indent, "movsd [%s], %s\n", fmt_stack_offset(stack_offset),
                    reg->name);
        return 0;
    } else if (len == 4) {
        cb_add_back(cb, indent, "movss [%s], %s\n", fmt_stack_offset(stack_offset),
                    reg->name);
        return 0;
    } else {
        cb_add_back(cb, indent, "movq %s, %s\n", temp1->qname, reg->name);
        return instr_move_gpr_into_mem(cb, indent, temp1, len, stack_offset, temp2);
    }
}

int instr_move_mem_into_mem(cb_t *cb, int indent, int64_t from_offset, size_t len,
                            int64_t to_offset, struct label_generator_t *lblg,
                            gpr_reg_t temp1, gpr_reg_t temp2) {
#define THRESHOLD 128
    if (len >= THRESHOLD) {
        const char *loop_label = lblg_gen(lblg);
        const char *end_label = lblg_gen(lblg);
        cb_add_back(cb, indent, "mov %s, %zu\n", temp1->qname, len - len % 8);
        cb_add_back(cb, indent, "%s:\n", loop_label);
        cb_add_back(cb, indent + CB_TAB, "test %s, %s\n", temp1->qname,
                    temp1->qname);
        cb_add_back(cb, indent + CB_TAB, "jz %s\n", end_label);
        cb_add_back(cb, indent + CB_TAB, "mov %s, qword [%s + %s]\n", temp2->qname,
                    fmt_stack_offset(from_offset - 8), temp1->qname);
        cb_add_back(cb, indent + CB_TAB, "mov qword [%s + %s], %s\n",
                    fmt_stack_offset(to_offset - 8), temp1->qname, temp2->qname);
        cb_add_back(cb, indent + CB_TAB, "sub %s, 8\n", temp1->qname);
        cb_add_back(cb, indent + CB_TAB, "jmp %s\n", loop_label);
        cb_add_back(cb, indent, "%s:\n", end_label);

        from_offset += len - len % 8;
        to_offset += len - len % 8;
        len %= 8;
    }

    for (size_t i = 0; i + 8 <= len; i += 8) {
        cb_add_back(cb, indent, "mov %s, qword [%s]\n", temp2->qname,
                    fmt_stack_offset(from_offset + i));
        cb_add_back(cb, indent, "mov qword [%s], %s\n", fmt_stack_offset(to_offset + i),
                    temp2->qname);
    }

    from_offset += len - len % 8;
    to_offset += len - len % 8;
    len %= 8;

    if (len == 0) {
        return 0;
    }

    if (len >= 4) {
        cb_add_back(cb, indent, "mov %s, dword [%s]\n", temp2->dname,
                    fmt_stack_offset(from_offset));
        cb_add_back(cb, indent, "mov dword [%s], %s\n", fmt_stack_offset(to_offset),
                    temp2->dname);
        from_offset += 4;
        to_offset += 4;
        len -= 4;
    }

    if (len >= 2) {
        cb_add_back(cb, indent, "mov %s, word [%s]\n", temp2->wname,
                    fmt_stack_offset(from_offset));
        cb_add_back(cb, indent, "mov word [%s], %s\n", fmt_stack_offset(to_offset),
                    temp2->wname);
        from_offset += 2;
        to_offset += 2;
        len -= 2;
    }

    if (len >= 1) {
        cb_add_back(cb, indent, "mov %s, byte [%s]\n", temp2->bname,
                    fmt_stack_offset(from_offset));
        cb_add_back(cb, indent, "mov byte [%s], %s\n", fmt_stack_offset(to_offset),
                    temp2->bname);
        from_offset += 1;
        to_offset += 1;
        len -= 1;
    }

    return 0;
#undef THRESHOLD
}
