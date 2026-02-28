%{
    #include "../common/common.h"
    #include "ast.h"
    extern int yylex();
    extern int yyparse();
    extern FILE *yyin;

    void yyerror(const char *s);
%}

%union {
    struct program_node_t *program;
    struct global_variable_declaration_node_t *global_variable_declaration;
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
    struct dereference_op_node_t *dereference_op;
    struct layout_access_op_node_t *layout_access_op;
    struct secondary_node_t *secondary;
    struct primary_node_t *primary;
    struct literal_node_t *literal;
    struct name_node_t *name;
}

%start program

%token <node> NAME
%token <node> INT
%token <node> UINT
%token <node> DOUBLE
%token <node> STRING
%token <node> MEMORY_LENGTH_SIMPLE
%token <node> MEMORY_LENGTH_PREFIX
%token <node> ALIGNMENT_SIMPLE
%token <node> CHUNK_CLASS_MEM
%token <node> CHUNK_CLASS_SSE
%token <node> CHUNK_CLASS_INT
%token <node> CHUNK_CLASS_LAYOUT
%token <node> GP_REGISTER
%token <node> REGISTER
%token <node> GLOBAL
%token <node> LAYOUT
%token <node> EXTERN
%token <node> NASM
%token <node> FN
%token <node> NASM_BLOCK
%token <node> IF
%token <node> ELSE
%token <node> GOTO
%token <node> LOOP
%token <node> BREAK
%token <node> CONTINUE
%token <node> RET
%token <node> AVOID
%token <node> ALIAS
%token <node> REG

%token <node> LOGICAL_OR
%token <node> LOGICAL_AND
%token <node> ASSIGN
%token <node> INCREMENT
%token <node> DECREMENT
%token <node> SIZEOF
%token <node> PLUS
%token <node> MINUS
%token <node> MULTIPLY
%token <node> DIVIDE
%token <node> REMAINDER
%token <node> BITWISE_AND
%token <node> BITWISE_OR
%token <node> BITWISE_XOR
%token <node> LOGICAL_NOT
%token <node> BITWISE_NOT
%token <node> LESS_THAN
%token <node> GREATER_THAN
%token <node> LESS_EQUAL
%token <node> GREATER_EQUAL
%token <node> EQUALS
%token <node> NOT_EQUALS
%token <node> CAST
%token <node> ACCESS

%token <node> ROB "("
%token <node> RCB ")"
%token <node> SOB "["
%token <node> SCB "]"
%token <node> COB "{"
%token <node> CCB "}"
%token <node> ARROW
%token <node> COLON ":"
%token <node> SEMICOLON ";"
%token <node> COMMA ","

%type <node> program
%type <node> global_variable_declaration
%type <node> layout_declaration_items
%type <node> layout_declaration
%type <node> extern_declaration
%type <node> function_declaration_arg
%type <node> function_declaration_args
%type <node> function_declaration
%type <node> body_list
%type <node> body
%type <node> statement
%type <node> variable_declaration
%type <node> register_alias
%type <node> if_statement
%type <node> label_declaration
%type <node> goto_statement
%type <node> loop_statement
%type <node> break_statement
%type <node> ret_statement
%type <node> avoid_block_regs
%type <node> avoid_block

%type <node> expression
%type <node> logical_or
%type <node> logical_and
%type <node> bitwise_or
%type <node> bitwise_xor
%type <node> bitwise_and
%type <node> equality
%type <node> relational
%type <node> additive
%type <node> multiplicative
%type <node> tetriary
%type <node> secondary
%type <node> primary
%type <node> literal

%%

program:
    program global_variable_declaration {}
    | program layout_declaration {}
    | program extern_declaration {}
    | program function_declaration {}
    | program nasm_block {}
    | {}
    ;

visibility:
    GLOBAL {}
    ;

memory_length:
    MEMORY_LENGTH_SIMPLE {}
    | MEMORY_LENGTH_PREFIX '(' SIZEOF NAME ')' {}
    ;

alignment:
    ALIGNMENT_SIMPLE {}
    ;

global_variable_declaration:
    NAME ':' memory_length {}
    | NAME ':' visibility memory_length {}
    | NAME ':' memory_length alignment {}
    | NAME ':' visibility memory_length alignment {}
    ;

chunk_class:
    CHUNK_CLASS_MEM {}
    | CHUNK_CLASS_SSE {}
    | CHUNK_CLASS_INT {}
    ;

abi_class:
    chunk_class {}
    | CHUNK_CLASS_LAYOUT {}
    ;

layout_declaration_items:
    layout_declaration_items NAME ':' memory_length {}
    | NAME ':' memory_length {}
    ;

layout_declaration:
    NAME ':' LAYOUT '{' layout_declaration_items '}' {}
    | NAME ':' LAYOUT chunk_class '{' layout_declaration_items '}' {}
    | NAME ':' LAYOUT chunk_class chunk_class '{' layout_declaration_items '}' {}
    ;

extern_declaration:
    EXTERN NAME {}
    | NASM NAME {}
    ;

function_declaration_arg:
    NAME {}
    | NAME ':' memory_length {}
    | NAME ':' alignment {}
    | NAME ':' abi_class {}
    | NAME ':' memory_length alignment {}
    | NAME ':' memory_length abi_class {}
    | NAME ':' alignment abi_class {}
    | NAME ':' memory_length alignment abi_class {}
    ;

function_declaration_args:
    function_declaration_args ',' function_declaration_arg {}
    | function_declaration_arg {}
    ;

function_declaration:
    NAME ':' FN '(' function_declaration_args ')' body {}
    | NAME ':' FN '(' function_declaration_args ')' ARROW memory_length body {}
    | NAME ':' FN '(' function_declaration_args ')' ARROW abi_class body {}
    | NAME ':' FN '(' function_declaration_args ')' ARROW memory_length abi_class body {}
    | NAME ':' visibility FN '(' function_declaration_args ')' body {}
    | NAME ':' visibility FN '(' function_declaration_args ')' ARROW memory_length body {}
    | NAME ':' visibility FN '(' function_declaration_args ')' ARROW abi_class body {}
    | NAME ':' visibility FN '(' function_declaration_args ')' ARROW memory_length
abi_class body {}
    ;

nasm_block:
    NASM_BLOCK {}
    ;

body_list:
    body_list statement {}
    | {}
    ;

body:
    '{' body_list '}' {}
    ;

statement:
    variable_declaration {}
    | register_alias {}
    | extern_declaration {}
    | if_statement {}
    | label_declaration {}
    | goto_statement {}
    | loop_statement {}
    | break_statement {}
    | ret_statement {}
    | avoid_block {}
    | expression ';' {}
    | nasm_block {}
    ;

variable_declaration:
    NAME ':' memory_length {}
    | NAME ':' memory_length alignment {}
    ;

register_alias:
    NAME ':' ALIAS REG {}
    | NAME ':' ALIAS GP_REGISTER {}
    ;

if_statement:
    IF expression body {} |
    IF expression body ELSE body {}
    ;

label_declaration:
    NAME ':' {}
    ;

goto_statement:
    GOTO NAME ';' {}
    ;

loop_statement:
    LOOP body {}
    ;

break_statement:
    BREAK ';' {}
    | CONTINUE ';' {}
    ;

ret_statement:
    RET expression ';' {}
    ;

avoid_block_regs:
    avoid_block_regs ',' REGISTER {}
    | REGISTER {}
    ;

avoid_block:
    AVOID avoid_block_regs body {}
    ;

expression:
    logical_or ASSIGN expression {}
    | logical_or {}
    ;

logical_or:
    logical_or LOGICAL_OR logical_and {}
    | logical_and {}
    ;

logical_and:
    logical_and LOGICAL_AND bitwise_or {}
    | bitwise_or {}
    ;

bitwise_or:
    bitwise_or BITWISE_OR bitwise_xor {}
    | bitwise_xor {}
    ;

bitwise_xor:
    bitwise_xor BITWISE_XOR bitwise_and {}
    | bitwise_and {}
    ;

bitwise_and:
    bitwise_and BITWISE_AND equality {}
    | equality {}
    ;

equality:
    equality EQUALS relational {}
    | equality NOT_EQUALS relational {}
    | relational {}
    ;

relational:
    relational LESS_THAN additive {}
    | relational GREATER_THAN additive {}
    | relational LESS_EQUAL additive {}
    | relational GREATER_EQUAL additive {}
    | additive {}
    ;

additive:
    additive PLUS multiplicative {}
    | additive MINUS multiplicative {}
    | multiplicative {}
    ;

multiplicative:
    multiplicative MULTIPLY tetriary {}
    | multiplicative DIVIDE tetriary {}
    | multiplicative REMAINDER tetriary {}
    | tetriary {}
    ;

prefix_op:
    INCREMENT tetriary {}
    | DECREMENT tetriary {}
    | LOGICAL_NOT tetriary {}
    | BITWISE_NOT tetriary {}
    ;

cast_op:
    tetriary CAST {}
    ;

address_op:
    '[' expression ']' tetriary {}
    | '[' ']' tetriary {}
    ;

sizeof_op:
    SIZEOF NAME {}
    ;

tetriary:
    prefix_op {}
    | cast_op {}
    | address_op {}
    | sizeof_op {}
    | secondary {}
    ;

suffix_op:
    secondary INCREMENT {}
    | secondary DECREMENT {}
    ;

dereference_op:
    secondary '[' expression ']' {}
    | secondary '[' ']' {}
    ;

layout_access_op:
    secondary ACCESS NAME {}
    ;

secondary:
    suffix_op {}
    | dereference_op {}
    | layout_access_op {}
    | primary {}
    ;

primary:
    '(' expression ')' {}
    | literal {}
    ;

literal:
    INT {}
    | UINT {}
    | DOUBLE {}
    | STRING {}
    | NAME {}
    ;







%%
