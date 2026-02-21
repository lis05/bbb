#include "cb.h"

void cb_init(cb_t *cb) {
    cb->size = 0;
    cb->cap = 1;
    cb->lines = (struct cblock_line_t *)malloc(sizeof(struct cblock_line_t));
    log_assert(cb->lines != NULL);
}

void cb_add_front(cb_t *cb, int indent, const char *line) {
    cb_t *part = (cb_t *)malloc(sizeof(cb_t));
    log_assert(part != NULL);

    cb_init(part);
    part->size = 1;
    part->lines[0].indent = indent;
    part->lines[0].line = strdup(line);
    log_assert(part->lines[0].line != NULL);

    cb_glue_front(cb, part);
}

void cb_add_back(cb_t *cb, int indent, const char *line) {
    cb_t *part = (cb_t *)malloc(sizeof(cb_t));
    log_assert(part != NULL);

    cb_init(part);
    part->size = 1;
    part->lines[0].indent = indent;
    part->lines[0].line = strdup(line);
    log_assert(part->lines[0].line != NULL);

    cb_glue_back(cb, part);
}

void cb_glue_front(cb_t *cb, cb_t *glue_me) {
    while (cb->size + glue_me->size > cb->cap) {
        cb->cap = cb->cap * 2;
        cb->lines = (struct cblock_line_t *)realloc(
            cb->lines, sizeof(struct cblock_line_t) * cb->cap);
        log_assert(cb->lines != NULL);
    }

    for (int i = cb->size - 1; i >= 0; i--) {
        cb->lines[i + glue_me->size] = cb->lines[i];
    }

    for (int i = 0; i < glue_me->size; i++) {
        cb->lines[i] = glue_me->lines[i];
        cb->size++;
    }

    glue_me->size = 0;
    cb_destroy(glue_me);
}

void cb_glue_back(cb_t *cb, cb_t *glue_me) {
    while (cb->size + glue_me->size > cb->cap) {
        cb->cap = cb->cap * 2;
        cb->lines = (struct cblock_line_t *)realloc(
            cb->lines, sizeof(struct cblock_line_t) * cb->cap);
        log_assert(cb->lines != NULL);
    }

    for (int i = 0; i < glue_me->size; i++) {
        cb->lines[cb->size] = glue_me->lines[i];
        cb->size++;
    }

    glue_me->size = 0;
    cb_destroy(glue_me);
}

void cb_destroy(cb_t *cb) {
    free(cb->lines);
    cb->size = cb->cap = 0;
}

