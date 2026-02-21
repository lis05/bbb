%{
    #include "../common/common.h"
    extern int yylex();
    extern int yyparse();
    extern FILE *yyin;

    void yyerror(const char *s);
%}

%union {
    TODO;
}

%start program

%%

program:
    program global_variable_declaration {}
    | program layout_declaration {}
    | program extern declaration {}
    | program function_declaration {}
    | program nasm_block {}
    | {}

layout_sizeof:
    SIZEOF NAME {}

visibility:
    GLOBAL {}

memory_length:
    MEMORY_LENGTH_SIMPLE {}
    | 'm' '(' layout_sizeof ')' {}

alignment:
    ALIGNMENT_SIMPLE {}

global_variable_declaration:
    NAME ':' memory_length {}
    | NAME ':' visibility memory_length {}
    | NAME ':' memory_length alignment {}
    | NAME ':' visibility memory_length alignment {}

chunk_class:
    CHUNK_CLASS_MEM {}
    | CHUNK_CLASS_SSE {}
    | CHUNK_CLASS_INT {}

abi_class:
    chunk_class {}
    | CHUNK_CLASS_LAYOUT {}

layout_declaration_items:
    layout_declaration_items NAME ':' memory_length {}
    | NAME ':' memory_length {}

layout_declaration:
    NAME ':' LAYOUT '{' layout_declaration_items '}' {}
    | NAME ':' LAYOUT chunk_class '{' layout_declaration_items '}' {}
    | NAME ':' LAYOUT chunk_class chunk_class '{' layout_declaration_items '}' {}

extern_declaration:
    EXTERN NAME {}
    | NASM NAME {}

function_declaration_arg:
    NAME {} |
    | NAME ':' memory_length {}
    | NAME ':' alignment {}
    | NAME ':' abi_class {}
    | NAME ':' memory_length alignment {}
    | NAME ':' memory_length abi_class {}
    | NAME ':' alignment abi_class {}
    | NAME ':' memory_length alignment abi_class {}

function_declaration_args:
    function_declaration_args ',' function_declaration_arg {}
    | function_declaration_arg {}

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

nasm_block:
    NASM_BLOCK {}

body_list:
    body_list statement {}
    | {}

body:
    '{' body_list '}' {}

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

variable_declaration:
    NAME ':' memory_length {}
    | NAME ':' memory_length alignment {}

register_alias:
    NAME ':' ALIAS RES {}
    | NAME ':' ALIAS GP_REGISTER {}

if_statement:
    IF expression body {} |
    IF expression body ELSE body {}

label_declaration:
    NAME ':' {}

goto_statement:
    GOTO NAME ';' {}

loop_statement:
    LOOP BODY {}

break_statement:
    BREAK ';' {}
    | CONTINUE ';' {}

ret_statement:
    RET expression ';' {}

avoid_block_regs:
    avoid_block_regs ',' REGISTER {}
    | REGISTER {}

avoid_block:
    AVOID avoid_block_regs body {}



%%
