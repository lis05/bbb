#include "ast.h"

#include <inttypes.h>
#include <stdio.h>

static void p_ind(int indent) {
    for (int i = 0; i < indent; i++) printf("  ");
}

static void p_frag(tfrag_t frag) {
    if (frag.begin_line == 0 && frag.end_line == 0)
        return;
    printf(" <%" PRIu64 ":%" PRIu64 "-%" PRIu64 ":%" PRIu64 ">", frag.begin_line,
           frag.begin_col, frag.end_line, frag.end_col);
}

#define CHECK_PTR(node, field) \
    if (node->field)           \
        printf(" " #field);
#define RECURSE(node, field, func) \
    if (node->field)               \
        func(node->field, indent + 1);

void ast_print_name_node(struct name_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[NAME");
    p_frag(node->frag);
    printf("]: \"%s\"\n", node->name ? node->name : "NULL");
}

void ast_print_program_node(struct program_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[PROGRAM");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, rest);
    CHECK_PTR(node, gvar_decl);
    CHECK_PTR(node, layout_decl);
    CHECK_PTR(node, ext_decl);
    CHECK_PTR(node, fn_decl);
    CHECK_PTR(node, nasm_b);
    printf("]\n");
    RECURSE(node, rest, ast_print_program_node);
    RECURSE(node, gvar_decl, ast_print_global_variable_declaration_node);
    RECURSE(node, layout_decl, ast_print_layout_declaration_node);
    RECURSE(node, ext_decl, ast_print_extern_declaration_node);
    RECURSE(node, fn_decl, ast_print_function_declaration_node);
    RECURSE(node, nasm_b, ast_print_name_node);
}

void ast_print_global_variable_declaration_node(
    struct global_variable_declaration_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[GVAR_DECL");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, name);
    CHECK_PTR(node, colon);
    CHECK_PTR(node, vis);
    CHECK_PTR(node, mem_len);
    CHECK_PTR(node, align);
    printf("]\n");
    RECURSE(node, name, ast_print_name_node);
    RECURSE(node, colon, ast_print_name_node);
    RECURSE(node, vis, ast_print_name_node);
    RECURSE(node, mem_len, ast_print_name_node);
    RECURSE(node, align, ast_print_name_node);
}

void ast_print_abi_class_node(struct abi_class_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[ABI_CLASS");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, chunk1);
    CHECK_PTR(node, chunk2);
    CHECK_PTR(node, layout);
    printf("]\n");
    RECURSE(node, chunk1, ast_print_name_node);
    RECURSE(node, chunk2, ast_print_name_node);
    RECURSE(node, layout, ast_print_name_node);
}

void ast_print_layout_declaration_items_node(
    struct layout_declaration_items_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[LAYOUT_ITEMS");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, rest);
    CHECK_PTR(node, name);
    CHECK_PTR(node, colon);
    CHECK_PTR(node, mem_len);
    printf("]\n");
    RECURSE(node, rest, ast_print_layout_declaration_items_node);
    RECURSE(node, name, ast_print_name_node);
    RECURSE(node, colon, ast_print_name_node);
    RECURSE(node, mem_len, ast_print_name_node);
}

void ast_print_layout_declaration_node(struct layout_declaration_node_t *node,
                                       int                               indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[LAYOUT_DECL");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, name);
    CHECK_PTR(node, colon);
    CHECK_PTR(node, layout);
    CHECK_PTR(node, chunk1);
    CHECK_PTR(node, chunk2);
    CHECK_PTR(node, open_brace);
    CHECK_PTR(node, items);
    CHECK_PTR(node, closed_brace);
    printf("]\n");
    RECURSE(node, name, ast_print_name_node);
    RECURSE(node, colon, ast_print_name_node);
    RECURSE(node, layout, ast_print_name_node);
    RECURSE(node, chunk1, ast_print_name_node);
    RECURSE(node, chunk2, ast_print_name_node);
    RECURSE(node, open_brace, ast_print_name_node);
    RECURSE(node, items, ast_print_layout_declaration_items_node);
    RECURSE(node, closed_brace, ast_print_name_node);
}

void ast_print_extern_declaration_node(struct extern_declaration_node_t *node,
                                       int                               indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[EXTERN_DECL");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, kw);
    CHECK_PTR(node, name);
    printf("]\n");
    RECURSE(node, kw, ast_print_name_node);
    RECURSE(node, name, ast_print_name_node);
}

void ast_print_function_declaration_arg_node(
    struct function_declaration_arg_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[FN_ARG");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, name);
    CHECK_PTR(node, colon);
    CHECK_PTR(node, mem_len);
    CHECK_PTR(node, align);
    CHECK_PTR(node, abi_class);
    printf("]\n");
    RECURSE(node, name, ast_print_name_node);
    RECURSE(node, colon, ast_print_name_node);
    RECURSE(node, mem_len, ast_print_name_node);
    RECURSE(node, align, ast_print_name_node);
    RECURSE(node, abi_class, ast_print_abi_class_node);
}

void ast_print_function_declaration_args_node(
    struct function_declaration_args_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[FN_ARGS_LIST");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, rest);
    CHECK_PTR(node, comma);
    CHECK_PTR(node, arg);
    printf("]\n");
    RECURSE(node, rest, ast_print_function_declaration_args_node);
    RECURSE(node, comma, ast_print_name_node);
    RECURSE(node, arg, ast_print_function_declaration_arg_node);
}

void ast_print_function_declaration_node(struct function_declaration_node_t *node,
                                         int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[FN_DECL");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, name);
    CHECK_PTR(node, colon);
    CHECK_PTR(node, vis);
    CHECK_PTR(node, fn);
    CHECK_PTR(node, open_brace);
    CHECK_PTR(node, args);
    CHECK_PTR(node, closed_brace);
    CHECK_PTR(node, arrow);
    CHECK_PTR(node, mem_len);
    CHECK_PTR(node, abi_class);
    CHECK_PTR(node, body);
    printf("]\n");
    RECURSE(node, name, ast_print_name_node);
    RECURSE(node, colon, ast_print_name_node);
    RECURSE(node, vis, ast_print_name_node);
    RECURSE(node, fn, ast_print_name_node);
    RECURSE(node, open_brace, ast_print_name_node);
    RECURSE(node, args, ast_print_function_declaration_args_node);
    RECURSE(node, closed_brace, ast_print_name_node);
    RECURSE(node, arrow, ast_print_name_node);
    RECURSE(node, mem_len, ast_print_name_node);
    RECURSE(node, abi_class, ast_print_abi_class_node);
    RECURSE(node, body, ast_print_body_node);
}

void ast_print_body_list_node(struct body_list_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[BODY_LIST");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, rest);
    CHECK_PTR(node, s);
    printf("]\n");
    RECURSE(node, rest, ast_print_body_list_node);
    RECURSE(node, s, ast_print_statement_node);
}

void ast_print_body_node(struct body_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[BODY");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, open_brace);
    CHECK_PTR(node, list);
    CHECK_PTR(node, closed_brace);
    printf("]\n");
    RECURSE(node, open_brace, ast_print_name_node);
    RECURSE(node, list, ast_print_body_list_node);
    RECURSE(node, closed_brace, ast_print_name_node);
}

void ast_print_statement_node(struct statement_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[STATEMENT");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, vdecl);
    CHECK_PTR(node, alias);
    CHECK_PTR(node, ext_decl);
    CHECK_PTR(node, if_s);
    CHECK_PTR(node, label);
    CHECK_PTR(node, goto_s);
    CHECK_PTR(node, loop_s);
    CHECK_PTR(node, break_s);
    CHECK_PTR(node, ret_s);
    CHECK_PTR(node, avoid);
    CHECK_PTR(node, expr);
    CHECK_PTR(node, semicolon);
    CHECK_PTR(node, nasm);
    printf("]\n");
    RECURSE(node, vdecl, ast_print_variable_declaration_node);
    RECURSE(node, alias, ast_print_register_alias_node);
    RECURSE(node, ext_decl, ast_print_extern_declaration_node);
    RECURSE(node, if_s, ast_print_if_statement_node);
    RECURSE(node, label, ast_print_label_declaration_node);
    RECURSE(node, goto_s, ast_print_goto_statement_node);
    RECURSE(node, loop_s, ast_print_loop_statement_node);
    RECURSE(node, break_s, ast_print_break_statement_node);
    RECURSE(node, ret_s, ast_print_ret_statement_node);
    RECURSE(node, avoid, ast_print_avoid_block_node);
    RECURSE(node, expr, ast_print_expression_node);
    RECURSE(node, semicolon, ast_print_name_node);
    RECURSE(node, nasm, ast_print_name_node);
}

void ast_print_variable_declaration_node(struct variable_declaration_node_t *node,
                                         int                                 indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[VAR_DECL");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, name);
    CHECK_PTR(node, colon);
    CHECK_PTR(node, mem_len);
    CHECK_PTR(node, align);
    printf("]\n");
    RECURSE(node, name, ast_print_name_node);
    RECURSE(node, colon, ast_print_name_node);
    RECURSE(node, mem_len, ast_print_name_node);
    RECURSE(node, align, ast_print_name_node);
}

void ast_print_register_alias_node(struct register_alias_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[REG_ALIAS");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, name);
    CHECK_PTR(node, colon);
    CHECK_PTR(node, alias);
    CHECK_PTR(node, reg);
    printf("]\n");
    RECURSE(node, name, ast_print_name_node);
    RECURSE(node, colon, ast_print_name_node);
    RECURSE(node, alias, ast_print_name_node);
    RECURSE(node, reg, ast_print_name_node);
}

void ast_print_if_statement_node(struct if_statement_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[IF_STMT");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, kw);
    CHECK_PTR(node, expr);
    CHECK_PTR(node, body);
    CHECK_PTR(node, else_kw);
    CHECK_PTR(node, else_body);
    printf("]\n");
    RECURSE(node, kw, ast_print_name_node);
    RECURSE(node, expr, ast_print_expression_node);
    RECURSE(node, body, ast_print_body_node);
    RECURSE(node, else_kw, ast_print_name_node);
    RECURSE(node, else_body, ast_print_body_node);
}

void ast_print_label_declaration_node(struct label_declaration_node_t *node,
                                      int                              indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[LABEL");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, name);
    CHECK_PTR(node, colon);
    printf("]\n");
    RECURSE(node, name, ast_print_name_node);
    RECURSE(node, colon, ast_print_name_node);
}

void ast_print_goto_statement_node(struct goto_statement_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[GOTO");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, kw);
    CHECK_PTR(node, name);
    CHECK_PTR(node, semicolon);
    printf("]\n");
    RECURSE(node, kw, ast_print_name_node);
    RECURSE(node, name, ast_print_name_node);
    RECURSE(node, semicolon, ast_print_name_node);
}

void ast_print_loop_statement_node(struct loop_statement_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[LOOP");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, kw);
    CHECK_PTR(node, body);
    printf("]\n");
    RECURSE(node, kw, ast_print_name_node);
    RECURSE(node, body, ast_print_body_node);
}

void ast_print_break_statement_node(struct break_statement_node_t *node,
                                    int                            indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[BREAK");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, kw);
    CHECK_PTR(node, semicolon);
    printf("]\n");
    RECURSE(node, kw, ast_print_name_node);
    RECURSE(node, semicolon, ast_print_name_node);
}

void ast_print_ret_statement_node(struct ret_statement_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[RET");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, kw);
    CHECK_PTR(node, expr);
    CHECK_PTR(node, semicolon);
    printf("]\n");
    RECURSE(node, kw, ast_print_name_node);
    RECURSE(node, expr, ast_print_expression_node);
    RECURSE(node, semicolon, ast_print_name_node);
}

void ast_print_avoid_block_regs_node(struct avoid_block_regs_node_t *node,
                                     int                             indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[AVOID_REGS");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, rest);
    CHECK_PTR(node, comma);
    CHECK_PTR(node, reg);
    printf("]\n");
    RECURSE(node, rest, ast_print_avoid_block_regs_node);
    RECURSE(node, comma, ast_print_name_node);
    RECURSE(node, reg, ast_print_name_node);
}

void ast_print_avoid_block_node(struct avoid_block_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[AVOID_BLOCK");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, kw);
    CHECK_PTR(node, regs);
    CHECK_PTR(node, body);
    printf("]\n");
    RECURSE(node, kw, ast_print_name_node);
    RECURSE(node, regs, ast_print_avoid_block_regs_node);
    RECURSE(node, body, ast_print_body_node);
}

void ast_print_expression_node(struct expression_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[EXPRESSION");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, arg1);
    CHECK_PTR(node, op);
    CHECK_PTR(node, arg2);
    CHECK_PTR(node, other);
    printf("]\n");
    RECURSE(node, arg1, ast_print_logical_or_node);
    RECURSE(node, op, ast_print_name_node);
    RECURSE(node, arg2, ast_print_expression_node);
    RECURSE(node, other, ast_print_logical_or_node);
}

void ast_print_logical_or_node(struct logical_or_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[LOGICAL_OR");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, arg1);
    CHECK_PTR(node, op);
    CHECK_PTR(node, arg2);
    CHECK_PTR(node, other);
    printf("]\n");
    RECURSE(node, arg1, ast_print_logical_or_node);
    RECURSE(node, op, ast_print_name_node);
    RECURSE(node, arg2, ast_print_logical_and_node);
    RECURSE(node, other, ast_print_logical_and_node);
}

void ast_print_logical_and_node(struct logical_and_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[LOGICAL_AND");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, arg1);
    CHECK_PTR(node, op);
    CHECK_PTR(node, arg2);
    CHECK_PTR(node, other);
    printf("]\n");
    RECURSE(node, arg1, ast_print_logical_and_node);
    RECURSE(node, op, ast_print_name_node);
    RECURSE(node, arg2, ast_print_bitwise_or_node);
    RECURSE(node, other, ast_print_bitwise_or_node);
}

void ast_print_bitwise_or_node(struct bitwise_or_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[BITWISE_OR");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, arg1);
    CHECK_PTR(node, op);
    CHECK_PTR(node, arg2);
    CHECK_PTR(node, other);
    printf("]\n");
    RECURSE(node, arg1, ast_print_bitwise_or_node);
    RECURSE(node, op, ast_print_name_node);
    RECURSE(node, arg2, ast_print_bitwise_xor_node);
    RECURSE(node, other, ast_print_bitwise_xor_node);
}

void ast_print_bitwise_xor_node(struct bitwise_xor_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[BITWISE_XOR");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, arg1);
    CHECK_PTR(node, op);
    CHECK_PTR(node, arg2);
    CHECK_PTR(node, other);
    printf("]\n");
    RECURSE(node, arg1, ast_print_bitwise_xor_node);
    RECURSE(node, op, ast_print_name_node);
    RECURSE(node, arg2, ast_print_bitwise_and_node);
    RECURSE(node, other, ast_print_bitwise_and_node);
}

void ast_print_bitwise_and_node(struct bitwise_and_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[BITWISE_AND");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, arg1);
    CHECK_PTR(node, op);
    CHECK_PTR(node, arg2);
    CHECK_PTR(node, other);
    printf("]\n");
    RECURSE(node, arg1, ast_print_bitwise_and_node);
    RECURSE(node, op, ast_print_name_node);
    RECURSE(node, arg2, ast_print_equality_node);
    RECURSE(node, other, ast_print_equality_node);
}

void ast_print_equality_node(struct equality_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[EQUALITY");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, arg1);
    CHECK_PTR(node, op);
    CHECK_PTR(node, arg2);
    CHECK_PTR(node, other);
    printf("]\n");
    RECURSE(node, arg1, ast_print_equality_node);
    RECURSE(node, op, ast_print_name_node);
    RECURSE(node, arg2, ast_print_relational_node);
    RECURSE(node, other, ast_print_relational_node);
}

void ast_print_relational_node(struct relational_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[RELATIONAL");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, arg1);
    CHECK_PTR(node, op);
    CHECK_PTR(node, arg2);
    CHECK_PTR(node, other);
    printf("]\n");
    RECURSE(node, arg1, ast_print_relational_node);
    RECURSE(node, op, ast_print_name_node);
    RECURSE(node, arg2, ast_print_additive_node);
    RECURSE(node, other, ast_print_additive_node);
}

void ast_print_additive_node(struct additive_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[ADDITIVE");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, arg1);
    CHECK_PTR(node, op);
    CHECK_PTR(node, arg2);
    CHECK_PTR(node, other);
    printf("]\n");
    RECURSE(node, arg1, ast_print_additive_node);
    RECURSE(node, op, ast_print_name_node);
    RECURSE(node, arg2, ast_print_multiplicative_node);
    RECURSE(node, other, ast_print_multiplicative_node);
}

void ast_print_multiplicative_node(struct multiplicative_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[MULTIPLICATIVE");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, arg1);
    CHECK_PTR(node, op);
    CHECK_PTR(node, arg2);
    CHECK_PTR(node, other);
    printf("]\n");
    RECURSE(node, arg1, ast_print_multiplicative_node);
    RECURSE(node, op, ast_print_name_node);
    RECURSE(node, arg2, ast_print_tetriary_node);
    RECURSE(node, other, ast_print_tetriary_node);
}

void ast_print_prefix_op_node(struct prefix_op_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[PREFIX_OP");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, op);
    CHECK_PTR(node, arg);
    printf("]\n");
    RECURSE(node, op, ast_print_name_node);
    RECURSE(node, arg, ast_print_tetriary_node);
}

void ast_print_cast_op_node(struct cast_op_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[CAST_OP");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, arg);
    CHECK_PTR(node, op);
    printf("]\n");
    RECURSE(node, arg, ast_print_tetriary_node);
    RECURSE(node, op, ast_print_name_node);
}

void ast_print_address_op_node(struct address_op_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[ADDRESS_OP");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, open_brace);
    CHECK_PTR(node, offset);
    CHECK_PTR(node, closed_brace);
    CHECK_PTR(node, arg);
    printf("]\n");
    RECURSE(node, open_brace, ast_print_name_node);
    RECURSE(node, offset, ast_print_expression_node);
    RECURSE(node, closed_brace, ast_print_name_node);
    RECURSE(node, arg, ast_print_tetriary_node);
}

void ast_print_sizeof_op_node(struct sizeof_op_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[SIZEOF_OP");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, kw);
    CHECK_PTR(node, name);
    printf("]\n");
    RECURSE(node, kw, ast_print_name_node);
    RECURSE(node, name, ast_print_name_node);
}

void ast_print_tetriary_node(struct tetriary_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[TETRIARY");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, prefix);
    CHECK_PTR(node, cast);
    CHECK_PTR(node, address);
    CHECK_PTR(node, sizeof_op);
    CHECK_PTR(node, secondary);
    printf("]\n");
    RECURSE(node, prefix, ast_print_prefix_op_node);
    RECURSE(node, cast, ast_print_cast_op_node);
    RECURSE(node, address, ast_print_address_op_node);
    RECURSE(node, sizeof_op, ast_print_sizeof_op_node);
    RECURSE(node, secondary, ast_print_secondary_node);
}

void ast_print_suffix_op_node(struct suffix_op_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[SUFFIX_OP");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, arg);
    CHECK_PTR(node, op);
    printf("]\n");
    RECURSE(node, arg, ast_print_secondary_node);
    RECURSE(node, op, ast_print_name_node);
}

void ast_print_function_call_op_arg_node(struct function_call_op_arg_node_t *node, int indent) {
    if (!node) return;
    p_ind(indent);
    printf("[FN_CALL_ARG");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, colon);
    CHECK_PTR(node, mem_len);
    CHECK_PTR(node, align);
    CHECK_PTR(node, abi_class);
    printf("]\n");
    RECURSE(node, colon, ast_print_name_node);
    RECURSE(node, mem_len, ast_print_name_node);
    RECURSE(node, align, ast_print_name_node);
    RECURSE(node, abi_class, ast_print_abi_class_node);
}

void ast_print_function_call_op_args_node(struct function_call_op_args_node_t *node, int indent) {
    if (!node) return;
    p_ind(indent);
    printf("[FN_CALL_ARGS");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, rest);
    CHECK_PTR(node, comma);
    CHECK_PTR(node, arg);
    printf("]\n");
    RECURSE(node, rest, ast_print_function_call_op_args_node);
    RECURSE(node, comma, ast_print_name_node);
    RECURSE(node, arg, ast_print_function_call_op_arg_node);
}

void ast_print_function_call_op_node(struct function_call_op_node_t *node, int indent) {
    if (!node) return;
    p_ind(indent);
    printf("[FN_CALL_OP");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, kw);
    CHECK_PTR(node, fn);
    CHECK_PTR(node, mem_len);
    CHECK_PTR(node, abi_class);
    CHECK_PTR(node, open_bracket);
    CHECK_PTR(node, args);
    CHECK_PTR(node, close_bracket);
    printf("]\n");
    RECURSE(node, kw, ast_print_name_node);
    RECURSE(node, fn, ast_print_expression_node);
    RECURSE(node, mem_len, ast_print_name_node);
    RECURSE(node, abi_class, ast_print_abi_class_node);
    RECURSE(node, open_bracket, ast_print_name_node);
    RECURSE(node, args, ast_print_function_call_op_args_node);
    RECURSE(node, close_bracket, ast_print_name_node);
}

void ast_print_dereference_op_node(struct dereference_op_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[DEREF_OP");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, arg);
    CHECK_PTR(node, open_brace);
    CHECK_PTR(node, offset);
    CHECK_PTR(node, close_brace);
    printf("]\n");
    RECURSE(node, arg, ast_print_secondary_node);
    RECURSE(node, open_brace, ast_print_name_node);
    RECURSE(node, offset, ast_print_expression_node);
    RECURSE(node, close_brace, ast_print_name_node);
}

void ast_print_layout_access_op_node(struct layout_access_op_node_t *node,
                                     int                             indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[LAYOUT_ACCESS_OP");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, arg);
    CHECK_PTR(node, op);
    CHECK_PTR(node, field);
    printf("]\n");
    RECURSE(node, arg, ast_print_secondary_node);
    RECURSE(node, op, ast_print_name_node);
    RECURSE(node, field, ast_print_name_node);
}

void ast_print_secondary_node(struct secondary_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[SECONDARY");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, suffix);
    CHECK_PTR(node, fn_call);
    CHECK_PTR(node, deref);
    CHECK_PTR(node, layout_access);
    CHECK_PTR(node, primary);
    printf("]\n");
    RECURSE(node, suffix, ast_print_suffix_op_node);
    RECURSE(node, fn_call, ast_print_function_call_op_node);
    RECURSE(node, deref, ast_print_dereference_op_node);
    RECURSE(node, layout_access, ast_print_layout_access_op_node);
    RECURSE(node, primary, ast_print_primary_node);
}

void ast_print_primary_node(struct primary_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[PRIMARY");
    p_frag(node->frag);
    printf(":");
    CHECK_PTR(node, open_brace);
    CHECK_PTR(node, expression);
    CHECK_PTR(node, close_brace);
    CHECK_PTR(node, literal);
    printf("]\n");
    RECURSE(node, open_brace, ast_print_name_node);
    RECURSE(node, expression, ast_print_expression_node);
    RECURSE(node, close_brace, ast_print_name_node);
    RECURSE(node, literal, ast_print_literal_node);
}

void ast_print_literal_node(struct literal_node_t *node, int indent) {
    if (!node)
        return;
    p_ind(indent);
    printf("[LITERAL");
    p_frag(node->frag);
    switch (node->type) {
    case LIT_INT:
        printf(" (INT)]: %" PRIi64 "\n", node->int_lit);
        break;
    case LIT_UINT:
        printf(" (UINT)]: %" PRIu64 "\n", node->uint_lit);
        break;
    case LIT_DOUBLE:
        printf(" (DOUBLE)]: %f\n", node->double_lit);
        break;
    case LIT_STRING:
        printf(" (STRING)]: \"%s\"\n", node->string_lit);
        break;
    case LIT_NAME:
        printf(" (NAME)]:\n");
        RECURSE(node, name_lit, ast_print_name_node);
        break;
    }
}
