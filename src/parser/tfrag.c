#include "tfrag.h"

void tfrag_init(tfrag_t *tfrag, const char *token, const char *filename,
                uint64_t begin, uint64_t end, uint64_t begin_line, uint64_t end_line,
                uint64_t begin_col, uint64_t end_col) {
    tfrag->token = token;
    tfrag->filename = filename;
    tfrag->begin = begin;
    tfrag->end = end;
    tfrag->begin_line = begin_line;
    tfrag->end_line = end_line;
    tfrag->begin_col = begin_col;
    tfrag->end_col = end_col;
}

void tfrag_combine(tfrag_t *res, tfrag_t *first, tfrag_t *second) {
    res->token = NULL;
    res->filename = first->filename;
    res->begin = MIN(first->begin, second->begin);
    res->end = MAX(first->end, second->end);
    res->begin_line = MIN(first->begin_line, second->begin_line);
    res->end_line = MAX(first->end_line, second->end_line);

    res->begin_col = first->begin_line < second->begin_line ? first->begin_col
                                                            : second->begin_col;
    if (first->begin_line == second->begin_line) {
        res->begin_col = MIN(first->begin_col, second->begin_col);
    }

    res->end_col =
        first->end_line > second->end_line ? first->end_col : second->end_col;
    if (first->end_line == second->end_line) {
        res->end_col = MAX(first->end_col, second->end_col);
    }
}

