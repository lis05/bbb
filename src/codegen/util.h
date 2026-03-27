#pragma once

#include "../common/common.h"
#include "../parser/ast.h"

// these were written from a polish ZUS
const char *util_get_visibility(const struct name_node_t *node);
int         util_get_mem_len(const struct name_node_t *node, size_t *res);
int         util_get_align(const struct name_node_t *node, size_t *res);
// returns 0 if INT/SSE/MEM, 1 if layout, -1 if error
int util_get_abi_class(const struct abi_class_node_t *node, int *chunk1, int *chunk2,
                       const char **layout);
int util_get_chunk(const struct name_node_t *node, int *chunk);
uint64_t util_align_up(uint64_t value, uint64_t alignment);

