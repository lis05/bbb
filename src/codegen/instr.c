#include "instr.h"

static const char *fmt_stack_offset(int64_t offset) {
#define N 128
    static char buf[N];

    if (offset > 0) {
        snprintf(buf, N, "rbp + %zu", (size_t)offset);
    } else if (offset < 0) {
        snprintf(buf, N, "rbp - %zu", (size_t)(-offset));
    } else {
        snprintf(buf, N, "rbp");
    }

    return buf;
#undef N
}

int instr_move_gpr_into_mem(cb_t *cb, int indent, gpr_reg_t reg, size_t len,
                            int64_t stack_offset, gpr_reg_t temp) {
    switch (len) {
    case 8:
        cb_add_back(cb, indent, "mov qword [%s], %s\n",
                    fmt_stack_offset(stack_offset), reg->qname);
        break;
    case 7:
        cb_add_back(cb, indent, "mov %s, %s\n", temp->qname, reg->qname);
        cb_add_back(cb, indent, "shr %s, 32\n", temp->qname);
        cb_add_back(cb, indent, "mov word [%s], %s\n",
                    fmt_stack_offset(stack_offset + 4), temp->wname);
        cb_add_back(cb, indent, "shr %s, 16\n", temp->dname);
        cb_add_back(cb, indent, "mov byte [%s], %s\n",
                    fmt_stack_offset(stack_offset + 6), temp->bname);
        goto jmp_4bytes;
    case 6:
        cb_add_back(cb, indent, "mov %s, %s\n", temp->qname, reg->qname);
        cb_add_back(cb, indent, "shr %s, 32\n", temp->qname);
        cb_add_back(cb, indent, "mov word [%s], %s\n",
                    fmt_stack_offset(stack_offset + 4), temp->wname);
        goto jmp_4bytes;
    case 5:
        cb_add_back(cb, indent, "mov %s, %s\n", temp->qname, reg->qname);
        cb_add_back(cb, indent, "shr %s, 32\n", temp->qname);
        cb_add_back(cb, indent, "mov byte [%s], %s\n",
                    fmt_stack_offset(stack_offset + 4), temp->bname);
    case 4:
        goto jmp_4bytes;  // shut up gcc, fallthrough is indended
    jmp_4bytes:
        cb_add_back(cb, indent, "mov dword [%s], %s\n",
                    fmt_stack_offset(stack_offset), reg->dname);
        break;
    case 3:
        cb_add_back(cb, indent, "mov %s, %s\n", temp->qname, reg->qname);
        cb_add_back(cb, indent, "shr %s, 8\n", temp->qname);
        cb_add_back(cb, indent, "mov word [%s], %s\n",
                    fmt_stack_offset(stack_offset + 1), temp->wname);
        goto jmp_1byte;
    case 2:
        cb_add_back(cb, indent, "mov word [%s], %s\n",
                    fmt_stack_offset(stack_offset), reg->wname);
        break;
    case 1:
    jmp_1byte:
        cb_add_back(cb, indent, "mov byte [%s], %s\n",
                    fmt_stack_offset(stack_offset), reg->bname);
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
    }
    else if (len == 8) {
        cb_add_back(cb, indent, "movsd [%s], %s\n", fmt_stack_offset(stack_offset), reg->name);
        return 0;
    }
    else if (len == 4) {
        cb_add_back(cb, indent, "movss [%s], %s\n", fmt_stack_offset(stack_offset), reg->name);
        return 0;
    }
    else {
        cb_add_back(cb, indent, "movq %s, %s\n", temp1->qname, reg->name);
        return instr_move_gpr_into_mem(cb, indent, temp1, len, stack_offset, temp2);
    }
}
