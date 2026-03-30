#include "scope.h"

void scope_init(struct scope_t *scope) {
    log_assert(scope != NULL);
    scope->size = 0;
    scope->cap = 1;
    scope->names = (const char **)malloc(sizeof(const char *));
    log_assert(scope->names != NULL);
    scope->locs = (struct location_t *)malloc(sizeof(struct location_t));
    log_assert(scope->locs != NULL);
}

void scope_add(struct scope_t *scope, const char *token, struct location_t loc) {
    log_assert(scope != NULL);
    if (scope->size == scope->cap) {
        scope->cap *= 2;
        scope->names = realloc(scope->names, sizeof(const char *) * scope->cap);
        log_assert(scope->names != NULL);
        scope->locs = realloc(scope->locs, sizeof(struct location_t) * scope->cap);
        log_assert(scope->locs != NULL);
    }

    scope->names[scope->size] = token;
    scope->locs[scope->size++] = loc;
}

void scope_remove(struct scope_t *scope, const char *token) {
    size_t p = 0;
    for (size_t i = 0; i < scope->size; i++) {
        if (strcmp(scope->names[i], token) == 0) {
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
        scope->names = realloc(scope->names, sizeof(const char *) * scope->cap);
        log_assert(scope->names != NULL);
        scope->locs = realloc(scope->locs, sizeof(struct location_t) * scope->cap);
        log_assert(scope->locs != NULL);
    }
}

int scope_has(struct scope_t *scope, const char *token) {
    log_assert(scope != NULL);
    for (size_t i = 0; i < scope->size; i++) {
        if (strcmp(token, scope->names[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

struct location_t scope_get(struct scope_t *scope, const char *token) {
    log_assert(scope != NULL);
    for (size_t i = 0; i < scope->size; i++) {
        if (strcmp(token, scope->names[i]) == 0) {
            return scope->locs[i];
        }
    }

    return (struct location_t){0};  // ur cooked
}

void scope_update(struct scope_t *scope, const char *token, struct location_t loc) {
    log_assert(scope != NULL);
    for (size_t i = 0; i < scope->size; i++) {
        if (strcmp(token, scope->names[i]) == 0) {
            scope->locs[i] = loc;
            return;
        }
    }
}

void scope_destroy(struct scope_t *scope) {
    log_assert(scope != NULL);
    free(scope->names);
    free(scope->locs);
}

