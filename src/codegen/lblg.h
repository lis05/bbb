#pragma once

#include "../common/common.h"

struct label_generator_t {
    size_t n, cap;
    char **labels;
};

void lblg_init(struct label_generator_t *lblg);
void lblg_destroy(struct label_generator_t *lblg);
const char *lblg_gen(struct label_generator_t *lblg);
const char *lblg_gen_double_lit();
const char *lblg_gen_string_lit();
