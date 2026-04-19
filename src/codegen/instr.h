#pragma once

#include "cb.h"
#include "lblg.h"
#include "loc.h"
#include "regs.h"
#include "util.h"

/*
 * This file contains small functions which generate instructions for specific
 * usecases.
 */

/* Moves data from a GPR register into memory. May overwrite temp. */
int STATUSCODE instr_move_gpr_into_mem(cb_t *cb, int indent, gpr_reg_t reg,
                                       size_t len, struct util_memory_address_t addr,
                                       struct gpr_pool_t *pool, const tfrag_t *frag);

/* Moves data from a GPR register into a GPR register. */
int STATUSCODE instr_move_gpr_into_gpr(cb_t *cb, int indent, gpr_reg_t from,
                                       gpr_reg_t to, size_t len,
                                       const tfrag_t *frag);

/* Moves data from an SSE register into memory. May overwrite temp1 and temp2. */
int STATUSCODE instr_move_sse_into_mem(cb_t *cb, int indent, sse_reg_t reg,
                                       size_t len, struct util_memory_address_t addr,
                                       struct gpr_pool_t *pool, const tfrag_t *frag);

/* Moves data from memory into memory. May overwrite temp1 and temp2. */
int STATUSCODE instr_move_mem_into_mem(cb_t *cb, int indent,
                                       struct util_memory_address_t from, size_t len,
                                       struct util_memory_address_t to,
                                       struct label_generator_t    *lblg,
                                       struct gpr_pool_t *pool, const tfrag_t *frag);

/* Moves a signed integer into a GPR register. */
int STATUSCODE instr_move_int_into_gpr(cb_t *cb, int indent, int64_t lit, size_t len,
                                       gpr_reg_t reg, const tfrag_t *frag);

/* Moves an unsigned integer into a GPR register. */
int STATUSCODE instr_move_uint_into_gpr(cb_t *cb, int indent, uint64_t lit,
                                        size_t len, gpr_reg_t reg,
                                        const tfrag_t *frag);
