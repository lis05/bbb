#pragma once

#include "../common/common.h"

typedef struct text_fragment_t {
    const char *token;
    const char *filename;
    uint64_t    begin;
    uint64_t    end;
    uint64_t    begin_line;
    uint64_t    end_line;
    uint64_t    begin_col;
    uint64_t    end_col;
} tfrag_t;

void tfrag_init(tfrag_t *tfrag, const char *token, const char *filename,
                uint64_t begin, uint64_t end, uint64_t begin_line, uint64_t end_line,
                uint64_t begin_col, uint64_t end_col);

void tfrag_combine(tfrag_t *res, tfrag_t *first, tfrag_t *second);
