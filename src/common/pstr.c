#include "common.h"

static YESNULL MUSTFREE char **strings;
static size_t                  len, cap;

void pstr_init() MEMSAFE {
    len = 0;
    cap = 512;
    strings = (char **)calloc_safe(cap, sizeof(char *));
}
void pstr_destroy() MEMSAFE {
    for (size_t i = 0; i < len; i++) {
        if (strings[i] != NULL) {
            free(strings[i]);
        }
    }
    len = cap = 0;
}

pstr_t NONULL pstr_take(char *str NONULL SINK) MEMSAFE {
    log_assert(str != NULL);
    pstr_t res = pstr_copy(str);
    free(str);
    return res;
}

pstr_t NONULL pstr_copy(const char *str NONULL) MEMSAFE {
    if (strings == NULL) {
        pstr_init();
    }
    log_assert(str != NULL);

    for (size_t i = 0; i < len; i++) {
        if (strcmp(str, strings[i]) == 0) {
            return strings[i];
        }
    }

    if (len == cap) {
        cap *= 2;
        strings = realloc_safe(strings, cap * sizeof(char *));
    }

    strings[len] = strdup_safe(str);
    return (pstr_t)strings[len++];
}

