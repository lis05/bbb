#include "scope.h"

void scope_init(struct scope_t *scope NONULL) MEMSAFE {
    log_assert(scope != NULL);
    scope->size = 0;
    scope->cap = 1;
    scope->names = calloc_safe(1, sizeof(pstr_t *));
    scope->locs = calloc_safe(1, sizeof(struct location_t));
}

void scope_add(struct scope_t *scope NONULL, pstr_t token NONULL,
               struct location_t loc) MEMSAFE {
    log_assert(scope != NULL);
    log_assert(token != NULL);
    if (scope->size == scope->cap) {
        scope->cap *= 2;
        scope->names = realloc_safe(scope->names, sizeof(pstr_t) * scope->cap);
        scope->locs =
            realloc_safe(scope->locs, sizeof(struct location_t) * scope->cap);
    }

    scope->names[scope->size] = token;
    scope->locs[scope->size++] = loc;
}

void scope_remove(struct scope_t *scope NONULL, pstr_t token NONULL) MEMSAFE {
    log_assert(scope != NULL);
    log_assert(token != NULL);
    size_t p = 0;
    for (size_t i = 0; i < scope->size; i++) {
        if (token == scope->names[i]) {
            continue;
        }
        if (i == p) {
            continue;
        }
        scope->names[p] = scope->names[i];
        scope->locs[p++] = scope->locs[i];
    }

    int f = 0;
    while (p * 4 < scope->cap) {
        scope->cap /= 2;
        f = 1;
    }

    if (f) {
        scope->names = realloc_safe(scope->names, sizeof(pstr_t *) * scope->cap);
        scope->locs =
            realloc_safe(scope->locs, sizeof(struct location_t) * scope->cap);
    }
}

int BOOL scope_has(struct scope_t *scope NONULL, pstr_t token NONULL) MEMSAFE {
    log_assert(scope != NULL);
    log_assert(token != NULL);
    for (size_t i = 0; i < scope->size; i++) {
        if (token == scope->names[i]) {
            return 1;
        }
    }

    return 0;
}

struct location_t scope_get(struct scope_t *scope NONULL,
                            pstr_t token          NONULL) MEMSAFE {
    log_assert(scope != NULL);
    log_assert(token != NULL);
    for (size_t i = 0; i < scope->size; i++) {
        if (token == scope->names[i]) {
            return scope->locs[i];
        }
    }

    return (struct location_t){0};  // ur cooked. fried
}

void scope_update(struct scope_t *scope NONULL, pstr_t token NONULL,
                  struct location_t loc) MEMSAFE {
    log_assert(scope != NULL);
    log_assert(token != NULL);
    for (size_t i = 0; i < scope->size; i++) {
        if (token == scope->names[i]) {
            scope->locs[i] = loc;
            return;
        }
    }
}

void scope_destroy(struct scope_t *scope NONULL) MEMSAFE {
    log_assert(scope != NULL);
    free(scope->names);
    free(scope->locs);
}

