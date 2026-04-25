#include "expr.h"

#include "gen.h"

#define SAVE_CONTEXT(fc_ptr, context_save) ((context_save) = *(fc_ptr))
#define RESTORE_CONTEXT(fc_ptr, context_save) (*(fc_ptr) = (context_save))

struct expr_gen_t expr_gen_invalid() {
    return (struct expr_gen_t){.cb = cb_invalid()};
}
int expr_gen_is_valid(struct expr_gen_t *eg) {
    return cb_is_valid(&eg->cb);
}
void expr_gen_destroy(struct expr_gen_t *eg) {
    if (expr_gen_is_valid(eg)) {
        cb_destroy(&eg->cb);
    }
}

/*
 * Some locations (like symbols, or pointers*) are not immediatelly available for
 * codegen. This function extracts them into a register.
 * For all other locs, it does nothing.
 *
 * This function may use a register from the gpr pool. */
static struct expr_gen_t extract(tfrag_t *frag, int indent, struct location_t *loc,
                                 struct function_context_t *fc) {
    log_debug("Extracting loc_id=%d\n", loc->type);
    struct expr_gen_t res = {0};
    cb_init(&res.cb);

    if (loc->type == LOC_SYMBOL) {
        // extract address into a register. inefficient, but i do not care atp.
        log_debug(" - extracting LOC_SYMBOL\n");
        EXPLAIN(res.cb, indent, "Extracting LOC_SYMBOL into a register.\n");
        struct gpr_pool_item_t *reg = gpr_pool_borrow(frag, &fc->gpr_pool);
        cb_add_back(&res.cb, indent, "lea %s, [rel %s]\n", reg->reg->qname,
                    loc->symbol);
        res.loc = (struct location_t){
            .type = LOC_MEM,
            .true_len = 8,
            .alignment = 8,
            .base = reg->reg,
            .index = NULL,
            .scale = 0,
            .offset = 0,
        };
        return res;
    } else if (loc->type == LOC_PTR_IN_GPR) {
        // same
        log_debug(" - extracting LOC_PTR_IN_GPR\n");
        EXPLAIN(res.cb, indent, "Extracting LOC_PTR_IN_GPR into a register.\n");
        struct gpr_pool_item_t *reg = gpr_pool_borrow(frag, &fc->gpr_pool);
        cb_add_back(&res.cb, indent, "mov %s, %s\n", reg->reg->qname, loc->gpr_reg1);
        res.loc = (struct location_t){
            .type = LOC_MEM,
            .true_len = 8,
            .alignment = 8,
            .base = reg->reg,
            .index = NULL,
            .scale = 0,
            .offset = 0,
        };
        return res;
    } else if (loc->type == LOC_PTR_ON_STACK) {
        // also the same
        log_debug(" - extracting LOC_PTR_ON_STACK\n");
        EXPLAIN(res.cb, indent, "Extracting LOC_PTR_ON_STACK into a register.\n");
        struct gpr_pool_item_t *reg = gpr_pool_borrow(frag, &fc->gpr_pool);
        cb_add_back(&res.cb, indent, "mov %s, [%s]\n", reg->reg->qname,
                    util_format_memory_address(util_get_memory_address(loc)));
        res.loc = (struct location_t){
            .type = LOC_MEM,
            .true_len = 8,
            .alignment = 8,
            .base = reg->reg,
            .index = NULL,
            .scale = 0,
            .offset = 0,
        };
        return res;
    } else {
        res.loc = *loc;
        return res;
    }
}

struct expr_gen_t gen_expression(int indent, struct expression_node_t *node,
                                 struct function_context_t *fc) {
    log_assert(node != NULL);

    if (node->other != NULL) {
        return gen_expr(indent, node->other, fc);
    }
    LOG_ENTER(&node->frag, indent);

    struct function_context_t context_save = {0};
    struct expr_gen_t         res = {0};
    struct expr_gen_t         left = {0};
    struct expr_gen_t         right = {0};
    struct expr_gen_t         addr = {0};
    struct expr_gen_t         value = {0};
    cb_t                      last = {0};

    SAVE_CONTEXT(fc, context_save);
    cb_init(&res.cb);

    EXPLAIN(res.cb, indent, "Assignment operator.\n");

    left = gen_expr(indent, node->arg1, fc);
    if (!expr_gen_is_valid(&left)) {
        goto error;
    }

    right = gen_expr(indent, node->arg2, fc);
    if (!expr_gen_is_valid(&right)) {
        goto error;
    }

    addr = extract(&node->arg1->frag, indent, &left.loc, fc);
    if (!expr_gen_is_valid(&addr)) {
        goto error;
    }

    value = extract(&node->arg2->frag, indent, &right.loc, fc);
    if (!expr_gen_is_valid(&value)) {
        goto error;
    }

    cb_glue_back(&res.cb, &left.cb);
    cb_glue_back(&res.cb, &right.cb);
    cb_glue_back(&res.cb, &addr.cb);
    cb_glue_back(&res.cb, &value.cb);

    size_t left_size, right_size = 0;

    if (util_parse_operator(node->op, &left_size, NULL, &right_size, NULL, NULL)) {
        goto error;
    }
    if (left_size != right_size) {
        context_msg(
            &node->op->frag,
            "Error: cannot assign arguments of different sizes. Did you forget a "
            "cast?\n");
        goto error;
    }

    last = loc_move_data(indent, &value.loc, &addr.loc, left_size, &fc->gpr_pool,
                         &fc->lblg, &node->frag);
    if (!cb_is_valid(&last)) {
        goto error;
    }
    gpr_pool_handle_borrowed(&last, indent, &fc->gpr_pool, false);
    cb_glue_back(&res.cb, &last);

    res.loc = left.loc;

end:
    RESTORE_CONTEXT(fc, context_save);
    return res;

error:
    expr_gen_destroy(&res);
    expr_gen_destroy(&left);
    expr_gen_destroy(&right);
    expr_gen_destroy(&addr);
    expr_gen_destroy(&value);
    cb_destroy(&last);
    res = expr_gen_invalid();
    goto end;
}

struct expr_gen_t gen_logical_or(int indent, struct logical_or_node_t *node,
                                 struct function_context_t *fc) {
    log_assert(node != NULL);
    // LOG_ENTER(&node->frag, indent);

    if (node->other != NULL) {
        return gen_expr(indent, node->other, fc);
    }

    struct expr_gen_t res = {0};
    cb_init(&res.cb);

    return res;
}

struct expr_gen_t gen_logical_and(int indent, struct logical_and_node_t *node,
                                  struct function_context_t *fc) {
    log_assert(node != NULL);
    // LOG_ENTER(&node->frag, indent);

    if (node->other != NULL) {
        return gen_expr(indent, node->other, fc);
    }

    struct expr_gen_t res = {0};
    cb_init(&res.cb);

    return res;
}

struct expr_gen_t gen_bitwise_or(int indent, struct bitwise_or_node_t *node,
                                 struct function_context_t *fc) {
    log_assert(node != NULL);
    // LOG_ENTER(&node->frag, indent);

    if (node->other != NULL) {
        return gen_expr(indent, node->other, fc);
    }

    struct expr_gen_t res = {0};
    cb_init(&res.cb);

    return res;
}

struct expr_gen_t gen_bitwise_xor(int indent, struct bitwise_xor_node_t *node,
                                  struct function_context_t *fc) {
    log_assert(node != NULL);
    // LOG_ENTER(&node->frag, indent);

    if (node->other != NULL) {
        return gen_expr(indent, node->other, fc);
    }

    struct expr_gen_t res = {0};
    cb_init(&res.cb);

    return res;
}

struct expr_gen_t gen_bitwise_and(int indent, struct bitwise_and_node_t *node,
                                  struct function_context_t *fc) {
    log_assert(node != NULL);
    // LOG_ENTER(&node->frag, indent);

    if (node->other != NULL) {
        return gen_expr(indent, node->other, fc);
    }

    struct expr_gen_t res = {0};
    cb_init(&res.cb);

    return res;
}

struct expr_gen_t gen_equality(int indent, struct equality_node_t *node,
                               struct function_context_t *fc) {
    log_assert(node != NULL);
    // LOG_ENTER(&node->frag, indent);

    if (node->other != NULL) {
        return gen_expr(indent, node->other, fc);
    }

    struct expr_gen_t res = {0};
    cb_init(&res.cb);

    return res;
}

struct expr_gen_t gen_relational(int indent, struct relational_node_t *node,
                                 struct function_context_t *fc) {
    log_assert(node != NULL);
    // LOG_ENTER(&node->frag, indent);

    if (node->other != NULL) {
        return gen_expr(indent, node->other, fc);
    }

    struct expr_gen_t res = {0};
    cb_init(&res.cb);

    return res;
}

struct expr_gen_t gen_additive(int indent, struct additive_node_t *node,
                               struct function_context_t *fc) {
    log_assert(node != NULL);
    // LOG_ENTER(&node->frag, indent);

    if (node->other != NULL) {
        return gen_expr(indent, node->other, fc);
    }

    struct expr_gen_t res = {0};
    cb_init(&res.cb);

    return res;
}

struct expr_gen_t gen_multiplicative(int indent, struct multiplicative_node_t *node,
                                     struct function_context_t *fc) {
    log_assert(node != NULL);
    // LOG_ENTER(&node->frag, indent);

    if (node->other != NULL) {
        return gen_expr(indent, node->other, fc);
    }

    struct expr_gen_t res = {0};
    cb_init(&res.cb);

    return res;
}

struct expr_gen_t gen_prefix_op(int indent, struct prefix_op_node_t *node,
                                struct function_context_t *fc) {
    log_assert(node != NULL);
    // LOG_ENTER(&node->frag, indent);

    struct expr_gen_t res = {0};
    cb_init(&res.cb);

    return res;
}

struct expr_gen_t gen_cast_op(int indent, struct cast_op_node_t *node,
                              struct function_context_t *fc) {
    log_assert(node != NULL);
    // LOG_ENTER(&node->frag, indent);

    struct expr_gen_t res = {0};
    cb_init(&res.cb);

    return res;
}

struct expr_gen_t gen_address_op(int indent, struct address_op_node_t *node,
                                 struct function_context_t *fc) {
    log_assert(node != NULL);
    // LOG_ENTER(&node->frag, indent);

    struct expr_gen_t res = {0};
    cb_init(&res.cb);

    return res;
}

struct expr_gen_t gen_sizeof_op(int indent, struct sizeof_op_node_t *node,
                                struct function_context_t *fc) {
    log_assert(node != NULL);
    // LOG_ENTER(&node->frag, indent);

    struct expr_gen_t res = {0};
    cb_init(&res.cb);

    return res;
}

struct expr_gen_t gen_tetriary(int indent, struct tetriary_node_t *node,
                               struct function_context_t *fc) {
    log_assert(node != NULL);
    // LOG_ENTER(&node->frag, indent);

    if (node->secondary != NULL) {
        return gen_expr(indent, node->secondary, fc);
    }

    struct expr_gen_t res = {0};
    cb_init(&res.cb);

    return res;
}

struct expr_gen_t gen_suffix_op(int indent, struct suffix_op_node_t *node,
                                struct function_context_t *fc) {
    log_assert(node != NULL);
    // LOG_ENTER(&node->frag, indent);

    struct expr_gen_t res = {0};
    cb_init(&res.cb);

    return res;
}

struct expr_gen_t gen_function_call_op_arg(int indent,
                                           struct function_call_op_arg_node_t *node,
                                           struct function_context_t          *fc) {
    log_assert(node != NULL);
    // LOG_ENTER(&node->frag, indent);

    struct expr_gen_t res = {0};
    cb_init(&res.cb);

    return res;
}

struct expr_gen_t gen_function_call_op_args(
    int indent, struct function_call_op_args_node_t *node,
    struct function_context_t *fc) {
    log_assert(node != NULL);
    // LOG_ENTER(&node->frag, indent);

    struct expr_gen_t res = {0};
    cb_init(&res.cb);

    return res;
}

struct expr_gen_t gen_function_call_op(int                             indent,
                                       struct function_call_op_node_t *node,
                                       struct function_context_t      *fc) {
    log_assert(node != NULL);
    // LOG_ENTER(&node->frag, indent);

    struct expr_gen_t res = {0};
    cb_init(&res.cb);

    return res;
}

struct expr_gen_t gen_dereference_op(int indent, struct dereference_op_node_t *node,
                                     struct function_context_t *fc) {
    log_assert(node != NULL);
    // LOG_ENTER(&node->frag, indent);

    struct expr_gen_t res = {0};
    cb_init(&res.cb);

    return res;
}

struct expr_gen_t gen_layout_access_op(int                             indent,
                                       struct layout_access_op_node_t *node,
                                       struct function_context_t      *fc) {
    log_assert(node != NULL);
    // LOG_ENTER(&node->frag, indent);

    struct expr_gen_t res = {0};
    cb_init(&res.cb);

    return res;
}

struct expr_gen_t gen_secondary(int indent, struct secondary_node_t *node,
                                struct function_context_t *fc) {
    log_assert(node != NULL);
    // LOG_ENTER(&node->frag, indent);

    if (node->primary != NULL) {
        return gen_expr(indent, node->primary, fc);
    }

    struct expr_gen_t res = {0};
    cb_init(&res.cb);

    return res;
}

struct expr_gen_t gen_primary(int indent, struct primary_node_t *node,
                              struct function_context_t *fc) {
    log_assert(node != NULL);
    // LOG_ENTER(&node->frag, indent);

    if (node->literal != NULL) {
        return gen_expr(indent, node->literal, fc);
    }

    struct expr_gen_t res = {0};
    cb_init(&res.cb);

    return res;
}

struct expr_gen_t gen_literal(int indent, struct literal_node_t *node,
                              struct function_context_t *fc) {
    log_assert(node != NULL);
    LOG_ENTER(&node->frag, indent);

    struct expr_gen_t res = {0};
    cb_init(&res.cb);

    if (node->type == LIT_INT) {
        res.loc = (struct location_t){
            .type = LOC_INT_LITERAL,
            .true_len = 8,
            .alignment = 8,
            .int_literal = node->int_lit,
        };
        log_debug(" - int literal: %" PRId64 "\n", node->int_lit);
    } else if (node->type == LIT_UINT) {
        res.loc = (struct location_t){
            .type = LOC_UINT_LITERAL,
            .true_len = 8,
            .alignment = 8,
            .uint_literal = node->uint_lit,
        };
        log_debug(" - int literal: %" PRIu64 "\n", node->uint_lit);
    } else if (node->type == LIT_DOUBLE) {
        char  *name;
        size_t repr;
        memcpy(&repr, &node->double_lit, sizeof(size_t));

        name = asprintf_safe("__lit__f%zu", repr);
        name = (char *)pstr_take(name);
        if (scope_has(&global_scope, name)) {
            res.loc = scope_get(&global_scope, name);
            log_debug(" - reusing double literal: %.17g\n", node->double_lit);
        } else {
            const char *lbl = lblg_gen_double_lit();
            cb_add_back(&data_section, CB_TAB, "%s dq %.17g\n", lbl,
                        node->double_lit);
            res.loc = (struct location_t){
                .type = LOC_SYMBOL,
                .true_len = 8,
                .alignment = 8,
                .symbol = pstr_take(memdup_safe(lbl, strlen(lbl) + 1)),
            };
            scope_add(&global_scope, name, res.loc);
            log_debug(" - new double literal: %.17g (symbol %s)\n", node->double_lit,
                      lbl);
        }
    } else if (node->type == LIT_STRING) {
        char *name;

        const char *str = node->frag.token;
        name = asprintf_safe("__lit__s%s", str);
        name = (char *)pstr_take(name);
        if (scope_has(&global_scope, name)) {
            res.loc = scope_get(&global_scope, name);
            log_debug(" - reusing string literal: %s\n", str);
        } else {
            const char *lbl = lblg_gen_string_lit();
            char       *cpy = calloc_safe(strlen(str) + 1 + 2, sizeof(char));
            strcpy(cpy, str);
            cpy[strlen(str) - 1] = '\\';
            cpy[strlen(str)] = '0';
            cpy[strlen(str) + 1] = '\0';
            cb_add_back(&data_section, CB_TAB, "%s db `%s`\n", lbl, cpy + 1);
            free(cpy);
            res.loc = (struct location_t){
                .type = LOC_SYMBOL,
                .true_len = 8,  // why not len(name)? because
                .alignment = 8,
                .symbol = pstr_take(memdup_safe(lbl, strlen(lbl) + 1)),
            };
            scope_add(&global_scope, name, res.loc);
            log_debug(" - new string literal: %s (symbol %s)\n", str, lbl);
        }
    } else if (node->type == LIT_NAME) {
        if (scope_has(&fc->local_scope, node->name_lit->name)) {
            res.loc = scope_get(&fc->local_scope, node->name_lit->name);
            log_debug(" - found name '%s' in local scope\n", node->name_lit->name);
        } else if (scope_has(&global_scope, node->name_lit->name)) {
            res.loc = scope_get(&global_scope, node->name_lit->name);
            log_debug(" - found name '%s' in global scope\n", node->name_lit->name);
        } else {
            context_msg(&node->name_lit->frag, "Error: unknown name.\n");
            cb_destroy(&res.cb);
            return (struct expr_gen_t){.cb = cb_invalid()};
        }
    } else {
        log_crit("lmao how\n");
    }

    return res;
}
