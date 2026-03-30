#pragma once

#include "../common/common.h"
#include "loc.h"

// locations should be relatively small, so we keep them by value
struct scope_t {
    size_t size, cap;
    const char **names;
    struct location_t *locs;
};

void scope_init(struct scope_t *scope);
void scope_add(struct scope_t *scope, const char *token, struct location_t loc);
int scope_has(struct scope_t *scope, const char *token);
void scope_remove(struct scope_t *scope, const char *token);
struct location_t scope_get(struct scope_t *scope, const char *token);
void scope_update(struct scope_t *scope, const char *token, struct location_t loc);
void scope_destroy(struct scope_t *scope); // does NOT free scope
