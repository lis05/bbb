#pragma once

#include "log.h"
#include "tags.h"

// MEMSAFE NONULL MUSTFREE
#define calloc_safe(how_many, size_of_one)              \
    ({                                                  \
        void *_res = calloc((how_many), (size_of_one)); \
        log_assert(_res != NULL);                       \
        _res;                                           \
    })

// ptr: NONULL
// MEMSAFE NONULL MUSTFREE
#define memdup_safe(ptr, size)      \
    ({                              \
        const void *_ptr = (ptr);   \
        size_t      _size = (size); \
        log_assert(_ptr != NULL);   \
        void *_res = malloc(_size); \
        log_assert(_res != NULL);   \
        memcpy(_res, _ptr, _size);  \
        _res;                       \
    })

// str: NONULL
// MEMSAFE NONULL MUSTFREE
#define strdup_safe(str)                     \
    ({                                       \
        const char *_str = (str);            \
        log_assert(_str != NULL);            \
        memdup_safe(_str, strlen(_str) + 1); \
    })

// ptr: NONULL
// MEMSAFE NONULL MUSTFREE
#define realloc_safe(ptr, size)            \
    ({                                     \
        void  *_ptr = (ptr);               \
        size_t _size = (size);             \
        log_assert(_ptr != NULL);          \
        void *_res = realloc(_ptr, _size); \
        log_assert(_res != NULL);          \
        _res;                              \
    })

// str: NONULL
// fmt: NONULL
// MEMSAFE NONULL MUSTFREE
#define asprintf_safe(str, fmt, ...)                         \
    ({                                                       \
        const char *_str = (str);                            \
        const char *_fmt = (fmt);                            \
        log_assert(str != NULL);                             \
        log_assert(fmt != NULL);                             \
        char *_res;                                          \
        log_assert(-1 != asprintf(_str, _fmt, __VA_ARGS__)); \
        log_assert(_res != NULL);                            \
        res;                                                 \
    })
