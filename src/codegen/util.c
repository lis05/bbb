#include "util.h"

#include "../parser/error.h"
#include "kw.h"
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

static int STATUSCODE get_mem_len(const tfrag_t *NONULL frag, const char *NONULL str,
                                  size_t *NONULL res) MEMSAFE {
    log_assert(str != NULL);
    log_assert(res != NULL);

    pstr_t       t = NULL;
    char *NOFREE ptr;
    size_t       num;

    if (strstr(str, "m(sizeof ") == str && str[strlen(str) - 1] == ')') {
        char *tmp = strdup_safe(str + strlen("m(sizeof "));
        *strchr(tmp, ')') = '\0';
        t = pstr_take(tmp);

        if (!layouts_has(t)) {
            context_msg(
                frag,
                "Error: the layout referenced here has not been declared yet.\n");
            return -1;
        }

        if (res != NULL) {
            *res = layouts_find(t).total_size;
        }

        return 0;
    } else if (str[0] == 'm') {
        t = pstr_take(strdup_safe(str + 1));
    } else {
        goto error;
    }

    num = strtoull(t, &ptr, 0);
    if (*ptr != '\0') {
        goto error;
    }

    if (res != NULL) {
        *res = num;
    }

    return 0;

error:
    context_msg(frag, "Error: invalid memory length specifier.\n");
    return 1;
}

int util_get_mem_len(const struct name_node_t *node, size_t *res) {
    log_assert(node != NULL);
    return get_mem_len(&node->frag, node->name, res);
}

int util_get_align(const struct name_node_t *node, size_t *res) {
    log_assert(node != NULL);

    const char *str = NULL;
    char       *ptr;
    size_t      num;

    if (strstr(node->name, "align") == node->name) {
        str = pstr_take(strdup_safe(node->name + 5));
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

        is_int = strcmp(node->chunk1->name, KW_CHUNK_INT);
        is_sse = strcmp(node->chunk1->name, KW_CHUNK_SSE);
        is_mem = strcmp(node->chunk1->name, KW_CHUNK_MEM);

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

        is_int = strcmp(node->chunk2->name, KW_CHUNK_INT);
        is_sse = strcmp(node->chunk2->name, KW_CHUNK_SSE);
        is_mem = strcmp(node->chunk2->name, KW_CHUNK_MEM);

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

    int is_int = strcmp(node->name, KW_CHUNK_INT);
    int is_sse = strcmp(node->name, KW_CHUNK_SSE);
    int is_mem = strcmp(node->name, KW_CHUNK_MEM);

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

int64_t util_align_stack_down(int64_t offset, size_t alignment) {
    return -util_align_up(-offset, alignment);
}

ONETIME const char *fmt_stack_offset(int64_t offset) {
#define N 128
    static char buf[N];

    if (offset > 0) {
        snprintf(buf, N, "rbp + %zu", (size_t)offset);
    } else if (offset < 0) {
        snprintf(buf, N, "rbp - %zu", (size_t)(-offset));
    } else {
        snprintf(buf, N, "rbp");
    }

    return buf;
#undef N
}

int STATUSCODE util_parse_operator(const struct name_node_t *NONULL node,
                                   size_t *YESNULL                  left_size,
                                   pstr_t *YESNULL                  left_type,
                                   size_t *YESNULL                  right_size,
                                   pstr_t *YESNULL                  right_type,
                                   char *MUSTFREE *YESNULL          operator) {
    log_assert(node != NULL);

    int r = 0;

    char *MUSTFREE left = NULL;
    char *MUSTFREE op = NULL;
    char *MUSTFREE right = NULL;

    // we will find the operator in the middle of node->name
    const char *const ops[] = {
        "||", "&&", "++", "--", "+", "-", "*",  "/",  "%", "&", "|",
        "^",  "~",  "<=", ">=", "<", ">", "==", "!=", "!", "=", "?",
    };

    for (size_t i = 0; i < sizeof(ops) / sizeof(const char *); i++) {
        char *mid = strstr(node->name, ops[i]);
        if (mid == NULL) {
            continue;
        }

        left = memdup_safe(node->name, mid - node->name + 1);
        left[mid - node->name] = '\0';

        op = memdup_safe(mid, strlen(ops[i]) + 1);
        op[strlen(ops[i])] = '\0';

        right = strdup_safe(mid + strlen(ops[i]));
        break;
    }

    if (op == NULL) {
        context_msg(&node->frag, "Error: invalid operator.\n");
        return -1;
    }

    if (operator != NULL) {
        *operator = op;
    }

    const char *const types[] = {
        "b", "sb", "w", "sw", "d", "sd", "q", "sq", "f", "F",
    };

    const size_t sizes[] = {
        1, 1, 2, 2, 4, 4, 8, 8, 4, 8,
    };

    log_assert(sizeof(types) / sizeof(const char *) ==
               sizeof(sizes) / sizeof(size_t));

    int BOOL f = 0;
    if (strcmp(left, "") == 0) {
        if (left_type != NULL) {
            *left_type = pstr_copy("q");
        }
        if (left_size != NULL) {
            *left_size = 8;
        }
    } else {
        for (size_t i = 0; i < sizeof(types) / sizeof(const char *); i++) {
            if (strcmp(left, types[i]) == 0) {
                if (left_type != NULL) {
                    *left_type = pstr_copy(types[i]);
                }
                if (left_size != NULL) {
                    *left_size = sizes[i];
                }
                f = 1;
                break;
            }
        }

        if (!f) {
            if (left_type != NULL) {
                *left_type = pstr_copy("q");
            }
            if (get_mem_len(&node->frag, left, left_size)) {
                goto error;
            }
        }
    }

    f = 0;
    if (strcmp(right, "") == 0) {
        if (right_type != NULL) {
            *right_type = pstr_copy("q");
        }
        if (right_size != NULL) {
            *right_size = 8;
        }
    } else {
        for (size_t i = 0; i < sizeof(types) / sizeof(const char *); i++) {
            if (strcmp(right, types[i]) == 0) {
                if (right_type != NULL) {
                    *right_type = pstr_copy(types[i]);
                }
                if (right_size != NULL) {
                    *right_size = sizes[i];
                }
                f = 1;
                break;
            }
        }

        if (!f) {
            if (right_type != NULL) {
                *right_type = pstr_copy("q");
            }
            if (get_mem_len(&node->frag, right, right_size)) {
                goto error;
            }
        }
    }

end:
    if (operator == NULL) {
        free(op);
    }
    free(left);
    free(right);

    return r;

error:
    r = 1;
    context_msg(&node->frag, "Error: invalid operator.\n");
    goto end;
}
