#include "util.h"
#include "../parser/error.h"

const char *util_get_visibility(const struct name_node_t *node) {
    log_assert(node != NULL);

    if (strcmp(node->name, "global") == 0) {
        return "global";
    }

    context_msg(&node->frag, "Error: invalid visibility (the only valid one is 'global')\n");
    return NULL;
}
    
int util_get_mem_len(const struct name_node_t *node, size_t *res) {
    log_assert(node != NULL);

    char *str = NULL;
    char *ptr;
    size_t num;
    
    if (strstr(node->name, "m(") == node->name && node->name[strlen(node->name) - 1] == ')') {
        context_msg(&node->frag, "Error: this is not yet supported, sorry\n");
        return 1;
    }
    else if (node->name[0] == 'm') {
        str = strdup(node->name + 1);
    }
    else {
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

    char *str = NULL;
    char *ptr;
    size_t num;
    
    if (strstr(node->name, "align") == node->name) {
        str = strdup(node->name + 5);
    }
    else {
        goto error;
    }

    num = strtoull(str, &ptr, 0);
    if (*ptr != '\0') {
        goto error;
    }

    if (__builtin_popcount(num) != 1) {
        context_msg(&node->frag, "Error: alignment should be a power of 2.\n");
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

    
        
            

