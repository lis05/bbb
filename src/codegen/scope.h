#pragma once

#include "../common/common.h"
#include "loc.h"

struct scope_t {
    size_t                         size, cap;
    pstr_t NONULL *names NONULL    MUSTFREE;
    struct location_t *locs NONULL MUSTFREE;
};

void     scope_init(struct scope_t *scope NONULL) MEMSAFE;
void     scope_add(struct scope_t *scope NONULL, pstr_t token NONULL,
                   struct location_t loc) MEMSAFE;
int BOOL scope_has(struct scope_t *scope NONULL, pstr_t token NONULL) MEMSAFE;
void     scope_remove(struct scope_t *scope NONULL, pstr_t token NONULL) MEMSAFE;
struct location_t scope_get(struct scope_t *scope NONULL,
                            pstr_t token          NONULL) MEMSAFE;
void              scope_update(struct scope_t *scope NONULL, pstr_t token NONULL,
                               struct location_t loc) MEMSAFE;
void              scope_destroy(struct scope_t *scope NONULL) MEMSAFE;
