#pragma once

#include "loc.h"
#include "regs.h"
#include "scope.h"
#include "lblg.h"

struct function_context_t {
    int64_t stack_offset;
    FINAL const char *return_point_label;
    FINAL struct location_t return_value;
    FINAL struct scope_t local_scope;
    FINAL struct label_generator_t lblg;
    struct gpr_pool_t gpr_pool;
    struct sse_pool_t sse_pool;
};

void fc_init(NONULL struct function_context_t *fc);
