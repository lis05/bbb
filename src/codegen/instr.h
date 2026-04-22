#pragma once

#include "cb.h"
#include "lblg.h"
#include "loc.h"
#include "regs.h"
#include "util.h"

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
//////////// ASSIGNMENT
/// (int, uint) -> (gpr, mem)
/// (gpr, see, mem) -> (gpr, see, mem)
/// total: 4+9=13
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
int STATUSCODE instr_move_int_into_gpr(cb_t *cb, int indent, int64_t lit, size_t len,
                                       gpr_reg_t to, const tfrag_t *frag);
int STATUSCODE instr_move_int_into_mem(cb_t *cb, int indent, int64_t lit, size_t len,
                                       struct util_memory_address_t addr,
                                       const tfrag_t               *frag);
int STATUSCODE instr_move_uint_into_gpr(cb_t *cb, int indent, uint64_t lit,
                                        size_t len, gpr_reg_t to,
                                        const tfrag_t *frag);
int STATUSCODE instr_move_uint_into_mem(cb_t *cb, int indent, uint64_t lit,
                                        size_t len, struct util_memory_address_t to,
                                        const tfrag_t *frag);
int STATUSCODE instr_move_gpr_into_gpr(cb_t *cb, int indent, gpr_reg_t from,
                                       gpr_reg_t to, size_t len,
                                       const tfrag_t *frag);
int STATUSCODE instr_move_gpr_into_sse(cb_t *cb, int indent, gpr_reg_t from,
                                       sse_reg_t to, size_t len,
                                       const tfrag_t *frag);
int STATUSCODE instr_move_gpr_into_mem(cb_t *cb, int indent, gpr_reg_t from,
                                       size_t len, struct util_memory_address_t to,
                                       const tfrag_t *frag);
int STATUSCODE instr_move_sse_into_gpr(cb_t *cb, int indent, sse_reg_t from,
                                       size_t len, gpr_reg_t to,
                                       const tfrag_t *frag);
int STATUSCODE instr_move_sse_into_sse(cb_t *cb, int indent, sse_reg_t from,
                                       size_t len, sse_reg_t to,
                                       const tfrag_t *frag);
int STATUSCODE instr_move_sse_into_mem(cb_t *cb, int indent, sse_reg_t from,
                                       size_t len, struct util_memory_address_t to,
                                       const tfrag_t *frag);
int STATUSCODE instr_move_mem_into_gpr(cb_t *cb, int indent,
                                       struct util_memory_address_t from, size_t len,
                                       gpr_reg_t to, const tfrag_t *frag);
int STATUSCODE instr_move_mem_into_sse(cb_t *cb, int indent,
                                       struct util_memory_address_t from, size_t len,
                                       sse_reg_t to, const tfrag_t *frag);
int STATUSCODE instr_move_mem_into_mem(cb_t *cb, int indent,
                                       struct util_memory_address_t from, size_t len,
                                       struct util_memory_address_t to,
                                       struct label_generator_t    *lblg,
                                       struct gpr_pool_t *pool, const tfrag_t *frag);
