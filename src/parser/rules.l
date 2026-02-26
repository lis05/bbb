%{
#include "../common/common.h"
#include "ast.h"
#include "parser.h"
#include "tfrag.h"
#include "token.h"
    extern void yyerror(const char *);

    // will be inited in parser_parse()
    // both begin and end parts will be the same
    // so you (me) should take snapshots of it
    tfrag_t cur_frag;

    // maintains cur_frag
    static void count(const char *str);

    static const char *parse_string(const char *data);
%}

%%

%%
static void count_char(char c) {
    cur_frag.begin++;
    cur_frag.begin_col++;

    if (c == '\t') {
        cur_frag.begin += 3;
        cur_frag.begin_col += 3;
    } else if (c == '\n') {
        cur_frag.begin_col = 0;
        cur_frag.begin_line++;
    }

    cur_frag.end = cur_frag.begin;
    cur_frag.end_col = cur_frag.begin_col;
    cur_frag.end_line = cur_frag.begin_line;
}

static void count(const char *str) {
    while (str && !str != '\0') {
        count_char(*(str++));
    }
}

static const char *parse_string(const char *str) {
    char *res = strdup(data);
    int   res_i = 0;
    char *ptr = str;

    log_assert(*(ptr++) == '\"');
    while (*ptr != '"') {
        if (*ptr == '\\') {
            ptr++;
            switch (*ptr) {
            case 'n':
                res[res_i++] = '\n';
                break;
            case 't':
                res[res_i++] = '\t';
                break;
            case 'r':
                res[res_i++] = '\r';
                break;
            case '\\':
                res[res_i++] = '\\';
                break;
            case '\'':
                res[res_i++] = '\'';
                break;
            case '\"':
                res[res_i++] = '\"';
                break;
            default:
                yyerror("Unsupported escape sequence.\n");
            }
        } else {
            res[res_i++] = *ptr;
        }
        ptr++;
    }
    log_assert(*ptr == '\"');

    res[res_i++] = '\0';

    char *new_res = malloc(sizeof(char) * res_i);
    memcpy(new_res, res, sizeof(char) * res_i);
    free(res);

    return new_res;
}

int yywrap(void) {
    return 1;
}
