#include <ctype.h>
#include <errno.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "log.h"
#include "mem.h"
#include "pstr.h"
#include "tags.h"

#define true 1
#define false 0
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) < (y) ? (y) : (x))
#define SWAP(x, y)           \
    do {                     \
        typeof(x) tmp = (x); \
        (x) = (y);           \
        (y) = tmp;           \
    } while (0)
