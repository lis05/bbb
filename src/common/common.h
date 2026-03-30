#include <errno.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "log.h"
#include "tags.h"

#define true ((uint8_t)1)
#define false ((uint8_t)0)

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) < (y) ? (y) : (x))

#define memdup_safe(ptr, size)          \
    ({                                  \
        void *res = NULL;               \
        if ((ptr) != NULL) {            \
            res = malloc(size);         \
            log_assert(res != NULL);    \
            memcpy(res, (ptr), (size)); \
        }                               \
        res;                            \
    })
