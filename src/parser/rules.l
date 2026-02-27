%{
    #include "../common/common.h"
    #include "ast.h"
    #include "parser.h"
    #include "tfrag.h"
    #include "token.h"
    #include "rules.tab.h"
    extern void yyerror(const char *);

    // will be inited in parser_parse()
    // both begin and end parts will be the same
    // so you (me) should take snapshots of it
    tfrag_t cur_frag;

    // maintains cur_frag
    static void count();

    static const char *parse_string(const char *data);

    #define COUNT(frag) do {\
        tfrag_t frag1 = cur_frag;\
        count();\
        tfrag_t frag2 = cur_frag;\
        tfrag_combine(&frag, &frag1, &frag2);\
        frag.token = token_get(yytext);\
    } while (0)

    #define ALLOC(t) ({\
        t *res = (t*)malloc(sizeof(t));\
        log_assert(res != NULL);\
        *res = (t){0};\
        res;\
    })

    #define NAME(frag, str) ({\
        struct name_node_t *res = ALLOC(struct name_node_t);\
        res->frag = (frag);\
        res->name = token_get(str);\
        res;\
    })
%}

NAME                                    [a-zA-Z_][a-zA-Z_0-9]*

%%

"//".* {
    count();
}

"/*"([^*]|\*+[^*/])*\*+"/" {
    count();
}

"m"[0-9]* {
    tfrag_t frag;
    COUNT(frag);

    struct memory_length_node_t *res = ALLOC(struct memory_length_node_t);
    res->frag = frag;
    res->prefix = NAME(frag, frag.token);

    yylval.memory_length = res;
    return MEMORY_LENGTH_SIMPLE;
}

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

static void count() {
    const char *str = yytext;
    while (*str != '\0') {
        count_char(*(str++));
    }
}

static const char *parse_string(const char *str) {
    char *res = strdup(str);
    log_assert(res != NULL);
    int   res_i = 0;
    const char *ptr = str;

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
