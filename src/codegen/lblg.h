#pragma once

#include "../common/common.h"

struct label_generator_t {
    size_t                               n, cap;
    char *NONULL MUSTFREE *labels NONULL MUSTFREE;
};

void lblg_init(struct label_generator_t *lblg NONULL) MEMSAFE;
void lblg_destroy(struct label_generator_t *lblg NONULL) MEMSAFE;
const char *NONULL NOFREE lblg_gen(struct label_generator_t *lblg NONULL) MEMSAFE;
const char *NONULL NOFREE lblg_gen_double_lit() MEMSAFE;
const char *NONULL NOFREE lblg_gen_string_lit() MEMSAFE;
