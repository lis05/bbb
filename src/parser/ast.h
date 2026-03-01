#pragma once

#include "tfrag.h"

struct program_node_t;
struct global_variable_declaration_node_t;
struct layout_declaration_items_node_t;
struct layout_declaration_node_t;
struct extern_declaration_node_t;
struct function_declaration_arg_node_t;
struct function_declaration_args_node_t;
struct function_declaration_node_t;
struct body_list_node_t;
struct body_node_t;
struct statement_node_t;
struct variable_declaration_node_t;
struct register_alias_node_t;
struct if_statement_node_t;
struct label_declaration_node_t;
struct goto_statement_node_t;
struct loop_statement_node_t;
struct break_statement_node_t;
struct ret_statement_node_t;
struct avoid_block_regs_node_t;
struct avoid_block_node_t;
struct expression_node_t;
struct logical_or_node_t;
struct logical_and_node_t;
struct bitwise_or_node_t;
struct bitwise_xor_node_t;
struct bitwise_and_node_t;
struct equality_node_t;
struct relational_node_t;
struct additive_node_t;
struct multiplicative_node_t;
struct prefix_op_node_t;
struct cast_op_node_t;
struct address_op_node_t;
struct sizeof_op_node_t;
struct tetriary_node_t;
struct suffix_op_node_t;
struct dereference_op_node_t;
struct layout_access_op_node_t;
struct secondary_node_t;
struct primary_node_t;
struct literal_node_t;
struct name_node_t;

struct program_node_t {
    tfrag_t                                    frag;
    struct program_node_t                     *rest;
    struct global_variable_declaration_node_t *gvar_decl;
    struct layout_declaration_node_t          *layout_decl;
    struct extern_declaration_node_t          *ext_decl;
    struct function_declaration_node_t        *fn_decl;
    struct name_node_t                        *nasm_b;
};

struct global_variable_declaration_node_t {
    tfrag_t             frag;
    struct name_node_t *name;
    struct name_node_t *colon;
    struct name_node_t *vis;
    struct name_node_t *mem_len;
    struct name_node_t *align;
};

struct layout_declaration_items_node_t {
    tfrag_t                                 frag;
    struct layout_declaration_items_node_t *rest;
    struct name_node_t                     *name;
    struct name_node_t                     *colon;
    struct name_node_t                     *mem_len;
};

struct layout_declaration_node_t {
    tfrag_t                                 frag;
    struct name_node_t                     *name;
    struct name_node_t                     *colon;
    struct name_node_t                     *layout;
    struct name_node_t                     *chunk1;
    struct name_node_t                     *chunk2;
    struct name_node_t                     *open_brace;
    struct layout_declaration_items_node_t *items;
    struct name_node_t                     *closed_brace;
};

struct extern_declaration_node_t {
    tfrag_t             frag;
    struct name_node_t *kw;
    struct name_node_t *name;
};

struct function_declaration_arg_node_t {
    tfrag_t             frag;
    struct name_node_t *name;
    struct name_node_t *colon;
    struct name_node_t *mem_len;
    struct name_node_t *align;
    struct name_node_t *abi_class;
};

struct function_declaration_args_node_t {
    tfrag_t                                  frag;
    struct function_declaration_args_node_t *rest;
    struct name_node_t                      *comma;
    struct function_declaration_arg_node_t  *arg;
};

struct function_declaration_node_t {
    tfrag_t                                 frag;
    struct name_node_t                     *name;
    struct name_node_t                     *colon;
    struct name_node_t                     *fn;
    struct name_node_t                     *open_brace;
    struct function_declarations_args_node *args;
    struct name_node_t                     *closed_brace;
    struct name_node_t                     *arrow;
    struct name_node_t                     *mem_len;
    struct name_node_t                     *abi_class;
    struct body_node_t                     *body;
};

struct body_list_node_t {
    tfrag_t                  frag;
    struct body_list_node_t *rest;
    struct statement_node_t *s;
};

struct body_node_t {
    tfrag_t                  frag;
    struct name_node_t      *open_brace;
    struct body_list_node_t *list;
    struct name_node_t      *closed_brace;
};

// this should use enum. but fuck you, i can do what i want
struct statement_node_t {
    tfrag_t                             frag;
    struct variable_declaration_node_t *vdecl;
    struct register_alias_node_t       *alias;
    struct extern_declaration_node_t   *ext_decl;
    struct if_statement_node_t         *if_s;
    struct label_declaration_node_t    *label;
    struct goto_statement_node_t       *goto_s;
    struct loop_statement_node_t       *loop_s;
    struct break_statement_node_t      *break_s;
    struct ret_statement_node_t        *ret_s;
    struct expression_node_t           *expr;
    struct name_node_t                 *semicolon;
    struct name_node_t                 *nasm;
};

struct variable_declaration_node_t {
    tfrag_t             frag;
    struct name_node_t *name;
    struct name_node_t *colon;
    struct name_node_t *mem_len;
    struct name_node_t *align;
};

struct register_alias_node_t {
    tfrag_t              frag;
    struct name_node_t  *name;
    struct name_node_t  *colon;
    struct namde_node_t *alias;
    struct name_node_t  *reg;
};

struct if_statement_node_t {
    tfrag_t                   frag;
    struct name_node_t       *kw;
    struct expression_node_t *expr;
    struct body_node_t       *body;
    struct name_node_t       *else_kw;
    struct body_node_t       *else_body;
};

struct label_declaration_node_t {
    tfrag_t             frag;
    struct name_node_t *name;
    struct name_node_t *colon;
};

struct goto_statement_node_t {
    tfrag_t             frag;
    struct name_node_t *kw;
    struct name_node_t *name;
    struct name_node_t *semicolon;
};

struct loop_statement_node_t {
    tfrag_t             frag;
    struct name_node_t *kw;
    struct body_node_t *body;
};

struct break_statement_node_t {
    tfrag_t             frag;
    struct name_node_t *kw;
    struct name_node_t *semicolon;
};

struct ret_statement_node_t {
    tfrag_t                   frag;
    struct name_node_t       *kw;
    struct expression_node_t *expr;
    struct name_node_t       *semicolon;
};

struct avoid_block_regs_node_t {
    tfrag_t                         frag;
    struct avoid_block_regs_node_t *rest;
    struct name_node_t             *comma;
    struct name_node_t             *reg;
};

struct avoid_block_node_t {
    tfrag_t                         frag;
    struct name_node_t             *kw;
    struct avoid_block_regs_node_t *regs;
    struct body_node_t             *body;
};

struct expression_node_t {
    tfrag_t                   frag;
    struct logical_or_node_t *arg1;
    struct name_node_t       *op;
    struct expression_node_t *arg2;
    struct logical_or_node_t *other;
};

struct logical_or_node_t {
    tfrag_t                    frag;
    struct logical_or_node_t  *arg1;
    struct name_node_t        *op;
    struct logical_and_node_t *arg2;
    struct logical_and_node_t *other;
};

struct logical_and_node_t {
    tfrag_t                    frag;
    struct logical_and_node_t *arg1;
    struct name_node_t        *op;
    struct bitwise_or_node_t  *arg2;
    struct bitwise_or_node_t  *other;
};

struct bitwise_or_node_t {
    tfrag_t                    frag;
    struct bitwise_or_node_t  *arg1;
    struct name_node_t        *op;
    struct bitwise_xor_node_t *arg2;
    struct bitwise_xor_node_t *other;
};

struct bitwise_xor_node_t {
    tfrag_t                    frag;
    struct bitwise_xor_node_t *arg1;
    struct name_node_t        *op;
    struct bitwise_and_node_t *arg2;
    struct bitwise_and_node_t *other;
};

struct bitwise_and_node_t {
    tfrag_t                    frag;
    struct bitwise_and_node_t *arg1;
    struct name_node_t        *op;
    struct equality_node_t    *arg2;
    struct equality_node_t    *other;
};

struct equality_node_t {
    tfrag_t                   frag;
    struct equality_node_t   *arg1;
    struct name_node_t       *op;
    struct relational_node_t *arg2;
    struct relational_node_t *other;
};

struct relational_node_t {
    tfrag_t                   frag;
    struct relational_node_t *arg1;
    struct name_node_t       *op;
    struct additive_node_t   *arg2;
    struct additive_node_t   *other;
};

struct additive_node_t {
    tfrag_t                       frag;
    struct additive_node_t       *arg1;
    struct name_node_t           *op;
    struct multuplicative_node_t *arg2;
    struct multuplicative_node_t *other;
};

struct multiplicative_node_t {
    tfrag_t                       frag;
    struct multiplicative_node_t *arg1;
    struct name_node_t           *op;
    struct tetriary_node_t       *arg2;
    struct tetriary_node_t       *other;
};

struct prefix_op_node_t {
    tfrag_t                 frag;
    struct name_node_t     *op;
    struct tetriary_node_t *arg;
};

struct cast_op_node_t {
    tfrag_t                 frag;
    struct tetriary_node_t *arg;
    struct name_node_t     *op;
};

struct address_op_node_t {
    tfrag_t                   frag;
    struct name_node_t       *open_brace;
    struct expression_node_t *offset;
    struct name_node_t       *closed_brace;
    struct tetriary_node_t   *arg;
};

struct sizeof_op_node_t {
    tfrag_t             frag;
    struct name_node_t *kw;
    struct name_node_t *name;
};

struct tetriary_node_t {
    tfrag_t                   frag;
    struct prefix_op_node_t  *prefix;
    struct cast_op_node_t    *cast;
    struct address_op_node_t *address;
    struct sizeof_op_node_t  *sizeof_op;
    struct secondary_node_t  *secondary;
};

struct suffix_op_node_t {
    tfrag_t                  frag;
    struct secondary_node_t *arg;
    struct name_node_t      *op;
};

struct dereference_op_node_t {
    tfrag_t                   frag;
    struct secondary_node_t  *arg;
    struct name_node_t       *open_brace;
    struct expression_node_t *offset;
    struct name_node_t       *close_brace;
};

struct layout_access_op_node_t {
    tfrag_t                  frag;
    struct secondary_node_t *arg;
    struct name_node_t      *op;
    struct name_node_t      *field;
};

struct secondary_node_t {
    tfrag_t                         frag;
    struct suffix_op_node_t        *suffix;
    struct dereference_op_node_t   *deref;
    struct layout_access_op_node_t *layout_access;
    struct primary_node_t          *primary;
};

struct primary_node_t {
    tfrag_t                   frag;
    struct name_node_t       *open_brace;
    struct expression_node_t *expression;
    struct name_node_t       *close_brace;
    struct literal_node_t    *literal;
};

// o
enum literal_type {
    LIT_INT = 0,
    LIT_UINT,
    LIT_DOUBLE,
    LIT_STRING,
    LIT_NAME
};

struct literal_node_t {
    tfrag_t           frag;
    enum literal_type type;
    union {
        int64_t     int_lit;
        uint64_t    uint_lit;
        double      double_lit;
        const char *string_lit;
        const char *name_lit;
    };
};

struct name_node_t {
    tfrag_t     frag;
    const char *name;
};
