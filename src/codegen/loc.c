#include "loc.h"

#include "cb.h"
#include "instr.h"

cb_t loc_args_copy(int indent, struct location_t *from, struct location_t *to,
                   struct label_generator_t *lblg) {
    cb_t res;
    cb_init(&res);

    const gpr_reg_t temp1 = r_r10;
    const gpr_reg_t temp2 = r_r11;

    if (to->type != LOC_STACK && to->type != LOC_PTR_ON_STACK) {
        goto error;
    }

    /* If moving from a register, we can do that in one instruction. Otherwise,
     * we do it using two.*/

    switch (from->type) {
    case LOC_GPR:
        if (instr_move_gpr_into_mem(&res, indent, from->gpr_reg1, from->true_len,
                                    to->stack_offset, temp1))
            goto error;
        break;
    case LOC_SSE:
        if (instr_move_sse_into_mem(&res, indent, from->sse_reg1, from->true_len,
                                    to->stack_offset, temp1, temp2))
            goto error;
        break;
    case LOC_GPR_GPR:
        if (instr_move_gpr_into_mem(&res, indent, from->gpr_reg1, 8,
                                    to->stack_offset, temp1))
            goto error;
        if (instr_move_gpr_into_mem(&res, indent, from->gpr_reg2, from->true_len - 8,
                                    to->stack_offset + 8, temp1))
            goto error;
        break;
    case LOC_GPR_SSE:
        if (instr_move_gpr_into_mem(&res, indent, from->gpr_reg1, 8,
                                    to->stack_offset, temp1))
            goto error;
        if (instr_move_sse_into_mem(&res, indent, from->sse_reg2, from->true_len - 8,
                                    to->stack_offset + 8, temp1, temp2))
            goto error;
        break;
    case LOC_SSE_GPR:
        if (instr_move_sse_into_mem(&res, indent, from->sse_reg1, 8,
                                    to->stack_offset, temp1, temp2))
            goto error;
        if (instr_move_gpr_into_mem(&res, indent, from->gpr_reg2, from->true_len - 8,
                                    to->stack_offset + 8, temp1))
            goto error;
        break;
    case LOC_SSE_SSE:
        if (instr_move_sse_into_mem(&res, indent, from->sse_reg1, 8,
                                    to->stack_offset, temp1, temp2))
            goto error;
        if (instr_move_sse_into_mem(&res, indent, from->sse_reg2, from->true_len - 8,
                                    to->stack_offset + 8, temp1, temp2))
            goto error;
        break;
    case LOC_PTR_IN_GPR:
        if (instr_move_gpr_into_mem(&res, indent, from->gpr_reg1, 8,
                                    to->stack_offset, temp1))
            goto error;
        break;
    case LOC_PTR_ON_STACK:
        if (instr_move_mem_into_mem(&res, indent, from->stack_offset, 8,
                                    to->stack_offset, lblg, temp1, temp2))
            goto error;
        break;
    case LOC_STACK:
        if (instr_move_mem_into_mem(&res, indent, from->stack_offset, from->true_len,
                                    to->stack_offset, lblg, temp1, temp2))
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
                   size_t len, gpr_reg_t helper1, gpr_reg_t helper2,
                   size_t *helpers_used) {
    if (helpers_used != 0)
        *helpers_used = 0;
    cb_t res = {0};
    cb_init(&res);

    if (from.type == LOC_GPR && to.type == LOC_GPR) {
        if (instr_move_gpr_into_gpr(&res, indent, from.gpr_reg1, to.gpr_reg1)) {
            goto error;
        }
    }

    return res;

error:
    cb_destroy(&res);
    return cb_invalid();
}
