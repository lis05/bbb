#include "cb.h"
#include <stdarg.h>

void cb_init(cb_t *cb) {
    cb->size = 0;
    cb->cap = 1;
    cb->lines = (struct cblock_line_t *)malloc(sizeof(struct cblock_line_t));
    log_assert(cb->lines != NULL);
}

void cb_add_front(cb_t *cb, int indent, const char *format, ...) {
    cb_t *part = (cb_t *)malloc(sizeof(cb_t));
    log_assert(part != NULL);

    char *line = NULL;
    va_list list;
    va_start(list, format);
    if (vasprintf(&line, format, list) == -1) {
        log_crit("Error vasprintf: %s\n", strerror(errno));
        return; // should probably add error codes or smth
    }
    va_end(list);
    log_assert(line != NULL);

    cb_init(part);
    part->size = 1;
    part->lines[0].indent = indent;
    part->lines[0].line = line;
    log_assert(part->lines[0].line != NULL);

    int old_size = cb->size;
    cb_glue_front(cb, part);
    log_assert(cb->size == old_size + 1);
    free(part);
}

void cb_add_back(cb_t *cb, int indent, const char *format, ...) {
    cb_t *part = (cb_t *)malloc(sizeof(cb_t));
    log_assert(part != NULL);

    char *line = NULL;
    va_list list;
    va_start(list, format);
    if (vasprintf(&line, format, list) == -1) {
        log_crit("Error vasprintf: %s\n", strerror(errno));
        return; // should probably add error codes or smth
    }
    va_end(list);
    log_assert(line != NULL);

    cb_init(part);
    part->size = 1;
    part->lines[0].indent = indent;
    part->lines[0].line = line;
    log_assert(part->lines[0].line != NULL);

    int old_size = cb->size;
    cb_glue_back(cb, part);
    log_assert(cb->size == old_size + 1);
    free(part);
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

cb_t cb_invalid() {
    return (cb_t){-1, -1, NULL};
}

int cb_is_valid(cb_t *cb) {
    return cb != NULL && cb->size != -1 && cb->cap != -1 && cb->lines != NULL;
}

void cb_print(FILE *fd, cb_t *cb) {
    for (int i = 0; i < cb->size; i++) {
        for (int ii = 0; ii < cb->lines[i].indent; ii++) {
            fprintf(fd, " ");
        }

        fprintf(fd, "%s", cb->lines[i].line);
    }
}
