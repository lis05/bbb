#include "loc.h"

void loc_init_gpr(struct location_t *loc, size_t mem_len, gpr_reg_t gpr_reg) {
    loc->type = LOC_GPR_REGISTER;
    loc->mem_len = mem_len;

    loc->gpr_reg = gpr_reg;
}

void loc_init_sse(struct location_t *loc, size_t mem_len, sse_reg_t sse_reg) {
    loc->type = LOC_SSE_REGISTER;
    loc->mem_len = mem_len;

    loc->sse_reg = sse_reg;
}

void loc_init_symbol(struct location_t *loc, size_t mem_len, const char *symbol, int64_t offset) {
    loc->type = LOC_SYMBOL_OFFSET;
    loc->mem_len = mem_len;

    loc->symbol.symbol = symbol;
    loc->symbol.offset = offset;
}

void loc_init_stack(struct location_t *loc, size_t mem_len, int64_t offset) {
    loc->type = LOC_STACK_OFFSET;
    loc->mem_len = mem_len;

    loc->stack_offset = offset;
}

void loc_init_scaled(struct location_t *loc, size_t mem_len, gpr_reg_t base, gpr_reg_t index,
                     uint8_t scale, int64_t offset) {
    loc->type = LOC_SCALED;
    loc->mem_len = mem_len;

    loc->scaled.base = base;
    loc->scaled.index = index;
    loc->scaled.scale = scale;
    loc->scaled.offset = offset;
}

void loc_init_int(struct location_t *loc, size_t mem_len, int64_t lit) {
    loc->type = LOC_INT_LITERAL;
    loc->mem_len = mem_len;

    loc->int_literal = lit;
}

void loc_init_uint(struct location_t *loc, size_t mem_len, uint64_t lit) {
    loc->type = LOC_UINT_LITERAL;
    loc->mem_len = mem_len;

    loc->uint_literal = lit;
}

void loc_init_double(struct location_t *loc, size_t mem_len, double lit) {
    loc->type = LOC_DOUBLE_LITERAL;
    loc->mem_len = mem_len;

    loc->double_literal = lit;
}
