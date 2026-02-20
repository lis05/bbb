#include "loc.h"

void loc_init_gpr(struct location_t *loc, gpr_reg_t gpr_reg) {
    loc->gpr_reg = gpr_reg;
}

void loc_init_sse(struct location_t *loc, sse_reg_t sse_reg) {
    loc->sse_reg = sse_reg;
}

void loc_init_symbol(struct location_t *loc, const char *symbol, int64_t offset) {
    loc->symbol.symbol = symbol;
    loc->symbol.offset = offset;
}

void loc_init_stack(struct location_t *loc, int64_t offset) {
    loc->stack_offset = offset;
}

void loc_init_scaled(struct location_t *loc, gpr_reg_t base, gpr_reg_t index,
                     uint8_t scale, int64_t offset) {
    loc->scaled.base = base;
    loc->scaled.index = index;
    loc->scaled.scale = scale;
    loc->scaled.offset = offset;
}

void loc_init_int(struct location_t *loc, int64_t lit) {
    loc->int_literal = lit;
}

void loc_init_uint(struct location_t *loc, uint64_t lit) {
    loc->uint_literal = lit;
}

void loc_init_double(struct location_t *loc, double lit) {
    loc->double_literal = lit;
}
