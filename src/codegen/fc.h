#pragma once

#include "loc.h"
#include "regs.h"
#include "scope.h"
#include "lblg.h"

struct function_context_t {
    int64_t stack_offset;
    const char *return_point_label;
    struct location_t return_value;
    struct scope_t local_scope;
    struct label_generator_t lblg;
    struct gpr_pool_t gpr_pool;
    struct sse_pool_t sse_pool;
};

void fc_init(struct function_context_t *fc NONULL) MEMSAFE;
