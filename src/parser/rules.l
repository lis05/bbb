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
    // for errors
    tfrag_t error_frag;

    // maintains cur_frag
    static void count();

    static const char *parse_string(const char *data);

    extern int print_lexemes;
    #define PRINT(...) do {\
        if (print_lexemes) printf(__VA_ARGS__);\
    } while(0)

    #define COUNT(frag) do {\
        tfrag_t frag1 = cur_frag;\
        count();\
        tfrag_t frag2 = cur_frag;\
        tfrag_combine(&frag, &frag1, &frag2);\
        frag.token = token_get(yytext);\
        error_frag = frag;\
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

    #define RET_NAME(ret_code) do {\
        tfrag_t frag;\
        COUNT(frag);\
        yylval.name = NAME(frag, frag.token);\
        return ret_code;\
    } while(0)
%}

NAME                                    [a-zA-Z_][a-zA-Z_0-9]*
GP_REGISTER                             r([abcd]x|si|di|sp|bp|[8-9]|1[0-5])
REGISTER                                ({GP_REGISTER}|xmm([0-9]|1[0-5]))
MEM_LEN_S                               "m"[0-9]+
MEM_LEN_P                               "m(sizeof "{NAME}")"
TYPE                                    (s?[bwdq]|[fF])
OP_TYPE                                 ({TYPE}|{MEM_LEN_S}|{MEM_LEN_P})

%x                                      NASM_BLOCK_STATE
%%

"//".*                                  { PRINT("[LINE-COMMENT]\n"); count(); }
"/*"([^*]|\*+[^*/])*\*+"/"              { PRINT("[MULTILINE-COMMENT]\n"); count(); }
{MEM_LEN_P}                             { PRINT("[MEMORY_LENGTH_PREFIX: '%s']\n", yytext); RET_NAME(MEMORY_LENGTH_PREFIX); }
{MEM_LEN_S}                             { PRINT("[MEMORY_LENGTH_SIMPLE: '%s']\n", yytext); RET_NAME(MEMORY_LENGTH_SIMPLE); }
"align"[1-9][0-9]* { PRINT("[ALIGNMENT_SIMPLE: '%s']\n", yytext); RET_NAME(ALIGNMENT_SIMPLE); }
"#mem"                                  { PRINT("[CHUNK_CLASS_MEM]\n"); RET_NAME(CHUNK_CLASS_MEM); }
"#sse"                                  { PRINT("[CHUNK_CLASS_SSE]\n"); RET_NAME(CHUNK_CLASS_SSE); }
"#int"                                  { PRINT("[CHUNK_CLASS_INT]\n"); RET_NAME(CHUNK_CLASS_INT); }
"#"{NAME}                               { PRINT("[CHUNK_CLASS_LAYOUT: '%s']\n", yytext); RET_NAME(CHUNK_CLASS_LAYOUT); }
{GP_REGISTER}                           { PRINT("[GP_REGISTER: '%s']\n", yytext); RET_NAME(GP_REGISTER); }
{REGISTER}                              { PRINT("[REGISTER: '%s']\n", yytext); RET_NAME(REGISTER); }
"global"                                { PRINT("[GLOBAL]\n"); RET_NAME(GLOBAL); }
"layout"                                { PRINT("[LAYOUT]\n"); RET_NAME(LAYOUT); }
"extern"                                { PRINT("[EXTERN]\n"); RET_NAME(EXTERN); }
"nasm"                                  { PRINT("[NASM]\n"); RET_NAME(NASM); }
"fn"                                    { PRINT("[FN]\n"); RET_NAME(FN); }
"%nasm"                                 { PRINT("[NASM_BLOCK_START]\n"); BEGIN(NASM_BLOCK_STATE); yymore(); }
<NASM_BLOCK_STATE>{
    "%endnasm"                          { PRINT("[NASM_BLOCK: '%s']\n", yytext); BEGIN(INITIAL); RET_NAME(NASM_BLOCK); }
    .|\n                                { yymore(); }
}
"if"                                    { PRINT("[IF]\n"); RET_NAME(IF); }
"else"                                  { PRINT("[ELSE]\n"); RET_NAME(ELSE); }
"goto"                                  { PRINT("[GOTO]\n"); RET_NAME(GOTO); }
"loop"                                  { PRINT("[LOOP]\n"); RET_NAME(LOOP); }
"break"                                 { PRINT("[BREAK]\n"); RET_NAME(BREAK); }
"continue"                              { PRINT("[CONTINUE]\n"); RET_NAME(CONTINUE); }
"ret"                                   { PRINT("[RET]\n"); RET_NAME(RET); }
"avoid"                                 { PRINT("[AVOID]\n"); RET_NAME(AVOID); }
"alias"                                 { PRINT("[ALIAS]\n"); RET_NAME(ALIAS); }
"reg"                                   { PRINT("[REG]\n"); RET_NAME(REG); }
"sizeof"                                { PRINT("[SIZEOF]\n"); RET_NAME(SIZEOF); }
{OP_TYPE}?"||"{OP_TYPE}?                { PRINT("[LOGICAL_OR: '%s']\n", yytext); RET_NAME(LOGICAL_OR); }
{OP_TYPE}?"&&"{OP_TYPE}?                { PRINT("[LOGICAL_AND: '%s']\n", yytext); RET_NAME(LOGICAL_AND); }
{OP_TYPE}?"++"{OP_TYPE}?                { PRINT("[INCREMENT: '%s']\n", yytext); RET_NAME(INCREMENT); }
{OP_TYPE}?"--"{OP_TYPE}?                { PRINT("[DECREMENT: '%s']\n", yytext); RET_NAME(DECREMENT); }
{OP_TYPE}?"+"{OP_TYPE}?                 { PRINT("[PLUS: '%s']\n", yytext); RET_NAME(PLUS); }
{OP_TYPE}?"-"{OP_TYPE}?                 { PRINT("[MINUS: '%s']\n", yytext); RET_NAME(MINUS); }
{OP_TYPE}?"*"{OP_TYPE}?                 { PRINT("[MULTIPLY: '%s']\n", yytext); RET_NAME(MULTIPLY); }
{OP_TYPE}?"/"{OP_TYPE}?                 { PRINT("[DIVIDE: '%s']\n", yytext); RET_NAME(DIVIDE); }
{OP_TYPE}?"%"{OP_TYPE}?                 { PRINT("[REMAINDER: '%s']\n", yytext); RET_NAME(REMAINDER); }
{OP_TYPE}?"&"{OP_TYPE}?                 { PRINT("[BITWISE_AND: '%s']\n", yytext); RET_NAME(BITWISE_AND); }
{OP_TYPE}?"|"{OP_TYPE}?                 { PRINT("[BITWISE_OR: '%s']\n", yytext); RET_NAME(BITWISE_OR); }
{OP_TYPE}?"^"{OP_TYPE}?                 { PRINT("[BITWISE_XOR: '%s']\n", yytext); RET_NAME(BITWISE_XOR); }
{OP_TYPE}?"!"{OP_TYPE}?                 { PRINT("[LOGICAL_NOT: '%s']\n", yytext); RET_NAME(LOGICAL_NOT); }
{OP_TYPE}?"~"{OP_TYPE}?                 { PRINT("[BITWISE_NOT: '%s']\n", yytext); RET_NAME(BITWISE_NOT); }
{OP_TYPE}?"<="{OP_TYPE}?                { PRINT("[LESS_EQUAL: '%s']\n", yytext); RET_NAME(LESS_EQUAL); }
{OP_TYPE}?">="{OP_TYPE}?                { PRINT("[GREATER_EQUAL: '%s']\n", yytext); RET_NAME(GREATER_EQUAL); }
{OP_TYPE}?"<"{OP_TYPE}?                 { PRINT("[LESS_THAN: '%s']\n", yytext); RET_NAME(LESS_THAN); }
{OP_TYPE}?">"{OP_TYPE}?                 { PRINT("[GREATER_THAN: '%s']\n", yytext); RET_NAME(GREATER_THAN); }
{OP_TYPE}?"=="{OP_TYPE}?                { PRINT("[EQUALS: '%s']\n", yytext); RET_NAME(EQUALS); }
{OP_TYPE}?"!="{OP_TYPE}?                { PRINT("[NOT_EQUALS: '%s']\n", yytext); RET_NAME(NOT_EQUALS); }
{OP_TYPE}?"="{OP_TYPE}?                 { PRINT("[ASSIGN: '%s']\n", yytext); RET_NAME(ASSIGN); }
{OP_TYPE}"?"{OP_TYPE}                   { PRINT("[CAST: '%s']\n", yytext); RET_NAME(CAST); }
{NAME}"."                               { PRINT("[ACCESS: '%s']\n", yytext); RET_NAME(ACCESS); }
"("                                     { PRINT("[ROB]: (\n"); RET_NAME(ROB); }
")"                                     { PRINT("[RCB]: )\n"); RET_NAME(RCB); }
"["                                     { PRINT("[SOB]: [\n"); RET_NAME(SOB); }
"]"                                     { PRINT("[SCB]: ]\n"); RET_NAME(SCB); }
"{"                                     { PRINT("[COB]: {\n"); RET_NAME(COB); }
"}"                                     { PRINT("[CCB]: }\n"); RET_NAME(CCB); }
"->"                                    { PRINT("[ARROW]\n"); RET_NAME(ARROW); }
":"                                     { PRINT("[COLON]\n"); RET_NAME(COLON); }
";"                                     { PRINT("[SEMICOLON]\n"); RET_NAME(SEMICOLON); }
","                                     { PRINT("[COMMA]\n"); RET_NAME(COMMA); }
\"([^\"\\]|\\.)*\"                      {
    PRINT("[STRING: '%s']\n", yytext);
    tfrag_t frag;
    COUNT(frag);
    struct literal_node_t *res = ALLOC(struct literal_node_t);
    res->frag = frag;
    res->type = LIT_STRING;
    res->string_lit = parse_string(yytext);
    yylval.literal = res;
    return STRING;
}
{NAME} { PRINT("[NAME: '%s']\n", yytext); RET_NAME(NAME); }
[+-](0x|0X|0)?[0-9a-fA-F]+ {
    PRINT("[INT: '%s']\n", yytext);
    tfrag_t frag;
    COUNT(frag);
    struct literal_node_t *res = ALLOC(struct literal_node_t);
    res->frag = frag;
    res->type = LIT_INT;

    char *ptr = yytext;
    res->int_lit = strtol(yytext, &ptr, 0);
    if (*ptr != '\0') {
        yyerror("Invalid integer literal.");
        exit(-1);
    }

    yylval.literal = res;
    return INT;
}
(0x|0X|0)?[0-9a-fA-F]+ {
    PRINT("[UINT: '%s']\n", yytext);
    tfrag_t frag;
    COUNT(frag);
    struct literal_node_t *res = ALLOC(struct literal_node_t);
    res->frag = frag;
    res->type = LIT_UINT;

    char *ptr = yytext;
    res->uint_lit = strtoul(yytext, &ptr, 0);
    if (*ptr != '\0') {
        yyerror("Invalid unsigned integer literal.");
        exit(-1);
    }

    yylval.literal = res;
    return UINT;
}
[+-]?([0-9]*[.])?[0-9]+([eE][+-]?[0-9]+)? {
    PRINT("[DOUBLE: '%s']\n", yytext);
    tfrag_t frag;
    COUNT(frag);
    struct literal_node_t *res = ALLOC(struct literal_node_t);
    res->frag = frag;
    res->type = LIT_DOUBLE;
    res->double_lit = strtod(yytext, NULL);
    yylval.literal = res;
    return DOUBLE;
}
[ \t\r\n] { count(); }
%% // fucking ai, do not remove useful code
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
