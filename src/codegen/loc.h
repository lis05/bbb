#pragma once

#include "../common/common.h"
#include "regs.h"

enum location_type {
    LOC_GPR_REGISTER = 0,
    LOC_SSE_REGISTER,
    LOC_SYMBOL_OFFSET,
    LOC_STACK_OFFSET,
    LOC_SCALED,
    LOC_INT_LITERAL,
    LOC_UINT_LITERAL,
    LOC_DOUBLE_LITERAL
};

struct location_t {
    enum location_type type;
    union {
        gpr_reg_t gpr_reg;

        sse_reg_t sse_reg;

        struct {
            const char *symbol;
            int64_t     offset;
        } symbol;

        // offset from rbp: rbp + stack_offset
        int64_t stack_offset;

        struct {
            gpr_reg_t base;
            gpr_reg_t index;
            uint8_t   scale;
            int64_t   offset;
        } scaled;

        int64_t int_literal;

        uint64_t uint_literal;

        double double_literal;
    };
};

void loc_init_gpr(struct location_t *loc, gpr_reg_t gpr_reg);
void loc_init_sse(struct location_t *loc, sse_reg_t sse_reg);
void loc_init_symbol(struct location_t *loc, const char *symbol, int64_t offset);
void loc_init_stack(struct location_t *loc, int64_t offset);
void loc_init_scaled(struct location_t *loc, gpr_reg_t base, gpr_reg_t index,
                     uint8_t scale, int64_t offset);
void loc_init_int(struct location_t *loc, int64_t lit);
void loc_init_uint(struct location_t *loc, uint64_t lit);
void loc_init_double(struct location_t *loc, double lit);



