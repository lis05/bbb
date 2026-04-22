#include "../parser/error.h"
#include "instr.h"
#include "util.h"

// TODO 1: remove limitations to just 8|4|2|1 bytes

int STATUSCODE instr_move_int_into_gpr(cb_t *cb, int indent, int64_t lit, size_t len,
                                       gpr_reg_t to, const tfrag_t *frag) {
    if (len == 8) {
        cb_add_back(cb, indent, "mov %s, %" PRId64 "\n", to->qname, lit);
    } else if (len == 4) {
        cb_add_back(cb, indent, "mov %s, %" PRId64 "\n", to->dname, lit);
    } else if (len == 2) {
        cb_add_back(cb, indent, "mov %s, %" PRId64 "\n", to->wname, lit);
    } else if (len == 1) {
        cb_add_back(cb, indent, "mov %s, %" PRId64 "\n", to->bname, lit);
    } else {
        context_msg(frag, "Error: can only move 8, 4, 2, or 1 bytes.\n");
        return -1;
    }
    return 0;
}

int STATUSCODE instr_move_int_into_mem(cb_t *cb, int indent, int64_t lit, size_t len,
                                       struct util_memory_address_t to,
                                       const tfrag_t               *frag) {
    if (len == 8) {
        cb_add_back(cb, indent, "mov qword [%s], %" PRId64 "\n",
                    util_format_memory_address(to), lit);
    } else if (len == 4) {
        cb_add_back(cb, indent, "mov dword [%s], %" PRId64 "\n",
                    util_format_memory_address(to), lit);
    } else if (len == 2) {
        cb_add_back(cb, indent, "mov word [%s], %" PRId64 "\n",
                    util_format_memory_address(to), lit);
    } else if (len == 1) {
        cb_add_back(cb, indent, "mov byte [%s], %" PRId64 "\n",
                    util_format_memory_address(to), lit);
    } else {
        context_msg(frag, "Error: can only move 8, 4, 2, or 1 bytes.\n");
        return -1;
    }
    return 0;
}

int STATUSCODE instr_move_uint_into_gpr(cb_t *cb, int indent, uint64_t lit,
                                        size_t len, gpr_reg_t to,
                                        const tfrag_t *frag) {
    if (len == 8) {
        cb_add_back(cb, indent, "mov %s, %" PRIu64 "\n", to->qname, lit);
    } else if (len == 4) {
        cb_add_back(cb, indent, "mov %s, %" PRIu64 "\n", to->dname, lit);
    } else if (len == 2) {
        cb_add_back(cb, indent, "mov %s, %" PRIu64 "\n", to->wname, lit);
    } else if (len == 1) {
        cb_add_back(cb, indent, "mov %s, %" PRIu64 "\n", to->bname, lit);
    } else {
        context_msg(frag, "Error: can only move 8, 4, 2, or 1 bytes.\n");
        return -1;
    }
    return 0;
}

int STATUSCODE instr_move_uint_into_mem(cb_t *cb, int indent, uint64_t lit,
                                        size_t len, struct util_memory_address_t to,
                                        const tfrag_t *frag) {
    if (len == 8) {
        cb_add_back(cb, indent, "mov qword [%s], %" PRIu64 "\n",
                    util_format_memory_address(to), lit);
    } else if (len == 4) {
        cb_add_back(cb, indent, "mov dword [%s], %" PRIu64 "\n",
                    util_format_memory_address(to), lit);
    } else if (len == 2) {
        cb_add_back(cb, indent, "mov word [%s], %" PRIu64 "\n",
                    util_format_memory_address(to), lit);
    } else if (len == 1) {
        cb_add_back(cb, indent, "mov byte [%s], %" PRIu64 "\n",
                    util_format_memory_address(to), lit);
    } else {
        context_msg(frag, "Error: can only move 8, 4, 2, or 1 bytes.\n");
        return -1;
    }
    return 0;
}

int STATUSCODE instr_move_gpr_into_gpr(cb_t *cb, int indent, gpr_reg_t from,
                                       gpr_reg_t to, size_t len,
                                       const tfrag_t *frag) {
    if (len == 8) {
        cb_add_back(cb, indent, "mov %s, %s\n", to->qname, from->qname);
    } else if (len == 4) {
        cb_add_back(cb, indent, "mov %s, %s\n", to->dname, from->dname);
    } else if (len == 2) {
        cb_add_back(cb, indent, "mov %s, %s\n", to->wname, from->wname);
    } else if (len == 1) {
        cb_add_back(cb, indent, "mov %s, %s\n", to->bname, from->bname);
    } else {
        context_msg(
            frag,
            "Error: cannot move %zu bytes from %s into %s. Must be 8, 4, 2, or 1.\n",
            len, from->qname, to->qname);
        return -1;
    }
    return 0;
}

int STATUSCODE instr_move_gpr_into_sse(cb_t *cb, int indent, gpr_reg_t from,
                                       sse_reg_t to, size_t len,
                                       const tfrag_t *frag) {
    if (len == 8) {
        cb_add_back(cb, indent, "movq %s, %s\n", to->name, from->qname);
    } else if (len == 4) {
        cb_add_back(cb, indent, "movd %s, %s\n", to->name, from->dname);
    } else {
        context_msg(
            frag, "Error: cannot move %zu bytes from %s into %s. Must be 8 or 4.\n",
            len, from->qname, to->name);
        return -1;
    }
    return 0;
}

int STATUSCODE instr_move_gpr_into_mem(cb_t *cb, int indent, gpr_reg_t from,
                                       size_t len, struct util_memory_address_t to,
                                       const tfrag_t *frag) {
    if (len == 8) {
        cb_add_back(cb, indent, "mov [%s], %s\n", util_format_memory_address(to),
                    from->qname);
    } else if (len == 4) {
        cb_add_back(cb, indent, "mov [%s], %s\n", util_format_memory_address(to),
                    from->dname);
    } else if (len == 2) {
        cb_add_back(cb, indent, "mov [%s], %s\n", util_format_memory_address(to),
                    from->wname);
    } else if (len == 1) {
        cb_add_back(cb, indent, "mov [%s], %s\n", util_format_memory_address(to),
                    from->bname);
    } else {
        context_msg(
            frag,
            "Error: cannot move %zu bytes from %s into %s. Must be 8, 4, 2 or 1.\n",
            len, from->qname, util_format_memory_address(to));
        return -1;
    }
    return 0;
}

int STATUSCODE instr_move_sse_into_gpr(cb_t *cb, int indent, sse_reg_t from,
                                       size_t len, gpr_reg_t to,
                                       const tfrag_t *frag) {
    if (len == 8) {
        cb_add_back(cb, indent, "movss %s, %s\n", to->qname, from->name);
    } else if (len == 4) {
        cb_add_back(cb, indent, "movss %s, %s\n", to->dname, from->name);
    } else {
        context_msg(
            frag, "Error: cannot move %zu bytes from %s into %s. Must be 8 or 4.\n",
            len, from->name, to->qname);
        return -1;
    }
    return 0;
}

int STATUSCODE instr_move_sse_into_sse(cb_t *cb, int indent, sse_reg_t from,
                                       size_t len, sse_reg_t to,
                                       const tfrag_t *frag) {
    if (len == 8) {
        cb_add_back(cb, indent, "movss %s, %s\n", to->name, from->name);
    } else if (len == 4) {
        cb_add_back(cb, indent, "movss %s, %s\n", to->name, from->name);
    } else {
        context_msg(
            frag, "Error: cannot move %zu bytes from %s into %s. Must be 8 or 4.\n",
            len, from->name, to->name);
        return -1;
    }
    return 0;
}

int STATUSCODE instr_move_sse_into_mem(cb_t *cb, int indent, sse_reg_t from,
                                       size_t len, struct util_memory_address_t to,
                                       const tfrag_t *frag) {
    if (len == 8) {
        cb_add_back(cb, indent, "movsd [%s], %s\n", util_format_memory_address(to),
                    from->name);
    } else if (len == 4) {
        cb_add_back(cb, indent, "movss [%s], %s\n", util_format_memory_address(to),
                    from->name);
    } else {
        context_msg(
            frag, "Error: cannot move %zu bytes from %s into %s. Must be 8 or 4.\n",
            len, from->name, util_format_memory_address(to));
        return -1;
    }
    return 0;
}

int STATUSCODE instr_move_mem_into_gpr(cb_t *cb, int indent,
                                       struct util_memory_address_t from, size_t len,
                                       gpr_reg_t to, const tfrag_t *frag) {
    if (len == 8) {
        cb_add_back(cb, indent, "mov %s, [%s]\n", to->qname,
                    util_format_memory_address(from));
    } else if (len == 4) {
        cb_add_back(cb, indent, "mov %s, [%s]\n", to->dname,
                    util_format_memory_address(from));
    } else if (len == 2) {
        cb_add_back(cb, indent, "mov %s, [%s]\n", to->wname,
                    util_format_memory_address(from));
    } else if (len == 1) {
        cb_add_back(cb, indent, "mov %s, [%s]\n", to->bname,
                    util_format_memory_address(from));
    } else {
        context_msg(
            frag,
            "Error: cannot move %zu bytes from %s into %s. Must be 8, 4, 2 or 1.\n",
            len, util_format_memory_address(from), to->qname);
        return -1;
    }
    return 0;
}

int STATUSCODE instr_move_mem_into_sse(cb_t *cb, int indent,
                                       struct util_memory_address_t from, size_t len,
                                       sse_reg_t to, const tfrag_t *frag) {
    if (len == 8) {
        cb_add_back(cb, indent, "movq %s, [%s]\n", to->name,
                    util_format_memory_address(from));
    } else if (len == 4) {
        cb_add_back(cb, indent, "movd %s, [%s]\n", to->name,
                    util_format_memory_address(from));
    } else {
        context_msg(
            frag, "Error: cannot move %zu bytes from %s into %s. Must be 8 or 4.\n",
            util_format_memory_address(from), to->name);
        return -1;
    }
    return 0;
}

int STATUSCODE instr_move_mem_into_mem(cb_t *cb, int indent,
                                       struct util_memory_address_t from, size_t len,
                                       struct util_memory_address_t to,
                                       struct label_generator_t    *lblg,
                                       struct gpr_pool_t           *pool,
                                       const tfrag_t               *frag) {
#define THRESHOLD 128
    struct gpr_pool_item_t *temp1 = NULL, *temp2 = NULL;
    if (len >= THRESHOLD) {
        const char *loop_label = lblg_gen(lblg);
        const char *end_label = lblg_gen(lblg);
        temp1 = gpr_pool_borrow(frag, pool);
        temp2 = gpr_pool_borrow(frag, pool);
        cb_add_back(cb, indent, "mov %s, %zu\n", temp1->reg->qname, len - len % 8);
        cb_add_back(cb, indent, "%s:\n", loop_label);
        cb_add_back(cb, indent + CB_TAB, "test %s, %s\n", temp1->reg->qname,
                    temp1->reg->qname);
        cb_add_back(cb, indent + CB_TAB, "jz %s\n", end_label);
        cb_add_back(cb, indent + CB_TAB, "mov %s, qword [%s + %s]\n",
                    temp2->reg->qname, util_format_memory_address2(from, -8),
                    temp1->reg->qname);
        cb_add_back(cb, indent + CB_TAB, "mov qword [%s + %s], %s\n",
                    util_format_memory_address2(to, -8), temp1->reg->qname,
                    temp2->reg->qname);
        cb_add_back(cb, indent + CB_TAB, "sub %s, 8\n", temp1->reg->qname);
        cb_add_back(cb, indent + CB_TAB, "jmp %s\n", loop_label);
        cb_add_back(cb, indent, "%s:\n", end_label);

        from.offset += len - len % 8;
        to.offset += len - len % 8;
        len %= 8;
    }

    for (size_t i = 0; i + 8 <= len; i += 8) {
        if (temp2 == NULL)
            temp2 = gpr_pool_borrow(frag, pool);
        cb_add_back(cb, indent, "mov %s, qword [%s]\n", temp2->reg->qname,
                    util_format_memory_address2(from, i));
        cb_add_back(cb, indent, "mov qword [%s], %s\n",
                    util_format_memory_address2(to, i), temp2->reg->qname);
    }

    from.offset += len - len % 8;
    to.offset += len - len % 8;
    len %= 8;

    if (len == 0) {
        return 0;
    }

    if (len >= 4) {
        if (temp2 == NULL)
            temp2 = gpr_pool_borrow(frag, pool);
        cb_add_back(cb, indent, "mov %s, dword [%s]\n", temp2->reg->dname,
                    util_format_memory_address(from));
        cb_add_back(cb, indent, "mov dword [%s], %s\n",
                    util_format_memory_address(to), temp2->reg->dname);
        from.offset += 4;
        to.offset += 4;
        len -= 4;
    }

    if (len >= 2) {
        if (temp2 == NULL)
            temp2 = gpr_pool_borrow(frag, pool);
        cb_add_back(cb, indent, "mov %s, word [%s]\n", temp2->reg->wname,
                    util_format_memory_address(from));
        cb_add_back(cb, indent, "mov word [%s], %s\n",
                    util_format_memory_address(to), temp2->reg->wname);
        from.offset += 2;
        to.offset += 2;
        len -= 2;
    }

    if (len >= 1) {
        if (temp2 == NULL)
            temp2 = gpr_pool_borrow(frag, pool);
        cb_add_back(cb, indent, "mov %s, byte [%s]\n", temp2->reg->bname,
                    util_format_memory_address(from));
        cb_add_back(cb, indent, "mov byte [%s], %s\n",
                    util_format_memory_address(to), temp2->reg->bname);
        len -= 1;
    }

    gpr_pool_release(temp1);
    gpr_pool_release(temp2);

    return 0;
#undef THRESHOLD
}

