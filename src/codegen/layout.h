#pragma once

#include "../common/common.h"

struct layout_t {
    size_t n;
    const char **fields;
    size_t *offsets;
    size_t total_size;
    uint8_t chunk1;
    uint8_t chunk2;
};

void layouts_register(const char *name, struct layout_t layout);
int layouts_has(const char *name);
struct layout_t layouts_find(const char *name);

int layout_has_field(const struct layout_t *layout, const char *name);
size_t layout_get_offset(const struct layout_t *layout, const char *name);


