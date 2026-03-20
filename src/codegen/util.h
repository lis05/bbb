#pragma once

#include "../common/common.h"
#include "../parser/ast.h"

// these were written from a polish ZUS
const char *util_get_visibility(const struct name_node_t *node);
int util_get_mem_len(const struct name_node_t *node, size_t *res);
int util_get_align(const struct name_node_t *node, size_t *res);

