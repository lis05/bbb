#pragma once

#include "../common/common.h"

struct cblock_line_t {
    int                     indent;
    const char *line NONULL MUSTFREE;
};

typedef struct cblock_t {
    int                                size, cap;
    struct cblock_line_t *lines NONULL MUSTFREE;
} cb_t;

#define CB_TAB 4

void cb_init(cb_t *cb NONULL) MEMSAFE;
void cb_add_front(cb_t *cb NONULL, int indent, const char *format, ...) MEMSAFE;
void cb_add_back(cb_t *cb NONULL, int indent, const char *format, ...) MEMSAFE;
// both glueing functions call cb_destroy() on glue_me
void cb_glue_front(cb_t *cb NONULL, cb_t *glue_me) MEMSAFE;
void cb_glue_back(cb_t *cb NONULL, cb_t *glue_me) MEMSAFE;
void cb_destroy(cb_t *cb NONULL) MEMSAFE;
cb_t cb_invalid() MEMSAFE;
int  cb_is_valid(cb_t *cb NONULL) MEMSAFE;
void cb_print(FILE *fd, cb_t *cb NONULL) MEMSAFE;

