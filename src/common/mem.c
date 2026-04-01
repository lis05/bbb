#include "mem.h"

#include "common.h"

void *NONULL MUSTFREE calloc_safe(size_t how_many, size_t size_of_one) MEMSAFE {
    void *res = calloc(how_many, size_of_one);
    log_assert(res != NULL);
    return res;
}

void *NONULL MUSTFREE memdup_safe(const void *ptr NONULL, size_t size) MEMSAFE {
    log_assert(ptr != NULL);
    void *res = calloc(1, size);
    log_assert(res != NULL);
    memcpy(res, ptr, size);
    return res;
}

char *NONULL MUSTFREE strdup_safe(const char *str NONULL) MEMSAFE {
    log_assert(str != NULL);
    return (char *)memdup_safe(str, strlen(str) + 1);
}

void *NONULL MUSTFREE realloc_safe(void *ptr NONULL SINK, size_t size) MEMSAFE {
    log_assert(ptr != NULL);
    void *res = realloc(ptr, size);
    log_assert(res != NULL);
    return res;
}

char *NONULL MUSTFREE asprintf_safe(const char *fmt NONULL, ...) MEMSAFE {
    log_assert(fmt != NULL);

    va_list ap;
    char   *res = NULL;

    va_start(ap, fmt);
    int status = vasprintf(&res, fmt, ap);
    va_end(ap);

    log_assert(status != -1);
    log_assert(res != NULL);

    return res;
}
