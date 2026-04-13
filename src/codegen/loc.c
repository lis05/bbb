#include "loc.h"

#include "../parser/error.h"
#include "cb.h"
#include "instr.h"

cb_t loc_args_copy(int indent, struct location_t *from, struct location_t *to,
                   struct label_generator_t *lblg, struct gpr_pool_t *pool,
                   const tfrag_t *frag) {
    cb_t res;
    cb_init(&res);

    if (to->type != LOC_STACK && to->type != LOC_PTR_ON_STACK) {
        goto error;
    }

    /* If moving from a register, we can do that in one instruction. Otherwise,
     * we do it using two.*/

    switch (from->type) {
    case LOC_GPR:
        if (instr_move_gpr_into_mem(&res, indent, from->gpr_reg1, from->true_len,
                                    to->stack_offset, pool, frag))
            goto error;
        break;
    case LOC_SSE:
        if (instr_move_sse_into_mem(&res, indent, from->sse_reg1, from->true_len,
                                    to->stack_offset, pool, frag))
            goto error;
        break;
    case LOC_GPR_GPR:
        if (instr_move_gpr_into_mem(&res, indent, from->gpr_reg1, 8,
                                    to->stack_offset, pool, frag))
            goto error;
        if (instr_move_gpr_into_mem(&res, indent, from->gpr_reg2, from->true_len - 8,
                                    to->stack_offset + 8, pool, frag))
            goto error;
        break;
    case LOC_GPR_SSE:
        if (instr_move_gpr_into_mem(&res, indent, from->gpr_reg1, 8,
                                    to->stack_offset, pool, frag))
            goto error;
        if (instr_move_sse_into_mem(&res, indent, from->sse_reg2, from->true_len - 8,
                                    to->stack_offset + 8, pool, frag))
            goto error;
        break;
    case LOC_SSE_GPR:
        if (instr_move_sse_into_mem(&res, indent, from->sse_reg1, 8,
                                    to->stack_offset, pool, frag))
            goto error;
        if (instr_move_gpr_into_mem(&res, indent, from->gpr_reg2, from->true_len - 8,
                                    to->stack_offset + 8, pool, frag))
            goto error;
        break;
    case LOC_SSE_SSE:
        if (instr_move_sse_into_mem(&res, indent, from->sse_reg1, 8,
                                    to->stack_offset, pool, frag))
            goto error;
        if (instr_move_sse_into_mem(&res, indent, from->sse_reg2, from->true_len - 8,
                                    to->stack_offset + 8, pool, frag))
            goto error;
        break;
    case LOC_PTR_IN_GPR:
        if (instr_move_gpr_into_mem(&res, indent, from->gpr_reg1, 8,
                                    to->stack_offset, pool, frag))
            goto error;
        break;
    case LOC_PTR_ON_STACK:
        if (instr_move_mem_into_mem(&res, indent, from->stack_offset, 8,
                                    to->stack_offset, lblg, pool, frag))
            goto error;
        break;
    case LOC_STACK:
        if (instr_move_mem_into_mem(&res, indent, from->stack_offset, from->true_len,
                                    to->stack_offset, lblg, pool, frag))
            goto error;
        break;
    }

end:
    return res;

error:
    cb_destroy(&res);
    return cb_invalid();
}

cb_t loc_move_data(int indent, struct location_t from, struct location_t to,
                   size_t len, struct gpr_pool_t *pool, const tfrag_t *frag) {
    cb_t res = {0};
    cb_init(&res);

    if (from.type == LOC_GPR) {
        if (to.type == LOC_GPR) {
            if (instr_move_gpr_into_gpr(&res, indent, from.gpr_reg1, to.gpr_reg1,
                                        len, frag)) {
                goto error;
            }
            return res;
        } else if (to.type == LOC_STACK) {
            if (instr_move_gpr_into_mem(&res, indent, from.gpr_reg1, len,
                                        to.stack_offset, pool, frag)) {
                goto error;
            }
            return res;
        }
    } else if (from.type == LOC_STACK) {
    } else if (from.type == LOC_INT_LITERAL) {
        if (to.type == LOC_GPR) {
            if (instr_move_int_into_gpr(&res, indent, from.int_literal, len,
                                        to.gpr_reg1, frag)) {
                goto error;
            }
            return res;
        }
    } else if (from.type == LOC_UINT_LITERAL) {
        if (to.type == LOC_GPR) {
            if (instr_move_uint_into_gpr(&res, indent, from.uint_literal, len,
                                         to.gpr_reg1, frag)) {
                goto error;
            }
            return res;
        }
    }

unsupported:
    context_msg(frag, "Error: unsupported move between location types %d and %d\n",
                from.type, to.type);
error:
    cb_destroy(&res);
    return cb_invalid();
}
