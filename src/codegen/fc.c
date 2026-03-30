#include "fc.h"

void fc_init(NONULL struct function_context_t *fc) {
    fc->stack_offset = 0;
    fc->return_value = (struct location_t){0};
    scope_init(&fc->local_scope);
    lblg_init(&fc->lblg);
    fc->return_point_label = lblg_gen(&fc->lblg);
    gpr_pool_init(&fc->gpr_pool);
    sse_pool_init(&fc->sse_pool);
}
