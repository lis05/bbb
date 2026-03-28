#pragma once

#include "cb.h"
#include "loc.h"
#include "regs.h"

/*
 * This file contains small functions which generate instructions for specific
 * usecases.
 */

/* Moves data from a GPR register into memory. May overwrite temp. */
int instr_move_gpr_into_mem(cb_t *cb, int indent, gpr_reg_t reg, size_t len,
                            int64_t stack_offset, gpr_reg_t temp);

/* Moves data from an SSE register into memory. May overwrite temp1 and temp2. */
int instr_move_sse_into_mem(cb_t *cb, int indent, sse_reg_t reg, size_t len,
                            int64_t stack_offset, gpr_reg_t temp1, gpr_reg_t temp2);
