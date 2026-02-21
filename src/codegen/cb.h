#pragma once

#include "../common/common.h"

struct cblock_line_t {
    int indent;
    const char *line;
};

typedef struct cblock_t {
    int size, cap;
    struct cblock_line_t *lines;
} cb_t;

#define CB_TAB 4

void cb_init(cb_t *cb);
void cb_add_front(cb_t *cb, int indent, const char *line);
void cb_add_back(cb_t *cb, int indent, const char *line);
void cb_glue_front(cb_t *cb, cb_t *glue_me);
void cb_glue_back(cb_t *cb, cb_t *glue_me);
void cb_destroy(cb_t *cb); // does NOT free cb




