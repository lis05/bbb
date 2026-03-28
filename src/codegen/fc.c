#include "fc.h"

void fc_init(struct function_context_t *fc) {
    fc->return_value = (struct location_t){0};
    scope_init(&fc->local_scope);
    gpr_pool_init(&fc->gpr_pool);
    sse_pool_init(&fc->sse_pool);
}
