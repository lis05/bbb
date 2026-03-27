#include "util.h"

#include "../parser/error.h"
#include "layout.h"
#include "vmap.h"

const char *util_get_visibility(const struct name_node_t *node) {
    log_assert(node != NULL);

    if (strcmp(node->name, "global") == 0) {
        return "global";
    }

    context_msg(&node->frag,
                "Error: invalid visibility (the only valid one is 'global')\n");
    return NULL;
}

int util_get_mem_len(const struct name_node_t *node, size_t *res) {
    log_assert(node != NULL);

    char  *str = NULL;
    char  *ptr;
    size_t num;

    if (strstr(node->name, "m(sizeof ") == node->name &&
        node->name[strlen(node->name) - 1] == ')') {
        str = strdup(node->name + strlen("m(sizeof "));
        *strchr(str, ')') = '\0';

        if (!layouts_has(str)) {
            free(str);
            context_msg(
                &node->frag,
                "Error: the layout referenced here has not been declared yet.\n");
            return -1;
        }

        if (res != NULL) {
            *res = layouts_find(str).total_size;
        }

        free(str);
        return 0;
    } else if (node->name[0] == 'm') {
        str = strdup(node->name + 1);
    } else {
        goto error;
    }

    num = strtoull(str, &ptr, 0);
    if (*ptr != '\0') {
        goto error;
    }

    if (res != NULL) {
        *res = num;
    }

    return 0;

error:
    free(str);
    context_msg(&node->frag, "Error: invalid memory length specifier.\n");
    return 1;
}

int util_get_align(const struct name_node_t *node, size_t *res) {
    log_assert(node != NULL);

    char  *str = NULL;
    char  *ptr;
    size_t num;

    if (strstr(node->name, "align") == node->name) {
        str = strdup(node->name + 5);
    } else {
        goto error;
    }

    num = strtoull(str, &ptr, 0);
    if (*ptr != '\0') {
        goto error;
    }

    if (__builtin_popcount(num) != 1 || num > 16) {
        context_msg(&node->frag,
                    "Error: alignment can be either 1, 2, 4, 8, or 16.\n");
        return -1;
    }

    if (res != NULL) {
        *res = num;
    }

    return 0;

error:
    free(str);
    context_msg(&node->frag, "Error: invalid alignment specifier.\n");
    return -1;
}

int util_get_abi_class(const struct abi_class_node_t *node, int *chunk1, int *chunk2,
                       const char **layout) {
    log_assert(node != NULL);

    int res = -1;
    int is_int, is_sse, is_mem;

    if (node->chunk1 != NULL) {
        if (res == 1) {
            goto error;
        }
        res = 0;

        is_int = strcmp(node->chunk1->name, "#int");
        is_sse = strcmp(node->chunk1->name, "#sse");
        is_mem = strcmp(node->chunk1->name, "#mem");

        if (is_int && is_sse && is_mem) {
            goto error;
        }

        if (chunk1 != NULL) {
            if (is_int == 0) {
                *chunk1 = VMAP_CHUNK_INT;
            } else if (is_sse == 0) {
                *chunk1 = VMAP_CHUNK_SSE;
            } else if (is_mem == 0) {
                *chunk1 = VMAP_CHUNK_MEM;
            }
        }
    } else if (chunk1 != NULL) {
        *chunk1 = VMAP_CHUNK_NONE;
    }

    if (node->chunk2 != NULL) {
        if (res == 1) {
            goto error;
        }
        res = 0;

        is_int = strcmp(node->chunk2->name, "#int");
        is_sse = strcmp(node->chunk2->name, "#sse");
        is_mem = strcmp(node->chunk2->name, "#mem");

        if (is_int && is_sse && is_mem) {
            goto error;
        }

        if (chunk2 != NULL) {
            if (is_int == 0) {
                *chunk2 = VMAP_CHUNK_INT;
            } else if (is_sse == 0) {
                *chunk2 = VMAP_CHUNK_SSE;
            } else if (is_mem == 0) {
                *chunk2 = VMAP_CHUNK_MEM;
            }
        }
    } else if (chunk2 != NULL) {
        *chunk2 = VMAP_CHUNK_NONE;
    }

    if (node->layout != NULL) {
        if (res == 0) {
            goto error;
        }
        res = 1;

        if (layout != NULL) {
            *layout = node->layout->name + 1;
        }
    } else if (layout != NULL) {
        *layout = NULL;
    }

    return res;

error:
    context_msg(&node->frag, "Error: invalid abi classification.\n");
    return -1;
}

int util_get_chunk(const struct name_node_t *node, int *chunk) {
    log_assert(node != NULL);

    int is_int = strcmp(node->name, "#int");
    int is_sse = strcmp(node->name, "#sse");
    int is_mem = strcmp(node->name, "#mem");

    if (is_int && is_sse && is_mem) {
        context_msg(&node->frag, "Error: invalid chunk classification.\n");
        return -1;
    }

    if (chunk != NULL) {
        if (is_int == 0) {
            *chunk = VMAP_CHUNK_INT;
        } else if (is_sse == 0) {
            *chunk = VMAP_CHUNK_SSE;
        } else if (is_mem == 0) {
            *chunk = VMAP_CHUNK_MEM;
        }
    }
    return 0;
}

uint64_t util_align_up(uint64_t value, uint64_t alignment) {
    return (value + alignment - 1) & ~(alignment - 1);
}
