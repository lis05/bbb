%{
    #include "../common/common.h"
    extern int yylex();
    extern int yyparse();
    extern FILE *yyin;

    void yyerror(const char *s);
%}

%union {
    ast_node_t *node;
}

%start program

%token <node> NAME
%token <node> INT
%token <node> UINT
%token <node> DOUBLE
%token <node> STRING
%token <node> MEMORY_LENGTH_SIMPLE
%token <node> MEMORY_LENGTH_PREFIX 'm'
%token <node> ALIGNMENT_SIMPLE
%token <node> TYPE
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
%token <node> RES

%token <node> LOGICAL_OR
%token <node> LOGICAL_AND
%token <node> ASSIGN "="
%token <node> INCREMENT
%token <node> DECREMENT
%token <node> SIZEOF
%token <node> PLUS "+"
%token <node> MINUS "-"
%token <node> MULTIPLY "*"
%token <node> DIVIDE "/"
%token <node> REMAINDER "%"
%token <node> BITWISE_AND "&"
%token <node> BITWISE_OR "|"
%token <node> BITWISE_XOR "^"
%token <node> LOGICAL_NOT "!"
%token <node> BITWISE_NOT "~"
%token <node> LESS_THEN "<"
%token <node> GREATER_THEN ">"
%token <node> LESS_EQUAL
%token <node> GREATER_EQUAL
%token <node> EQUALS
%token <node> NOT_EQUALS

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
%token <node> DOT "."

%type <node> program
%type <node> visibility
%type <node> memory_length
%type <node> alignment
%type <node> global_variable_declaration
%type <node> chunk_class
%type <node> abi_class
%type <node> layout_declaration_items
%type <node> layout_declaration
%type <node> extern_declaration
%type <node> function_declaration_arg
%type <node> function_declaration_args
%type <node> function_declaration
%type <node> nasm_block
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
%type <node> operand_memory_length
%type <node> operand_type
%type <node> assignment
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
    NAME {} |
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
    NAME ':' ALIAS RES {}
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
    assignment {}
    ;

operand_memory_length:
    memory_length {}
    | {}
    ;

operand_type:
    TYPE {}
    | memory_length {}
    | {}
    ;

assignment:
    logical_or operand_type '=' operand_type assignment {}
    | logical_or {}
    ;

logical_or:
    logical_or operand_type LOGICAL_OR operand_type logical_and {}
    | logical_and {}
    ;

logical_and:
    logical_and operand_type LOGICAL_AND operand_type bitwise_or {}
    | bitwise_or {}
    ;

bitwise_or:
    bitwise_or operand_type '|' operand_type bitwise_xor {}
    | bitwise_xor {}
    ;

bitwise_xor:
    bitwise_xor operand_type '^' operand_type bitwise_and {}
    | bitwise_and {}
    ;

bitwise_and:
    bitwise_and operand_type '&' operand_type equality {}
    | equality {}
    ;

equality:
    equality operand_type EQUALS operand_type relational {}
    | equality operand_type NOT_EQUALS operand_type relational {}
    | relational {}
    ;

relational:
    relational operand_type '<' operand_type additive {}
    | relational operand_type '>' operand_type additive {}
    | relational operand_type LESS_EQUAL operand_type additive {}
    | relational operand_type GREATER_EQUAL operand_type additive {}
    | additive {}
    ;

additive:
    additive operand_type '+' operand_type multiplicative {}
    | additive operand_type '-' operand_type multiplicative {}
    | multiplicative {}
    ;

multiplicative:
    multiplicative operand_type '*' operand_type tetriary {}
    | multiplicative operand_type '/' operand_type tetriary {}
    | multiplicative operand_type '%' operand_type tetriary {}
    | tetriary {}
    ;

tetriary:
    INCREMENT operand_type tetriary {}
    | DECREMENT operand_type tetriary {}
    | '!' operand_type tetriary {}
    | '~' operand_type tetriary {}
    | tetriary operand_type '?' operand_type {}
    | '[' expression ']' tetriary {}
    | '[' ']' tetriary {}
    | SIZEOF NAME {}
    | secondary {}
    ;

secondary:
    secondary operand_type INCREMENT {}
    | secondary operand_type DECREMENT {}
    | secondary '[' expression ']' {}
    | secondary '[' ']' {}
    | secondary NAME '.' NAME {}
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
