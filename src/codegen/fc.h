#pragma once

#include "loc.h"
#include "regs.h"
#include "scope.h"
#include "lblg.h"

struct function_context_t {
    // this will never change
    struct location_t return_value;
    // this will never change either
    struct scope_t local_scope; // includes function arguments
    // this will also never change
    struct label_generator_t lblg;
    // these two will change
    struct gpr_pool_t gpr_pool;
    struct sse_pool_t sse_pool;
};

void fc_init(struct function_context_t *fc);
