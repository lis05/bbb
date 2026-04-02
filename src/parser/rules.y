%{
    #include "../common/common.h"
    #include "ast.h"
    #include "parser.h"
    extern int yylex();
    extern int yyparse();
    extern FILE *yyin;

    void yyerror(const char *s);

    #define YYMALLOC(sz) calloc_safe(1, sz)
    #define YYFREE(p) free(p)

    #define ALLOC(t) ({\
        t *res = calloc_safe(1, sizeof(t));\
        log_assert(res != NULL);\
        *res = (t){0};\
        res;\
    })

    // please fix this mess if you know how to do it
    #define _TF_C(t1, t2, t3) tfrag_combine(&(t1)->frag, &(t2)->frag, &(t3)->frag)
    #define _TF_C1(dest) do {} while (0)
    #define _TF_C2(dest, t1) do { (dest)->frag = (t1)->frag; } while (0)
    #define _TF_C3(dest, t1, t2) _TF_C(dest, t1, t2)
    #define _TF_C4(dest, t1, t2, t3) do {\
        _TF_C3(dest, t1, t2);\
        _TF_C(dest, dest, t3);\
    } while(0);
    #define _TF_C5(dest, t1, t2, t3, t4) do {\
        _TF_C4(dest, t1, t2, t3);\
        _TF_C(dest, dest, t4);\
    } while(0);
    #define _TF_C6(dest, t1, t2, t3, t4, t5) do {\
        _TF_C5(dest, t1, t2, t3, t4);\
        _TF_C(dest, dest, t5);\
    } while(0);
    #define _TF_C7(dest, t1, t2, t3, t4, t5, t6) do {\
        _TF_C6(dest, t1, t2, t3, t4, t5);\
        _TF_C(dest, dest, t6);\
    } while(0);
    #define _TF_C8(dest, t1, t2, t3, t4, t5, t6, t7) do {\
        _TF_C7(dest, t1, t2, t3, t4, t5, t6);\
        _TF_C(dest, dest, t7);\
    } while(0);
    #define _TF_C9(dest, t1, t2, t3, t4, t5, t6, t7, t8) do {\
        _TF_C8(dest, t1, t2, t3, t4, t5, t6, t7);\
        _TF_C(dest, dest, t8);\
    } while(0);
    #define _TF_C10(dest, t1, t2, t3, t4, t5, t6, t7, t8, t9) do {\
        _TF_C9(dest, t1, t2, t3, t4, t5, t6, t7, t8);\
        _TF_C(dest, dest, t9);\
    } while(0);
    #define _TF_C11(dest, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10) do {\
        _TF_C10(dest, t1, t2, t3, t4, t5, t6, t7, t8, t9);\
        _TF_C(dest, dest, t10);\
    } while(0);
    #define _TF_C12(dest, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11) do {\
        _TF_C11(dest, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10);\
        _TF_C(dest, dest, t11);\
    } while(0);

    #define _GET_TF_C(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, NAME, ...)\
        NAME
    #define TFRAG_COMBINE(...) _GET_TF_C(__VA_ARGS__, _TF_C12, _TF_C11,\
        _TF_C10, _TF_C9, _TF_C8, _TF_C7, _TF_C6, _TF_C5, _TF_C4,\
        _TF_C3, _TF_C2, _TF_C1)(__VA_ARGS__)
%}

%define parse.error verbose

%union {
    struct program_node_t *program;
    struct global_variable_declaration_node_t *global_variable_declaration;
    struct abi_class_node_t *abi_class;
    struct layout_declaration_items_node_t *layout_declaration_items;
    struct layout_declaration_node_t *layout_declaration;
    struct extern_declaration_node_t *extern_declaration;
    struct function_declaration_arg_node_t *function_declaration_arg;
    struct function_declaration_args_node_t *function_declaration_args;
    struct function_declaration_node_t *function_declaration;
    struct body_list_node_t *body_list;
    struct body_node_t *body;
    struct statement_node_t *statement;
    struct variable_declaration_node_t *variable_declaration;
    struct register_alias_node_t *register_alias;
    struct if_statement_node_t *if_statement;
    struct label_declaration_node_t *label_declaration;
    struct goto_statement_node_t *goto_statement;
    struct loop_statement_node_t *loop_statement;
    struct break_statement_node_t *break_statement;
    struct ret_statement_node_t *ret_statement;
    struct avoid_block_regs_node_t *avoid_block_regs;
    struct avoid_block_node_t *avoid_block;
    struct expression_node_t *expression;
    struct logical_or_node_t *logical_or;
    struct logical_and_node_t *logical_and;
    struct bitwise_or_node_t *bitwise_or;
    struct bitwise_xor_node_t *bitwise_xor;
    struct bitwise_and_node_t *bitwise_and;
    struct equality_node_t *equality;
    struct relational_node_t *relational;
    struct additive_node_t *additive;
    struct multiplicative_node_t *multiplicative;
    struct prefix_op_node_t *prefix_op;
    struct cast_op_node_t *cast_op;
    struct address_op_node_t *address_op;
    struct sizeof_op_node_t *sizeof_op;
    struct tetriary_node_t *tetriary;
    struct suffix_op_node_t *suffix_op;
    struct function_call_op_arg_node_t *function_call_op_arg;
    struct function_call_op_args_node_t *function_call_op_args;
    struct function_call_op_node_t *function_call_op;
    struct dereference_op_node_t *dereference_op;
    struct layout_access_op_node_t *layout_access_op;
    struct secondary_node_t *secondary;
    struct primary_node_t *primary;
    struct literal_node_t *literal;
    struct name_node_t *name;
}

%start program

%token <name> NAME
%token <literal> INT
%token <literal> UINT
%token <literal> DOUBLE
%token <literal> STRING
%token <name> MEMORY_LENGTH_SIMPLE
%token <name> MEMORY_LENGTH_PREFIX
%token <name> ALIGNMENT_SIMPLE
%token <name> CHUNK_CLASS_MEM
%token <name> CHUNK_CLASS_SSE
%token <name> CHUNK_CLASS_INT
%token <name> CHUNK_CLASS_LAYOUT
%token <name> GP_REGISTER
%token <name> REGISTER
%token <name> GLOBAL
%token <name> LAYOUT
%token <name> EXTERN
%token <name> NASM
%token <name> FN
%token <name> NASM_BLOCK
%token <name> IF
%token <name> ELSE
%token <name> GOTO
%token <name> LOOP
%token <name> BREAK
%token <name> CONTINUE
%token <name> RET
%token <name> AVOID
%token <name> ALIAS
%token <name> REG
%token <name> CALL

%token <name> LOGICAL_OR
%token <name> LOGICAL_AND
%token <name> ASSIGN
%token <name> INCREMENT
%token <name> DECREMENT
%token <name> SIZEOF
%token <name> PLUS
%token <name> MINUS
%token <name> MULTIPLY
%token <name> DIVIDE
%token <name> REMAINDER
%token <name> BITWISE_AND
%token <name> BITWISE_OR
%token <name> BITWISE_XOR
%token <name> LOGICAL_NOT
%token <name> BITWISE_NOT
%token <name> LESS_THAN
%token <name> GREATER_THAN
%token <name> LESS_EQUAL
%token <name> GREATER_EQUAL
%token <name> EQUALS
%token <name> NOT_EQUALS
%token <name> CAST
%token <name> ACCESS

%token <name> ROB "("
%token <name> RCB ")"
%token <name> SOB "["
%token <name> SCB "]"
%token <name> COB "{"
%token <name> CCB "}"
%token <name> ARROW
%token <name> COLON ":"
%token <name> SEMICOLON ";"
%token <name> COMMA ","

%type <program> program
%type <name> visibility
%type <name> memory_length
%type <name> alignment
%type <global_variable_declaration> global_variable_declaration
%type <name> chunk_class
%type <abi_class> abi_class
%type <layout_declaration_items> layout_declaration_items
%type <layout_declaration> layout_declaration
%type <extern_declaration> extern_declaration
%type <function_declaration_arg> function_declaration_arg
%type <function_declaration_args> function_declaration_args
%type <function_declaration> function_declaration
%type <body_list> body_list
%type <body> body
%type <statement> statement
%type <variable_declaration> variable_declaration
%type <register_alias> register_alias
%type <if_statement> if_statement
%type <label_declaration> label_declaration
%type <goto_statement> goto_statement
%type <loop_statement> loop_statement
%type <break_statement> break_statement
%type <ret_statement> ret_statement
%type <avoid_block_regs> avoid_block_regs
%type <avoid_block> avoid_block

%type <expression> expression
%type <logical_or> logical_or
%type <logical_and> logical_and
%type <bitwise_or> bitwise_or
%type <bitwise_xor> bitwise_xor
%type <bitwise_and> bitwise_and
%type <equality> equality
%type <relational> relational
%type <additive> additive
%type <multiplicative> multiplicative
%type <prefix_op> prefix_op
%type <cast_op> cast_op
%type <address_op> address_op
%type <sizeof_op> sizeof_op
%type <tetriary> tetriary
%type <suffix_op> suffix_op
%type <function_call_op_arg> function_call_op_arg
%type <function_call_op_args> function_call_op_args
%type <function_call_op> function_call_op
%type <dereference_op> dereference_op
%type <layout_access_op> layout_access_op
%type <secondary> secondary
%type <primary> primary
%type <literal> literal

%%

program:
    program global_variable_declaration {
        $$ = ALLOC(struct program_node_t);
        TFRAG_COMBINE($$, $1, $2);
        $$->rest = $1;
        $$->gvar_decl = $2;
        parsing_result = $$;
    }
    | program layout_declaration {
        $$ = ALLOC(struct program_node_t);
        TFRAG_COMBINE($$, $1, $2);
        $$->rest = $1;
        $$->layout_decl = $2;
        parsing_result = $$;
    }
    | program extern_declaration {
        $$ = ALLOC(struct program_node_t);
        TFRAG_COMBINE($$, $1, $2);
        $$->rest = $1;
        $$->ext_decl = $2;
        parsing_result = $$;
    }
    | program function_declaration {
        $$ = ALLOC(struct program_node_t);
        TFRAG_COMBINE($$, $1, $2);
        $$->rest = $1;
        $$->fn_decl = $2;
        parsing_result = $$;
    }
    | program NASM_BLOCK {
        $$ = ALLOC(struct program_node_t);
        TFRAG_COMBINE($$, $1, $2);
        $$->rest = $1;
        $$->nasm_b = $2;
        parsing_result = $$;
    }
    | {
        $$ = ALLOC(struct program_node_t);
        parsing_result = $$;
    }
    ;

visibility:
    GLOBAL { $$ = $1; }
    ;

memory_length:
    MEMORY_LENGTH_SIMPLE { $$ = $1; }
    | MEMORY_LENGTH_PREFIX { $$ = $1; }
    ;

alignment:
    ALIGNMENT_SIMPLE { $$ = $1; }
    ;

global_variable_declaration:
    NAME ":" memory_length {
        $$ = ALLOC(struct global_variable_declaration_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->name = $1;
        $$->colon = $2;
        $$->mem_len = $3;
    }
    | NAME ":" visibility memory_length {
        $$ = ALLOC(struct global_variable_declaration_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4);
        $$->name = $1;
        $$->colon = $2;
        $$->vis = $3;
        $$->mem_len = $4;
    }
    | NAME ":" memory_length alignment {
        $$ = ALLOC(struct global_variable_declaration_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4);
        $$->name = $1;
        $$->colon = $2;
        $$->mem_len = $3;
        $$->align = $4;
    }
    | NAME ":" visibility memory_length alignment {
        $$ = ALLOC(struct global_variable_declaration_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4, $5);
        $$->name = $1;
        $$->colon = $2;
        $$->vis = $3;
        $$->mem_len = $4;
        $$->align = $5;
    }
    ;

chunk_class:
    CHUNK_CLASS_MEM { $$ = $1; }
    | CHUNK_CLASS_SSE { $$ = $1; }
    | CHUNK_CLASS_INT { $$ = $1; }
    ;

abi_class:
    chunk_class {
        $$ = ALLOC(struct abi_class_node_t);
        TFRAG_COMBINE($$, $1);
        $$->chunk1 = $1;
    }
    | chunk_class chunk_class {
        $$ = ALLOC(struct abi_class_node_t);
        TFRAG_COMBINE($$, $1, $2);
        $$->chunk1 = $1;
        $$->chunk2 = $2;
    }
    | CHUNK_CLASS_LAYOUT {
        $$ = ALLOC(struct abi_class_node_t);
        TFRAG_COMBINE($$, $1);
        $$->layout = $1;
    }
    ;

layout_declaration_items:
    layout_declaration_items NAME ":" memory_length {
        $$ = ALLOC(struct layout_declaration_items_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4);
        $$->rest = $1;
        $$->name = $2;
        $$->colon = $3;
        $$->mem_len = $4;
    }
    | NAME ":" memory_length {
        $$ = ALLOC(struct layout_declaration_items_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->name = $1;
        $$->colon = $2;
        $$->mem_len = $3;
    }
    ;

layout_declaration:
    NAME ":" LAYOUT "{" layout_declaration_items "}" {
        $$ = ALLOC(struct layout_declaration_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4, $5, $6);
        $$->name = $1;
        $$->colon = $2;
        $$->layout = $3;
        $$->open_brace = $4;
        $$->items = $5;
        $$->closed_brace = $6;
    }
    | NAME ":" LAYOUT chunk_class "{" layout_declaration_items "}" {
        $$ = ALLOC(struct layout_declaration_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4, $5, $6, $7);
        $$->name = $1;
        $$->colon = $2;
        $$->layout = $3;
        $$->chunk1 = $4;
        $$->open_brace = $5;
        $$->items = $6;
        $$->closed_brace = $7;
    }
    | NAME ":" LAYOUT chunk_class chunk_class "{" layout_declaration_items "}" {
        $$ = ALLOC(struct layout_declaration_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4, $5, $6, $7, $8);
        $$->name = $1;
        $$->colon = $2;
        $$->layout = $3;
        $$->chunk1 = $4;
        $$->chunk2 = $5;
        $$->open_brace = $6;
        $$->items = $7;
        $$->closed_brace = $8;
    }
    ;

extern_declaration:
    EXTERN NAME {
        $$ = ALLOC(struct extern_declaration_node_t);
        TFRAG_COMBINE($$, $1, $2);
        $$->kw = $1;
        $$->name = $2;
    }
    | NASM NAME {
        $$ = ALLOC(struct extern_declaration_node_t);
        TFRAG_COMBINE($$, $1, $2);
        $$->kw = $1;
        $$->name = $2;
    }
    ;

function_declaration_arg:
    NAME {
        $$ = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE($$, $1);
        $$->name = $1;
    }
    | NAME ":" memory_length {
        $$ = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->name = $1;
        $$->colon = $2;
        $$->mem_len = $3;
    }
    | NAME ":" alignment {
        $$ = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->name = $1;
        $$->colon = $2;
        $$->align = $3;
    }
    | NAME ":" abi_class {
        $$ = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->name = $1;
        $$->colon = $2;
        $$->abi_class = $3;
    }
    | NAME ":" memory_length alignment {
        $$ = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4);
        $$->name = $1;
        $$->colon = $2;
        $$->mem_len = $3;
        $$->align = $4;
    }
    | NAME ":" memory_length abi_class {
        $$ = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4);
        $$->name = $1;
        $$->colon = $2;
        $$->mem_len = $3;
        $$->abi_class = $4;
    }
    | NAME ":" alignment abi_class {
        $$ = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4);
        $$->name = $1;
        $$->colon = $2;
        $$->align = $3;
        $$->abi_class = $4;
    }
    | NAME ":" memory_length alignment abi_class {
        $$ = ALLOC(struct function_declaration_arg_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4, $5);
        $$->name = $1;
        $$->colon = $2;
        $$->mem_len = $3;
        $$->align = $4;
        $$->abi_class = $5;
    }
    ;

function_declaration_args:
    function_declaration_args "," function_declaration_arg {
        $$ = ALLOC(struct function_declaration_args_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->rest = $1;
        $$->comma = $2;
        $$->arg = $3;
    }
    | function_declaration_arg {
        $$ = ALLOC(struct function_declaration_args_node_t);
        TFRAG_COMBINE($$, $1);
        $$->arg = $1;
    }
    | {
        $$ = ALLOC(struct function_declaration_args_node_t);
    }
    ;

function_declaration:
    NAME ":" FN "(" function_declaration_args ")" body {
        $$ = ALLOC(struct function_declaration_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4, $5, $6, $7);
        $$->name = $1;
        $$->colon = $2;
        $$->fn = $3;
        $$->open_brace = $4;
        $$->args = $5;
        $$->closed_brace = $6;
        $$->body = $7;
    }
    | NAME ":" FN "(" function_declaration_args ")" ARROW memory_length body {
        $$ = ALLOC(struct function_declaration_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4, $5, $6, $7, $8, $9);
        $$->name = $1;
        $$->colon = $2;
        $$->fn = $3;
        $$->open_brace = $4;
        $$->args = $5;
        $$->closed_brace = $6;
        $$->arrow = $7;
        $$->mem_len = $8;
        $$->body = $9;
    }
    | NAME ":" FN "(" function_declaration_args ")" ARROW abi_class body {
        $$ = ALLOC(struct function_declaration_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4, $5, $6, $7, $8, $9);
        $$->name = $1;
        $$->colon = $2;
        $$->fn = $3;
        $$->open_brace = $4;
        $$->args = $5;
        $$->closed_brace = $6;
        $$->arrow = $7;
        $$->abi_class = $8;
        $$->body = $9;
    }
    | NAME ":" FN "(" function_declaration_args ")" ARROW memory_length abi_class body {
        $$ = ALLOC(struct function_declaration_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4, $5, $6, $7, $8, $9, $10);
        $$->name = $1;
        $$->colon = $2;
        $$->fn = $3;
        $$->open_brace = $4;
        $$->args = $5;
        $$->closed_brace = $6;
        $$->arrow = $7;
        $$->mem_len = $8;
        $$->abi_class = $9;
        $$->body = $10;
    }
    | NAME ":" visibility FN "(" function_declaration_args ")" body {
        $$ = ALLOC(struct function_declaration_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4, $5, $6, $7, $8);
        $$->name = $1;
        $$->colon = $2;
        $$->vis = $3;
        $$->fn = $4;
        $$->open_brace = $5;
        $$->args = $6;
        $$->closed_brace = $7;
        $$->body = $8;
    }
    | NAME ":" visibility FN "(" function_declaration_args ")" ARROW memory_length body {
        $$ = ALLOC(struct function_declaration_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4, $5, $6, $7, $8, $9, $10);
        $$->name = $1;
        $$->colon = $2;
        $$->vis = $3;
        $$->fn = $4;
        $$->open_brace = $5;
        $$->args = $6;
        $$->closed_brace = $7;
        $$->arrow = $8;
        $$->mem_len = $9;
        $$->body = $10;
    }
    | NAME ":" visibility FN "(" function_declaration_args ")" ARROW abi_class body {
        $$ = ALLOC(struct function_declaration_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4, $5, $6, $7, $8, $9, $10);
        $$->name = $1;
        $$->colon = $2;
        $$->vis = $3;
        $$->fn = $4;
        $$->open_brace = $5;
        $$->args = $6;
        $$->closed_brace = $7;
        $$->arrow = $8;
        $$->abi_class = $9;
        $$->body = $10;
    }
    | NAME ":" visibility FN "(" function_declaration_args ")" ARROW memory_length
abi_class body {
        $$ = ALLOC(struct function_declaration_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11);
        $$->name = $1;
        $$->colon = $2;
        $$->vis = $3;
        $$->fn = $4;
        $$->open_brace = $5;
        $$->args = $6;
        $$->closed_brace = $7;
        $$->arrow = $8;
        $$->mem_len = $9;
        $$->abi_class = $10;
        $$->body = $11;
    }
    ;

body_list:
    body_list statement {
        $$ = ALLOC(struct body_list_node_t);
        TFRAG_COMBINE($$, $1, $2);
        $$->rest = $1;
        $$->s = $2;
    }
    | {
        $$ = ALLOC(struct body_list_node_t);
    }
    ;

body:
    "{" body_list "}" {
        $$ = ALLOC(struct body_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->open_brace = $1;
        $$->list = $2;
        $$->closed_brace = $3;
    }
    ;

statement:
    variable_declaration {
        $$ = ALLOC(struct statement_node_t);
        TFRAG_COMBINE($$, $1);
        $$->vdecl = $1;
    }
    | register_alias {
        $$ = ALLOC(struct statement_node_t);
        TFRAG_COMBINE($$, $1);
        $$->alias = $1;
    }
    | extern_declaration {
        $$ = ALLOC(struct statement_node_t);
        TFRAG_COMBINE($$, $1);
        $$->ext_decl = $1;
    }
    | if_statement {
        $$ = ALLOC(struct statement_node_t);
        TFRAG_COMBINE($$, $1);
        $$->if_s = $1;
    }
    | label_declaration {
        $$ = ALLOC(struct statement_node_t);
        TFRAG_COMBINE($$, $1);
        $$->label = $1;
    }
    | goto_statement {
        $$ = ALLOC(struct statement_node_t);
        TFRAG_COMBINE($$, $1);
        $$->goto_s = $1;
    }
    | loop_statement {
        $$ = ALLOC(struct statement_node_t);
        TFRAG_COMBINE($$, $1);
        $$->loop_s = $1;
    }
    | break_statement {
        $$ = ALLOC(struct statement_node_t);
        TFRAG_COMBINE($$, $1);
        $$->break_s = $1;
    }
    | ret_statement {
        $$ = ALLOC(struct statement_node_t);
        TFRAG_COMBINE($$, $1);
        $$->ret_s = $1;
    }
    | avoid_block {
        $$ = ALLOC(struct statement_node_t);
        TFRAG_COMBINE($$, $1);
        $$->avoid = $1;
    }
    | expression ";" {
        $$ = ALLOC(struct statement_node_t);
        TFRAG_COMBINE($$, $1, $2);
        $$->expr = $1;
        $$->semicolon = $2;
    }
    | NASM_BLOCK {
        $$ = ALLOC(struct statement_node_t);
        TFRAG_COMBINE($$, $1);
        $$->nasm = $1;
    }
    ;

variable_declaration:
    NAME ":" memory_length {
        $$ = ALLOC(struct variable_declaration_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->name = $1;
        $$->colon = $2;
        $$->mem_len = $3;
    }
    | NAME ":" memory_length alignment {
        $$ = ALLOC(struct variable_declaration_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4);
        $$->name = $1;
        $$->colon = $2;
        $$->mem_len = $3;
        $$->align = $4;
    }
    ;

register_alias:
    NAME ":" ALIAS REG {
        $$ = ALLOC(struct register_alias_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4);
        $$->name = $1;
        $$->colon = $2;
        $$->alias = $3;
        $$->reg = $4;
    }
    | NAME ":" ALIAS GP_REGISTER {
        $$ = ALLOC(struct register_alias_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4);
        $$->name = $1;
        $$->colon = $2;
        $$->alias = $3;
        $$->reg = $4;
    }
    ;

if_statement:
    IF expression body {
        $$ = ALLOC(struct if_statement_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->kw = $1;
        $$->expr = $2;
        $$->body = $3;
    }
    | IF expression body ELSE body {
        $$ = ALLOC(struct if_statement_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4, $5);
        $$->kw = $1;
        $$->expr = $2;
        $$->body = $3;
        $$->else_kw = $4;
        $$->else_body = $5;
    }
    ;

label_declaration:
    NAME ":" {
        $$ = ALLOC(struct label_declaration_node_t);
        TFRAG_COMBINE($$, $1, $2);
        $$->name = $1;
        $$->colon = $2;
    }
    ;

goto_statement:
    GOTO NAME ";" {
        $$ = ALLOC(struct goto_statement_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->kw = $1;
        $$->name = $2;
        $$->semicolon = $3;
    }
    ;

loop_statement:
    LOOP body {
        $$ = ALLOC(struct loop_statement_node_t);
        TFRAG_COMBINE($$, $1, $2);
        $$->kw = $1;
        $$->body = $2;
    }
    ;

break_statement:
    BREAK ";" {
        $$ = ALLOC(struct break_statement_node_t);
        TFRAG_COMBINE($$, $1, $2);
        $$->kw = $1;
        $$->semicolon = $2;
    }
    | CONTINUE ";" {
        $$ = ALLOC(struct break_statement_node_t);
        TFRAG_COMBINE($$, $1, $2);
        $$->kw = $1;
        $$->semicolon = $2;
    }
    ;

ret_statement:
    RET expression ";" {
        $$ = ALLOC(struct ret_statement_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->kw = $1;
        $$->expr = $2;
        $$->semicolon = $3;
    }
    ;

avoid_block_regs:
    avoid_block_regs "," REGISTER {
        $$ = ALLOC(struct avoid_block_regs_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->rest = $1;
        $$->comma = $2;
        $$->reg = $3;
    }
    | avoid_block_regs "," GP_REGISTER {
        $$ = ALLOC(struct avoid_block_regs_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->rest = $1;
        $$->comma = $2;
        $$->reg = $3;
    }
    | REGISTER {
        $$ = ALLOC(struct avoid_block_regs_node_t);
        TFRAG_COMBINE($$, $1);
        $$->reg = $1;
    }
    | GP_REGISTER {
        $$ = ALLOC(struct avoid_block_regs_node_t);
        TFRAG_COMBINE($$, $1);
        $$->reg = $1;
    }
    ;

avoid_block:
    AVOID avoid_block_regs body {
        $$ = ALLOC(struct avoid_block_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->kw = $1;
        $$->regs = $2;
        $$->body = $3;
    }
    ;

expression:
    logical_or ASSIGN expression {
        $$ = ALLOC(struct expression_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->arg1 = $1;
        $$->op = $2;
        $$->arg2 = $3;
    }
    | logical_or {
        $$ = ALLOC(struct expression_node_t);
        TFRAG_COMBINE($$, $1);
        $$->other = $1;
    }
    ;

logical_or:
    logical_or LOGICAL_OR logical_and {
        $$ = ALLOC(struct logical_or_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->arg1 = $1;
        $$->op = $2;
        $$->arg2 = $3;
    }
    | logical_and {
        $$ = ALLOC(struct logical_or_node_t);
        TFRAG_COMBINE($$, $1);
        $$->other = $1;
    }
    ;

logical_and:
    logical_and LOGICAL_AND bitwise_or {
        $$ = ALLOC(struct logical_and_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->arg1 = $1;
        $$->op = $2;
        $$->arg2 = $3;
    }
    | bitwise_or {
        $$ = ALLOC(struct logical_and_node_t);
        TFRAG_COMBINE($$, $1);
        $$->other = $1;
    }
    ;

bitwise_or:
    bitwise_or BITWISE_OR bitwise_xor {
        $$ = ALLOC(struct bitwise_or_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->arg1 = $1;
        $$->op = $2;
        $$->arg2 = $3;
    }
    | bitwise_xor {
        $$ = ALLOC(struct bitwise_or_node_t);
        TFRAG_COMBINE($$, $1);
        $$->other = $1;
    }
    ;

bitwise_xor:
    bitwise_xor BITWISE_XOR bitwise_and {
        $$ = ALLOC(struct bitwise_xor_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->arg1 = $1;
        $$->op = $2;
        $$->arg2 = $3;
    }
    | bitwise_and {
        $$ = ALLOC(struct bitwise_xor_node_t);
        TFRAG_COMBINE($$, $1);
        $$->other = $1;
    }
    ;

bitwise_and:
    bitwise_and BITWISE_AND equality {
        $$ = ALLOC(struct bitwise_and_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->arg1 = $1;
        $$->op = $2;
        $$->arg2 = $3;
    }
    | equality {
        $$ = ALLOC(struct bitwise_and_node_t);
        TFRAG_COMBINE($$, $1);
        $$->other = $1;
    }
    ;

equality:
    equality EQUALS relational {
        $$ = ALLOC(struct equality_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->arg1 = $1;
        $$->op = $2;
        $$->arg2 = $3;
    }
    | equality NOT_EQUALS relational {
        $$ = ALLOC(struct equality_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->arg1 = $1;
        $$->op = $2;
        $$->arg2 = $3;
    }
    | relational {
        $$ = ALLOC(struct equality_node_t);
        TFRAG_COMBINE($$, $1);
        $$->other = $1;
    }
    ;

relational:
    relational LESS_THAN additive {
        $$ = ALLOC(struct relational_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->arg1 = $1;
        $$->op = $2;
        $$->arg2 = $3;
    }
    | relational GREATER_THAN additive {
        $$ = ALLOC(struct relational_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->arg1 = $1;
        $$->op = $2;
        $$->arg2 = $3;
    }
    | relational LESS_EQUAL additive {
        $$ = ALLOC(struct relational_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->arg1 = $1;
        $$->op = $2;
        $$->arg2 = $3;
    }
    | relational GREATER_EQUAL additive {
        $$ = ALLOC(struct relational_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->arg1 = $1;
        $$->op = $2;
        $$->arg2 = $3;
    }
    | additive {
        $$ = ALLOC(struct relational_node_t);
        TFRAG_COMBINE($$, $1);
        $$->other = $1;
    }
    ;

additive:
    additive PLUS multiplicative {
        $$ = ALLOC(struct additive_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->arg1 = $1;
        $$->op = $2;
        $$->arg2 = $3;
    }
    | additive MINUS multiplicative {
        $$ = ALLOC(struct additive_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->arg1 = $1;
        $$->op = $2;
        $$->arg2 = $3;
    }
    | multiplicative {
        $$ = ALLOC(struct additive_node_t);
        TFRAG_COMBINE($$, $1);
        $$->other = $1;
    }
    ;

multiplicative:
    multiplicative MULTIPLY tetriary {
        $$ = ALLOC(struct multiplicative_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->arg1 = $1;
        $$->op = $2;
        $$->arg2 = $3;
    }
    | multiplicative DIVIDE tetriary {
        $$ = ALLOC(struct multiplicative_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->arg1 = $1;
        $$->op = $2;
        $$->arg2 = $3;
    }
    | multiplicative REMAINDER tetriary {
        $$ = ALLOC(struct multiplicative_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->arg1 = $1;
        $$->op = $2;
        $$->arg2 = $3;
    }
    | tetriary {
        $$ = ALLOC(struct multiplicative_node_t);
        TFRAG_COMBINE($$, $1);
        $$->other = $1;
    }
    ;

prefix_op:
    INCREMENT tetriary {
        $$ = ALLOC(struct prefix_op_node_t);
        TFRAG_COMBINE($$, $1, $2);
        $$->op = $1;
        $$->arg = $2;
    }
    | DECREMENT tetriary {
        $$ = ALLOC(struct prefix_op_node_t);
        TFRAG_COMBINE($$, $1, $2);
        $$->op = $1;
        $$->arg = $2;
    }
    | LOGICAL_NOT tetriary {
        $$ = ALLOC(struct prefix_op_node_t);
        TFRAG_COMBINE($$, $1, $2);
        $$->op = $1;
        $$->arg = $2;
    }
    | BITWISE_NOT tetriary {
        $$ = ALLOC(struct prefix_op_node_t);
        TFRAG_COMBINE($$, $1, $2);
        $$->op = $1;
        $$->arg = $2;
    }
    ;

cast_op:
    tetriary CAST {
        $$ = ALLOC(struct cast_op_node_t);
        TFRAG_COMBINE($$, $1, $2);
        $$->arg = $1;
        $$->op = $2;
    }
    ;

address_op:
    "[" expression "]" tetriary {
        $$ = ALLOC(struct address_op_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4);
        $$->open_brace = $1;
        $$->offset = $2;
        $$->closed_brace = $3;
        $$->arg = $4;
    }
    | "[" "]" tetriary {
        $$ = ALLOC(struct address_op_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->open_brace = $1;
        $$->closed_brace = $2;
        $$->arg = $3;
    }
    ;

sizeof_op:
    SIZEOF NAME {
        $$ = ALLOC(struct sizeof_op_node_t);
        TFRAG_COMBINE($$, $1, $2);
        $$->kw = $1;
        $$->name = $2;
    }
    ;

tetriary:
    prefix_op {
        $$ = ALLOC(struct tetriary_node_t);
        TFRAG_COMBINE($$, $1);
        $$->prefix = $1;
    }
    | cast_op {
        $$ = ALLOC(struct tetriary_node_t);
        TFRAG_COMBINE($$, $1);
        $$->cast = $1;
    }
    | address_op {
        $$ = ALLOC(struct tetriary_node_t);
        TFRAG_COMBINE($$, $1);
        $$->address = $1;
    }
    | sizeof_op {
        $$ = ALLOC(struct tetriary_node_t);
        TFRAG_COMBINE($$, $1);
        $$->sizeof_op = $1;
    }
    | secondary {
        $$ = ALLOC(struct tetriary_node_t);
        TFRAG_COMBINE($$, $1);
        $$->secondary = $1;
    }
    ;

suffix_op:
    secondary INCREMENT {
        $$ = ALLOC(struct suffix_op_node_t);
        TFRAG_COMBINE($$, $1, $2);
        $$->arg = $1;
        $$->op = $2;
    }
    | secondary DECREMENT {
        $$ = ALLOC(struct suffix_op_node_t);
        TFRAG_COMBINE($$, $1, $2);
        $$->arg = $1;
        $$->op = $2;
    }
    ;

function_call_op_arg:
    expression {
        $$ = ALLOC(struct function_call_op_arg_node_t);
        TFRAG_COMBINE($$, $1);
        $$->arg = $1;
    }
    | expression ":" memory_length {
        $$ = ALLOC(struct function_call_op_arg_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->arg = $1;
        $$->colon = $2;
        $$->mem_len = $3;
    }
    | expression ":" alignment {
        $$ = ALLOC(struct function_call_op_arg_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->arg = $1;
        $$->colon = $2;
        $$->align = $3;
    }
    | expression ":" abi_class {
        $$ = ALLOC(struct function_call_op_arg_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->arg = $1;
        $$->colon = $2;
        $$->abi_class = $3;
    }
    | expression ":" memory_length alignment {
        $$ = ALLOC(struct function_call_op_arg_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4);
        $$->arg = $1;
        $$->colon = $2;
        $$->mem_len = $3;
        $$->align = $4;
    }
    | expression ":" memory_length abi_class {
        $$ = ALLOC(struct function_call_op_arg_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4);
        $$->arg = $1;
        $$->colon = $2;
        $$->mem_len = $3;
        $$->abi_class = $4;
    }
    | expression ":" alignment abi_class {
        $$ = ALLOC(struct function_call_op_arg_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4);
        $$->arg = $1;
        $$->colon = $2;
        $$->align = $3;
        $$->abi_class = $4;
    }
    | expression ":" memory_length alignment abi_class {
        $$ = ALLOC(struct function_call_op_arg_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4, $5);
        $$->arg = $1;
        $$->colon = $2;
        $$->mem_len = $3;
        $$->align = $4;
        $$->abi_class = $5;
    }
    ;

function_call_op_args:
    function_call_op_args "," function_call_op_arg {
        $$ = ALLOC(struct function_call_op_args_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->rest = $1;
        $$->comma = $2;
        $$->arg = $3;
    }
    | function_call_op_arg {
        $$ = ALLOC(struct function_call_op_args_node_t);
        TFRAG_COMBINE($$, $1);
        $$->arg = $1;
    }
    | {
        $$ = ALLOC(struct function_call_op_args_node_t);
    }
    ;

function_call_op:
    CALL expression "(" function_call_op_args ")" {
        $$ = ALLOC(struct function_call_op_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4, $5);
        $$->kw = $1;
        $$->fn = $2;
        $$->open_bracket = $3;
        $$->args = $4;
        $$->close_bracket = $5;
    }
    | CALL memory_length expression "(" function_call_op_args ")" {
        $$ = ALLOC(struct function_call_op_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4, $5, $6);
        $$->kw = $1;
        $$->mem_len = $2;
        $$->fn = $3;
        $$->open_bracket = $4;
        $$->args = $5;
        $$->close_bracket = $6;
    }
    | CALL abi_class expression "(" function_call_op_args ")" {
        $$ = ALLOC(struct function_call_op_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4, $5, $6);
        $$->kw = $1;
        $$->abi_class = $2;
        $$->fn = $3;
        $$->open_bracket = $4;
        $$->args = $5;
        $$->close_bracket = $6;
    }
    | CALL memory_length abi_class expression "(" function_call_op_args ")" {
        $$ = ALLOC(struct function_call_op_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4, $5, $6, $7);
        $$->kw = $1;
        $$->mem_len = $2;
        $$->abi_class = $3;
        $$->fn = $4;
        $$->open_bracket = $5;
        $$->args = $6;
        $$->close_bracket = $7;
    }

dereference_op:
    secondary "[" expression "]" {
        $$ = ALLOC(struct dereference_op_node_t);
        TFRAG_COMBINE($$, $1, $2, $3, $4);
        $$->arg = $1;
        $$->open_brace = $2;
        $$->offset = $3;
        $$->close_brace = $4;
    }
    | secondary "[" "]" {
        $$ = ALLOC(struct dereference_op_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->arg = $1;
        $$->open_brace = $2;
        $$->close_brace = $3;
    }
    ;

layout_access_op:
    secondary ACCESS NAME {
        $$ = ALLOC(struct layout_access_op_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->arg = $1;
        $$->op = $2;
        $$->field = $3;
    }
    ;

secondary:
    suffix_op {
        $$ = ALLOC(struct secondary_node_t);
        TFRAG_COMBINE($$, $1);
        $$->suffix = $1;
    }
    | function_call_op {
        $$ = ALLOC(struct secondary_node_t);
        TFRAG_COMBINE($$, $1);
        $$->fn_call = $1;
    }
    | dereference_op {
        $$ = ALLOC(struct secondary_node_t);
        TFRAG_COMBINE($$, $1);
        $$->deref = $1;
    }
    | layout_access_op {
        $$ = ALLOC(struct secondary_node_t);
        TFRAG_COMBINE($$, $1);
        $$->layout_access = $1;
    }
    | primary {
        $$ = ALLOC(struct secondary_node_t);
        TFRAG_COMBINE($$, $1);
        $$->primary = $1;
    }
    ;

primary:
    "(" expression ")" {
        $$ = ALLOC(struct primary_node_t);
        TFRAG_COMBINE($$, $1, $2, $3);
        $$->open_brace = $1;
        $$->expression = $2;
        $$->close_brace = $3;
    }
    | literal {
        $$ = ALLOC(struct primary_node_t);
        TFRAG_COMBINE($$, $1);
        $$->literal = $1;
    }
    ;

literal:
    INT { $$ = $1; }
    | UINT { $$ = $1; }
    | DOUBLE { $$ = $1; }
    | STRING { $$ = $1; }
    | NAME {
        $$ = ALLOC(struct literal_node_t);
        TFRAG_COMBINE($$, $1);
        $$->type = LIT_NAME;
        $$->name_lit = $1;
    }
    ;

%%
