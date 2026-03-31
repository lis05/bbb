#pragma once

#include "gen.h"
#include "cb.h"
#include "loc.h"
#include "fc.h"
#include "../parser/ast.h"

struct expr_gen_t {
    cb_t              cb;
    struct location_t loc;
};

struct expr_gen_t gen_expression(int indent, struct expression_node_t *node,
                                 struct function_context_t *fc);
struct expr_gen_t gen_logical_or(int indent, struct logical_or_node_t *node,
                                 struct function_context_t *fc);
struct expr_gen_t gen_logical_and(int indent, struct logical_and_node_t *node,
                                  struct function_context_t *fc);
struct expr_gen_t gen_bitwise_or(int indent, struct bitwise_or_node_t *node,
                                 struct function_context_t *fc);
struct expr_gen_t gen_bitwise_xor(int indent, struct bitwise_xor_node_t *node,
                                  struct function_context_t *fc);
struct expr_gen_t gen_bitwise_and(int indent, struct bitwise_and_node_t *node,
                                  struct function_context_t *fc);
struct expr_gen_t gen_equality(int indent, struct equality_node_t *node,
                               struct function_context_t *fc);
struct expr_gen_t gen_relational(int indent, struct relational_node_t *node,
                                 struct function_context_t *fc);
struct expr_gen_t gen_additive(int indent, struct additive_node_t *node,
                               struct function_context_t *fc);
struct expr_gen_t gen_multiplicative(int indent, struct multiplicative_node_t *node,
                                     struct function_context_t *fc);
struct expr_gen_t gen_prefix_op(int indent, struct prefix_op_node_t *node,
                                struct function_context_t *fc);
struct expr_gen_t gen_cast_op(int indent, struct cast_op_node_t *node,
                              struct function_context_t *fc);
struct expr_gen_t gen_address_op(int indent, struct address_op_node_t *node,
                                 struct function_context_t *fc);
struct expr_gen_t gen_sizeof_op(int indent, struct sizeof_op_node_t *node,
                                struct function_context_t *fc);
struct expr_gen_t gen_tetriary(int indent, struct tetriary_node_t *node,
                               struct function_context_t *fc);
struct expr_gen_t gen_suffix_op(int indent, struct suffix_op_node_t *node,
                                struct function_context_t *fc);
struct expr_gen_t gen_function_call_op_arg(int indent,
                                           struct function_call_op_arg_node_t *node,
                                           struct function_context_t          *fc);
struct expr_gen_t gen_function_call_op_args(
    int indent, struct function_call_op_args_node_t *node,
    struct function_context_t *fc);
struct expr_gen_t gen_function_call_op(int                             indent,
                                       struct function_call_op_node_t *node,
                                       struct function_context_t      *fc);
struct expr_gen_t gen_dereference_op(int indent, struct dereference_op_node_t *node,
                                     struct function_context_t *fc);
struct expr_gen_t gen_layout_access_op(int                             indent,
                                       struct layout_access_op_node_t *node,
                                       struct function_context_t      *fc);
struct expr_gen_t gen_secondary(int indent, struct secondary_node_t *node,
                                struct function_context_t *fc);
struct expr_gen_t gen_primary(int indent, struct primary_node_t *node,
                              struct function_context_t *fc);
struct expr_gen_t gen_literal(int indent, struct literal_node_t *node,
                              struct function_context_t *fc);
struct expr_gen_t gen_name(int indent, struct name_node_t *node,
                           struct function_context_t *fc);

#define gen_expr(indent, node, fc)                                        \
    _Generic((node),                                                      \
        struct expression_node_t *: gen_expression,                       \
        struct logical_or_node_t *: gen_logical_or,                       \
        struct logical_and_node_t *: gen_logical_and,                     \
        struct bitwise_or_node_t *: gen_bitwise_or,                       \
        struct bitwise_xor_node_t *: gen_bitwise_xor,                     \
        struct bitwise_and_node_t *: gen_bitwise_and,                     \
        struct equality_node_t *: gen_equality,                           \
        struct relational_node_t *: gen_relational,                       \
        struct additive_node_t *: gen_additive,                           \
        struct multiplicative_node_t *: gen_multiplicative,               \
        struct prefix_op_node_t *: gen_prefix_op,                         \
        struct cast_op_node_t *: gen_cast_op,                             \
        struct address_op_node_t *: gen_address_op,                       \
        struct sizeof_op_node_t *: gen_sizeof_op,                         \
        struct tetriary_node_t *: gen_tetriary,                           \
        struct suffix_op_node_t *: gen_suffix_op,                         \
        struct function_call_op_arg_node_t *: gen_function_call_op_arg,   \
        struct function_call_op_args_node_t *: gen_function_call_op_args, \
        struct function_call_op_node_t *: gen_function_call_op,           \
        struct dereference_op_node_t *: gen_dereference_op,               \
        struct layout_access_op_node_t *: gen_layout_access_op,           \
        struct secondary_node_t *: gen_secondary,                         \
        struct primary_node_t *: gen_primary,                             \
        struct literal_node_t *: gen_literal,                             \
        struct name_node_t *: gen_name)(indent, node, fc)

