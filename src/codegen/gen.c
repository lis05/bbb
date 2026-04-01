#include "gen.h"

#include "expr.h"

static cb_t gen_program(int indent, const struct program_node_t *node);
static cb_t gen_global_variable_decl(
    int indent, const struct global_variable_declaration_node_t *node);
static cb_t gen_extern_decl(int                                     indent,
                            const struct extern_declaration_node_t *node);
static cb_t gen_layout_decl(int                                     indent,
                            const struct layout_declaration_node_t *node);
static cb_t gen_function_declaration(int indent,
                                     const struct function_declaration_node_t *node);
static cb_t gen_body(int indent, const struct body_node_t *node,
                     struct function_context_t *fc);
static cb_t gen_body_list(int indent, const struct body_list_node_t *node,
                          struct function_context_t *fc);
static cb_t gen_statement(int indent, const struct statement_node_t *node,
                          struct function_context_t *fc);
static cb_t gen_variable_declaration(int indent,
                                     const struct variable_declaration_node_t *node,
                                     struct function_context_t                *fc);
static cb_t gen_register_alias(int indent, const struct register_alias_node_t *node,
                               struct function_context_t *fc);
static cb_t gen_nasm_block(int indent, const struct name_node_t *node,
                           struct function_context_t *fc);

struct scope_t global_scope;
cb_t           data_section;

cb_t gen(struct program_node_t *prog) {
    cb_t res;
    cb_init(&res);

    log_debug("Initializing global scope\n");
    scope_init(&global_scope);

    cb_init(&data_section);
    EXPLAIN(data_section, 0, "Strings and floats are stored here.\n");
    cb_add_back(&data_section, 0, "section .rodata\n");

    cb_t other = gen_program(0, prog);
    if (!cb_is_valid(&other)) {
        return other;
    }
    cb_glue_back(&res, &other);
    cb_glue_back(&res, &data_section);

    scope_destroy(&global_scope);

    return res;
}

static cb_t gen_program(int indent, const struct program_node_t *node) {
    log_assert(node != NULL);
    LOG_ENTER(&node->frag, indent);

    cb_t res;
    cb_init(&res);

    if (node->rest != NULL) {
        cb_t other = gen_program(indent, node->rest);
        if (!cb_is_valid(&other)) {
            return other;
        }
        cb_glue_back(&res, &other);
    }

    if (node->gvar_decl != NULL) {
        cb_t other = gen_global_variable_decl(indent, node->gvar_decl);
        if (!cb_is_valid(&other)) {
            return other;
        }
        cb_glue_back(&res, &other);
    } else if (node->layout_decl != NULL) {
        cb_t other = gen_layout_decl(indent, node->layout_decl);
        if (!cb_is_valid(&other)) {
            return other;
        }
        cb_glue_back(&res, &other);
    } else if (node->ext_decl != NULL) {
        cb_t other = gen_extern_decl(indent, node->ext_decl);
        if (!cb_is_valid(&other)) {
            return other;
        }
        cb_glue_back(&res, &other);
    } else if (node->fn_decl != NULL) {
        cb_t other = gen_function_declaration(indent, node->fn_decl);
        if (!cb_is_valid(&other)) {
            return other;
        }
        cb_glue_back(&res, &other);
    } else if (node->nasm_b != NULL) {
        cb_t other = gen_nasm_block(indent, node->nasm_b, NULL);
        if (!cb_is_valid(&other)) {
            return other;
        }
        cb_glue_back(&res, &other);
    }

    return res;
}

static cb_t gen_global_variable_decl(
    int indent, const struct global_variable_declaration_node_t *node) {
    log_assert(node != NULL);
    LOG_ENTER(&node->frag, indent);

    cb_t res;
    cb_init(&res);

    int    is_global = 0;
    size_t mem_len = 8;
    size_t align = 8;

    if (node->vis != NULL) {
        const char *vis = util_get_visibility(node->vis);
        if (vis != NULL && strcmp(vis, "global") == 0) {
            is_global = 1;
        } else {
            cb_destroy(&res);
            return cb_invalid();
        }
    }
    log_debug(" - global: %d\n", is_global);

    if (node->mem_len != NULL && util_get_mem_len(node->mem_len, &mem_len)) {
        cb_destroy(&res);
        return cb_invalid();
    }
    log_debug(" - mem_len: %zu\n", mem_len);

    if (node->align != NULL && util_get_align(node->align, &align)) {
        cb_destroy(&res);
        return cb_invalid();
    }
    log_debug(" - align: %zu\n", align);

    EXPLAIN(res, indent, "This is a global variable '%s'.\n", node->name->name);
    cb_add_back(&res, indent, "section .bss\n");
    if (is_global == 1) {
        cb_add_back(&res, indent + CB_TAB, "global %s\n", node->name->name);
    }

    cb_add_back(&res, indent + CB_TAB, "alignb %zu\n", align);
    cb_add_back(&res, indent + CB_TAB, "%s: resb %zu\n", node->name->name, mem_len);
    cb_add_back(&res, 0, "\n");

    if (scope_has(&global_scope, node->name->name)) {
        log_debug(" - symbol already in the global scope.\n");
        context_msg(&node->name->frag,
                    "Error: the compiler is already aware of this symbol.\n");
        cb_destroy(&res);
        return cb_invalid();
    }

    struct location_t loc = {
        .type = LOC_SYMBOL,
        .true_len = mem_len,
        .alignment = align,
        .symbol = node->name->name,
    };

    log_debug(" - adding location to global scope.\n");
    scope_add(&global_scope, node->name->name, loc);

    return res;
}

static cb_t gen_extern_decl(int                                     indent,
                            const struct extern_declaration_node_t *node) {
    log_assert(node != NULL);
    LOG_ENTER(&node->frag, indent);

    cb_t res;
    cb_init(&res);

    if (strcmp(node->kw->name, "extern") == 0) {
        log_debug("Generating extern declaration for '%s'\n", node->name->name);

        EXPLAIN(res, indent, "Extern declaration.\n");

        char *line =
            (char *)malloc(strlen("extern ") + strlen(node->name->name) + 1 + 1);
        log_assert(line != NULL);

        strcpy(line, "extern ");
        strcat(line, node->name->name);
        log_debug(" - appending '%s'\n", line);
        strcat(line, "\n");
        cb_add_back(&res, indent, line);
        cb_add_back(&res, 0, "\n");
        free(line);

        if (scope_has(&global_scope, node->name->name)) {
            log_debug(" - symbol already in the global scope.\n");
            context_msg(&node->name->frag,
                        "Error: the compiler is already aware of this symbol.\n");
            cb_destroy(&res);
            return cb_invalid();
        }

        struct location_t loc = {
            .type = LOC_SYMBOL,
            .true_len = 0,
            .alignment = 0,
            .symbol = node->name->name,
        };
        log_debug(" - adding location to global scope.\n");
        scope_add(&global_scope, node->name->name, loc);

        return res;
    } else if (strcmp(node->kw->name, "nasm") == 0) {
        log_debug("Generating nasm declaration\n");

        if (scope_has(&global_scope, node->name->name)) {
            log_debug(" - symbol already in the global scope.\n");
            context_msg(&node->name->frag,
                        "Note: the compiler is already aware of this symbol.\n");
            return res;
        }

        struct location_t loc = {
            .type = LOC_SYMBOL,
            .true_len = 0,
            .alignment = 0,
            .symbol = node->name->name,
        };
        log_debug(" - adding location to global scope.\n");
        scope_add(&global_scope, node->name->name, loc);

        return res;
    } else {
        context_msg(&node->frag, "Unknown declaration (wrong keyword)\n");
        cb_destroy(&res);
        return cb_invalid();
    }
}

static cb_t gen_layout_decl(int                                     indent,
                            const struct layout_declaration_node_t *node) {
    log_assert(node != NULL);
    LOG_ENTER(&node->frag, indent);

    cb_t res;
    cb_init(&res);

    if (layouts_has(node->name->name) == 1) {
        context_msg(&node->name->frag,
                    "Error: layout with the same name already exists.\n");
        cb_destroy(&res);
        return cb_invalid();
    }

    size_t          mem_len;
    struct layout_t layout = {0};

    // first pass for n and total_size
    struct layout_declaration_items_node_t *items = node->items;

    while (items != NULL) {
        if (items->mem_len != NULL && util_get_mem_len(items->mem_len, &mem_len)) {
            cb_destroy(&res);
            return cb_invalid();
        }
        layout.total_size += mem_len;
        if (strcmp(items->name->name, "_") != 0) {
            layout.n++;
        }

        items = items->rest;
    }

    // second pass
    log_debug(" - fields without paddings: %zu\n", layout.n);
    log_debug(" - total size: %zu\n", layout.total_size);
    items = node->items;
    layout.fields = (const char **)malloc(sizeof(const char *) * layout.n);
    log_assert(layout.fields != NULL);
    layout.offsets = (size_t *)malloc(sizeof(const char *) * layout.total_size);
    log_assert(layout.offsets != NULL);

    size_t n = layout.n;
    layout.n = 0;
    size_t i = 0;
    size_t offset = 0;

    EXPLAIN(res, indent, "Layout '%s' is defined as:\n", node->name->name);
    while (items != NULL) {
        if (items->mem_len != NULL && util_get_mem_len(items->mem_len, &mem_len)) {
            cb_destroy(&res);
            return cb_invalid();  // cant happen but ok
        }
        if (layout_has_field(&layout, items->name->name) == 1) {
            context_msg(&items->name->frag, "Error: duplicate layout field.\n");
            free(layout.fields);
            free(layout.offsets);
            cb_destroy(&res);
            return cb_invalid();
        }
        if (strcmp(items->name->name, "_") != 0) {
            layout.fields[i] = items->name->name;
            layout.offsets[i] = offset;
            EXPLAIN(res, indent + CB_TAB, "field '%s' of size %zub at offset +%zu\n",
                    layout.fields[i], mem_len, offset);
            log_debug(" - field '%s' of %zub at +%zu\n", items->name->name, mem_len,
                      offset);
            layout.n++;
        } else {
            log_debug(" - padding of %zub at +%zu\n", mem_len, offset);
            EXPLAIN(res, indent + CB_TAB, "padding of size %zub at offset +%zu\n",
                    mem_len, offset);
        }
        offset += mem_len;

        i++;
        items = items->rest;
    }

    int chunk;
    layout.chunk1 = VMAP_CHUNK_NONE;
    layout.chunk2 = VMAP_CHUNK_NONE;

    if (node->chunk1 != NULL) {
        switch (util_get_chunk(node->chunk1, &chunk)) {
        case -1:
            free(layout.fields);
            free(layout.offsets);
            cb_destroy(&res);
            return cb_invalid();
        case 0:
            layout.chunk1 = chunk;
        }
    }
    if (node->chunk2 != NULL) {
        switch (util_get_chunk(node->chunk2, &chunk)) {
        case -1:
            free(layout.fields);
            free(layout.offsets);
            cb_destroy(&res);
            return cb_invalid();
        case 0:
            layout.chunk2 = chunk;
        }
    }
    log_debug(" - chunk1: %zu\n", (size_t)layout.chunk1);
    EXPLAIN(res, indent + CB_TAB, "chunk1's id is %zu\n", (size_t)layout.chunk1);
    log_debug(" - chunk2: %zu\n", (size_t)layout.chunk2);
    EXPLAIN(res, indent + CB_TAB, "chunk2's id is %zu\n", (size_t)layout.chunk2);

    EXPLAIN_NL(res);
    log_assert(layout.n == n);

    layouts_register(node->name->name, layout);
    log_debug(" - registered the layout.\n");

    return res;
}

// stores info about all function arguments
struct func_args_meta_t {
    size_t       n;
    const char **names;
    size_t      *mem_len;
    size_t      *align;
    uint8_t     *chunk1;
    uint8_t     *chunk2;
    const char **layout;  // exclusive with chunks
    tfrag_t     *frags;
};

static void destroy_func_args_meta(struct func_args_meta_t *meta) {
    free(meta->names);
    free(meta->mem_len);
    free(meta->align);
    free(meta->chunk1);
    free(meta->chunk2);
    free(meta->layout);
    free(meta->frags);
}

static struct func_args_meta_t collect_func_args(
    const struct function_declaration_node_t *node, int *error) {
    log_debug("=== Collecting func_args_meta_t for '%s'\n", node->name->name);
    *error = 0;

    struct func_args_meta_t res = {0};

    struct function_declaration_args_node_t *args = node->args;
    struct function_declaration_arg_node_t  *arg = NULL;
    while (args != NULL) {
        if (args->arg != NULL) {
            res.n++;
        }
        args = args->rest;
    }
    log_debug(" - n=%zu\n", res.n);

    if (res.n == 0) {
        log_debug(" - returning early since n=0\n");
        return res;
    }

    res.names = (const char **)malloc(sizeof(const char *) * res.n);
    log_assert(res.names != NULL);
    res.mem_len = (size_t *)malloc(sizeof(size_t) * res.n);
    log_assert(res.mem_len != NULL);
    res.align = (size_t *)malloc(sizeof(size_t) * res.n);
    log_assert(res.align != NULL);
    res.chunk1 = (uint8_t *)malloc(sizeof(uint8_t) * res.n);
    log_assert(res.chunk1 != NULL);
    res.chunk2 = (uint8_t *)malloc(sizeof(uint8_t) * res.n);
    log_assert(res.chunk2 != NULL);
    res.layout = (const char **)malloc(sizeof(const char *) * res.n);
    log_assert(res.layout != NULL);
    res.frags = (tfrag_t *)malloc(sizeof(tfrag_t) * res.n);
    log_assert(res.frags != NULL);

    args = node->args;
    size_t i = res.n - 1;
    size_t mem_len, align;
    while (args != NULL) {
        if ((arg = args->arg) != NULL) {
            log_debug(" - %zu (%s):\n", i, arg->name->name);
            res.names[i] = arg->name->name;

            for (size_t ii = i + 1; ii < res.n; ii++) {
                if (strcmp(res.names[i], res.names[ii]) == 0) {
                    context_msg(&res.frags[ii], "Error: duplicate parameter.\n");
                    goto l_error;
                }
            }

            mem_len = 8;
            if (arg->mem_len != NULL && util_get_mem_len(arg->mem_len, &mem_len)) {
                goto l_error;
            }
            res.mem_len[i] = mem_len;
            log_debug("   - mem_len=%zu\n", mem_len);

            align = 8;
            if (arg->align != NULL && util_get_align(arg->align, &align)) {
                goto l_error;
            }
            res.align[i] = align;
            log_debug("   - align=%zu\n", align);

            int         chunk1 = VMAP_CHUNK_INT, chunk2 = VMAP_CHUNK_NONE;
            const char *layout = NULL;
            if (arg->abi_class != NULL) {
                switch (
                    util_get_abi_class(arg->abi_class, &chunk1, &chunk2, &layout)) {
                case -1:
                    goto l_error;
                case 0:
                    log_debug("   - chunk1=%d\n", chunk1);
                    log_debug("   - chunk2=%d\n", chunk2);
                    break;
                case 1:
                    log_debug("   - layout=%s\n", layout);
                    break;
                }
            }
            res.chunk1[i] = chunk1;
            res.chunk2[i] = chunk2;
            res.layout[i] = layout;

            res.frags[i] = arg->frag;
        }

        i--;
        args = args->rest;
    }
    log_assert(i + 1 == 0);
    log_debug("=== done\n");
    return res;

l_error:
    *error = 1;
    destroy_func_args_meta(&res);
    return (struct func_args_meta_t){0};
}

/*
 * ==========================================
 * From this point onwards, everything will be inside of functions...
 *
 *                          ^^^^^^^^^^ lmao no, nasm blocks lol
 */

static cb_t gen_function_declaration(
    int indent, const struct function_declaration_node_t *node) {
    log_assert(node != NULL);
    LOG_ENTER(&node->frag, indent);

    cb_t res;
    cb_init(&res);

    if (scope_has(&global_scope, node->name->name)) {
        log_debug(" - symbol already in the global scope.\n");
        context_msg(&node->name->frag,
                    "Note: the compiler is already aware of this symbol.\n");
        cb_destroy(&res);
        return cb_invalid();
    }

    int                     meta_error;
    struct func_args_meta_t args_meta = collect_func_args(node, &meta_error);
    if (meta_error) {
        destroy_func_args_meta(&args_meta);
        cb_destroy(&res);
        return cb_invalid();
    }

    EXPLAIN(res, indent, "Function '%s' begins here.\n", node->name->name);
    cb_add_back(&res, indent, "section .text\n");
    if (node->vis != NULL) {
        if (strcmp(util_get_visibility(node->vis), "global") == 0) {
            cb_add_back(&res, indent, "global %s\n", node->name->name);
        } else {
            context_msg(&node->vis->frag, "Error: invalid visibility.\n");
            destroy_func_args_meta(&args_meta);
            cb_destroy(&res);
            return cb_invalid();
        }
    }

    cb_add_back(&res, indent, "%s:\n", node->name->name);
    indent += CB_TAB;

    struct vmap_t args_mapping = {0};
    struct vmap_t args_copy_mapping = {0};

    log_debug(" - constructing vmap_args_request_t\n");
    struct vmap_args_request_t args_request = {0};
    args_request.n = args_meta.n;
    if (args_request.n != 0) {
        args_request.names = (const char **)memdup_safe(
            args_meta.names, args_meta.n * sizeof(const char *));
        log_assert(args_request.names != NULL);
        args_request.mem_len =
            (size_t *)memdup_safe(args_meta.mem_len, args_meta.n * sizeof(size_t));
        args_request.align =
            (size_t *)memdup_safe(args_meta.align, args_meta.n * sizeof(size_t));

        // chunks may come from a layout
        args_request.chunk1 =
            (uint8_t *)memdup_safe(args_meta.chunk1, args_meta.n * sizeof(uint8_t));
        args_request.chunk2 =
            (uint8_t *)memdup_safe(args_meta.chunk2, args_meta.n * sizeof(uint8_t));
    }
    for (size_t i = 0; i < args_meta.n; i++) {
        if (args_meta.layout[i] != NULL) {
            log_debug("   - argument %zu (%s) is classified using a layout %s\n", i,
                      args_request.names[i], args_meta.layout[i]);

            if (!layouts_has(args_meta.layout[i])) {
                context_msg(&args_meta.frags[i],
                            "Error: the layout referenced here has not been "
                            "declared yet.\n");
                goto g_error;
            }

            struct layout_t layout = layouts_find(args_meta.layout[i]);
            args_request.chunk1[i] =
                layout.chunk1 == VMAP_CHUNK_NONE ? VMAP_CHUNK_INT : layout.chunk1;
            args_request.chunk2[i] =
                layout.chunk2 == VMAP_CHUNK_NONE ? VMAP_CHUNK_INT : layout.chunk2;
        }
    }
    log_debug("   - done creating vmap_args_request_t\n");

    log_debug(" - running vmap_args()\n");
    args_mapping = vmap_args(&args_request);
    log_debug("   - done running vmap_args()\n");

    log_debug(" - running vmap_args_copy()\n");
    args_copy_mapping = vmap_args_copy(&args_request);
    log_debug("   - done running vmap_args()\n");

    struct function_context_t fc;
    fc_init(&fc);

    if (args_copy_mapping.n > 0) {
        fc.stack_offset =
            args_copy_mapping.locs[args_copy_mapping.n - 1].stack_offset;
    }

    for (size_t i = 0; i < args_copy_mapping.n; i++) {
        log_debug(" - adding %zu-th function param to scope.\n", i);
        scope_add(&fc.local_scope, args_copy_mapping.names[i],
                  args_copy_mapping.locs[i]);
    }

    // TODO: add return value request

    cb_t body = gen_body(indent, node->body, &fc);
    if (!cb_is_valid(&body)) {
        goto g_error;
    }

    int64_t frame_size = -fc.stack_offset;
    log_assert(frame_size >= 0);
    log_debug(" - frame size: %" PRId64 "\n", frame_size);

    /* =============================================
     * new stack frame
     */

    cb_add_back(&res, indent, "push rbp\n");
    cb_add_back(&res, indent, "mov rbp, rsp\n");
    EXPLAIN(res, indent, "Space for local variables.\n");
    cb_add_back(&res, indent, "sub rsp, %zu\n", (size_t)frame_size);
    cb_add_back(&res, indent, "\n");

    /* ============================================
     * copy arguments onto the stack
     */

    log_debug(" - copying arguments onto the stack\n");
    for (size_t i = 0; i < args_mapping.n; i++) {
        cb_t b = loc_args_copy(indent, &args_mapping.locs[i],
                               &args_copy_mapping.locs[i], &fc.lblg);
        if (!cb_is_valid(&b)) {
            context_msg(&args_meta.frags[i],
                        "Error: copying arguments onto the stack has failed.\n");
            goto g_error;
        }
        if (args_copy_mapping.locs[i].true_len <= 16) {
            EXPLAIN(res, indent,
                    "Copy %zu-th argument ('%s', %zu bytes) onto the stack at rbp - "
                    "%" PRId64 ".\n",
                    i, args_copy_mapping.names[i],
                    args_copy_mapping.locs[i].true_len,
                    -(args_copy_mapping.locs[i].stack_offset));
        } else {
            EXPLAIN(res, indent,
                    "Copy %zu-th argument ('%s', pointer) onto the stack at rbp - "
                    "%" PRId64 ".\n",
                    i, args_copy_mapping.names[i],
                    -(args_copy_mapping.locs[i].stack_offset));
        }
        cb_glue_back(&res, &b);
        cb_add_back(&res, indent, "\n");
    }
    log_debug("   - done copying\n");

    /* ============================================
     * function body
     */

    EXPLAIN(res, indent, "Function body begins here.\n");
    cb_glue_back(&res, &body);

    EXPLAIN(res, indent, "Function body ends here.\n");
    EXPLAIN_NL(res);

    /* ============================================
     * end of function, destruction of the stack frame
     */

    EXPLAIN(res, indent, "This is the return point of the function.\n");
    cb_add_back(&res, indent, "%s:\n", fc.return_point_label);

    // end of this function
    cb_add_back(&res, indent, "mov rsp, rbp\n");
    cb_add_back(&res, indent, "pop rbp\n");
    cb_add_back(&res, indent, "ret\n");

    EXPLAIN(res, indent - CB_TAB, "End of function '%s'.\n", node->name->name);
    cb_add_back(&res, indent, "\n");

    struct location_t loc = {
        .type = LOC_SYMBOL,
        .true_len = 0,
        .alignment = 0,
        .symbol = node->name->name,
    };
    log_debug(" - adding location to global scope.\n");
    scope_add(&global_scope, node->name->name, loc);

    return res;

g_error:
    // args request
    free(args_request.names);
    free(args_request.mem_len);
    free(args_request.align);
    free(args_request.chunk1);
    free(args_request.chunk2);

    // args meta
    destroy_func_args_meta(&args_meta);

    // mappings
    vmap_destroy(&args_mapping);
    vmap_destroy(&args_copy_mapping);

    // function context
    scope_destroy(&fc.local_scope);

    cb_destroy(&res);
    return cb_invalid();
}

static cb_t gen_body(int indent, const struct body_node_t *node,
                     struct function_context_t *fc) {
    log_assert(node != NULL);
    return gen_body_list(indent, node->list, fc);
}

static cb_t gen_body_list(int indent, const struct body_list_node_t *node,
                          struct function_context_t *fc) {
    log_assert(node != NULL);
    LOG_ENTER(&node->frag, indent);

    cb_t res;
    cb_init(&res);

    // we need to handle statements from top to bottom...

    if (node->rest != NULL) {
        cb_t r = gen_body_list(indent, node->rest, fc);
        if (!cb_is_valid(&r)) {
            cb_destroy(&res);
            return cb_invalid();
        }
        cb_glue_back(&res, &r);
    }

    if (node->s != NULL) {
        cb_t s = gen_statement(indent, node->s, fc);
        if (!cb_is_valid(&s)) {
            cb_destroy(&res);
            return cb_invalid();
        }
        cb_glue_back(&res, &s);
    }

    return res;
}
static cb_t gen_statement(int indent, const struct statement_node_t *node,
                          struct function_context_t *fc) {
    log_assert(node != NULL);
    LOG_ENTER(&node->frag, indent);

    if (node->vdecl != NULL) {
        cb_t res = gen_variable_declaration(indent, node->vdecl, fc);
        return res;
    } else if (node->alias != NULL) {
        cb_t res = gen_register_alias(indent, node->alias, fc);
        return res;
    } else if (node->nasm != NULL) {
        cb_t res = gen_nasm_block(indent, node->nasm, fc);
        return res;
    } else if (node->expr != NULL) {
        struct expr_gen_t res = gen_expr(indent, node->expr, fc);
        return res.cb;
    }
    return cb_invalid();
}

/*
 * So this works, but it is kinda weird. Code like this will be possible:
 * a: m8
 * CAN ACCESS a HERE
 *
 * if (...) {
 *     b: m8
 *     CAN ACCESS a HERE
 *     CAN ACCESS b HERE
 * }
 *
 * CAN ACCESS a HERE
 * CAN ACCESS b HERE
 *
 * if (...) {
 *     c: m8
 *     CAN ACCESS a HERE
 *     CAN ACCESS b HERE
 *     CAN ACCESS c HERE
 * }
 *
 * CAN ACCESS a HERE
 * CAN ACCESS b HERE
 * CAN ACCESS c HERE
 *
 * this is easy to fix but i am lazy. fix: first parse all local variables, add them
 * to scope. OR make scopes that can remove variables that are outside of their
 * scope. Like each scope has a counter and variables get removed if their counter is
 * bigger than the scope's
 */

static cb_t gen_variable_declaration(int indent,
                                     const struct variable_declaration_node_t *node,
                                     struct function_context_t                *fc) {
    log_assert(node != NULL);
    LOG_ENTER(&node->frag, indent);

    cb_t res;
    cb_init(&res);

    if (scope_has(&fc->local_scope, node->name->name)) {
        context_msg(&node->frag, "Error: duplicate local variable.\n");
        cb_destroy(&res);
        return cb_invalid();
    }

    size_t mem_len = 8;
    size_t align = 8;

    if (node->mem_len != NULL && util_get_mem_len(node->mem_len, &mem_len)) {
        cb_destroy(&res);
        return cb_invalid();
    }
    if (node->align != NULL && util_get_align(node->align, &align)) {
        cb_destroy(&res);
        return cb_invalid();
    }

    log_debug(" - var '%s' of mem_len=%zu and align=%zu changes rbp:\n",
              node->name->name, mem_len, align);
    log_debug("   ^ from %" PRId64 "\n", fc->stack_offset);
    fc->stack_offset -= mem_len;
    fc->stack_offset = util_align_stack_down(fc->stack_offset, align);
    log_debug("   ^ to %" PRId64 "\n", fc->stack_offset);

    struct location_t loc = {
        .type = LOC_STACK,
        .true_len = mem_len,
        .alignment = align,
        .stack_offset = fc->stack_offset,
    };

    scope_add(&fc->local_scope, node->name->name, loc);

    return res;
}

static cb_t gen_register_alias(int indent, const struct register_alias_node_t *node,
                               struct function_context_t *fc) {
    log_assert(node != NULL);
    LOG_ENTER(&node->frag, indent);

    cb_t res;
    cb_init(&res);

    struct gpr_pool_item_t *item;

    if (strcmp(node->reg->name, KW_ALIAS_REG) == 0) {
        item = gpr_pool_find_available(&fc->gpr_pool);
    } else {
        // ugly. switch? tables?
        if (strcmp(node->reg->name, r_rax->qname) == 0) {
            item = gpr_pool_find(&fc->gpr_pool, r_rax);
        } else if (strcmp(node->reg->name, r_rbx->qname) == 0) {
            item = gpr_pool_find(&fc->gpr_pool, r_rbx);
        } else if (strcmp(node->reg->name, r_rcx->qname) == 0) {
            item = gpr_pool_find(&fc->gpr_pool, r_rcx);
        } else if (strcmp(node->reg->name, r_rdx->qname) == 0) {
            item = gpr_pool_find(&fc->gpr_pool, r_rdx);
        } else if (strcmp(node->reg->name, r_rsi->qname) == 0) {
            item = gpr_pool_find(&fc->gpr_pool, r_rsi);
        } else if (strcmp(node->reg->name, r_rdi->qname) == 0) {
            item = gpr_pool_find(&fc->gpr_pool, r_rdi);
        } else if (strcmp(node->reg->name, r_rbp->qname) == 0) {
            item = gpr_pool_find(&fc->gpr_pool, r_rbp);
        } else if (strcmp(node->reg->name, r_rsp->qname) == 0) {
            item = gpr_pool_find(&fc->gpr_pool, r_rsp);
        } else if (strcmp(node->reg->name, r_r8->qname) == 0) {
            item = gpr_pool_find(&fc->gpr_pool, r_r8);
        } else if (strcmp(node->reg->name, r_r9->qname) == 0) {
            item = gpr_pool_find(&fc->gpr_pool, r_r9);
        } else if (strcmp(node->reg->name, r_r10->qname) == 0) {
            item = gpr_pool_find(&fc->gpr_pool, r_r10);
        } else if (strcmp(node->reg->name, r_r11->qname) == 0) {
            item = gpr_pool_find(&fc->gpr_pool, r_r11);
        } else if (strcmp(node->reg->name, r_r12->qname) == 0) {
            item = gpr_pool_find(&fc->gpr_pool, r_r12);
        } else if (strcmp(node->reg->name, r_r13->qname) == 0) {
            item = gpr_pool_find(&fc->gpr_pool, r_r13);
        } else if (strcmp(node->reg->name, r_r14->qname) == 0) {
            item = gpr_pool_find(&fc->gpr_pool, r_r14);
        } else if (strcmp(node->reg->name, r_r15->qname) == 0) {
            item = gpr_pool_find(&fc->gpr_pool, r_r15);
        } else {
            context_msg(&node->frag, "Error: invalid register.\n");
            cb_destroy(&res);
            return cb_invalid();
        }
    }

    if (item == NULL) {
        context_msg(&node->frag, "Error: could not find an available register.\n");
        cb_destroy(&res);
        return cb_invalid();
    }
    if (item->abi_protected) {
        context_msg(
            &node->frag,
            "Note: will use register %s which might cause ABI-related issues.\n",
            item->reg->qname);
    }
    if (!item->available) {
        context_msg(&node->frag, "Note: register %s is already in use.\n",
                    item->reg->qname);
    }

    struct location_t loc = {
        .type = LOC_GPR,
        .true_len = 8,
        .alignment = 8,
        .gpr_reg1 = item->reg,
    };
    item->available = 0;

    log_debug(" - alias '%s' is register %s\n", node->name->name, item->reg->qname);
    scope_add(&fc->local_scope, node->name->name, loc);
    return res;
}

/*
 * 1. Tokens like $var are replaced with:
 *   - rel <symbol>
 *   - rbp + <offset>
 *   - <register name>
 *   depending on the location of the variable.
 *
 * TODO: think how to allow nasm like msg db "$hello" to not be replaced with
 * locations...
 */

static int is_name(char c) {
    return isalnum((unsigned char)c) || c == '_';
}

static cb_t gen_nasm_block(int indent, const struct name_node_t *node,
                           struct function_context_t *fc) {
    log_assert(node != NULL);
    LOG_ENTER(&node->frag, indent);

    cb_t res;
    cb_init(&res);

    char *orig;
    char *str = orig = strdup(node->name);
    log_assert(str != NULL);
    if (strstr(str, KW_NASM_START) != str) {
        goto error;
    }

    str += strlen(KW_NASM_START);

    char *end = strstr(str, KW_NASM_END);
    if (end == NULL) {
        goto error;
    }

    while (str < end && *(str) == ' ') str++;
    while (str < end && *(str) == '\n') str++;
    while (str < end && *(end - 1) == ' ') end--;
    while (str < end && *(end - 1) == '\n') end--;
    *end = '\n';
    *(end + 1) = '\0';

    while (str + 1 < end) {
        char *line_end = strchr(str, '\n');
        *line_end = '\0';

        char *line = strdup(str);
        log_assert(line != NULL);
        char *placeholder;

        str = line_end + 1;
        log_debug(" - checking line '%s' for placeholders..\n", line);

        while (1) {
            if ((placeholder = strchr(line, '$')) == NULL) {
                break;
            }

            char *placeholder_end = placeholder + 1;
            while (is_name(*placeholder_end)) {
                placeholder_end++;
            }

            size_t len = placeholder_end - placeholder;
            if (len <= 1) {
                context_msg(&node->frag, "Error: invalid placeholder.\n");
                free(line);
                cb_destroy(&res);
                return cb_invalid();
            }

            char *cutout = memdup_safe(placeholder + 1, len);
            cutout[len - 1] = '\0';
            cutout = pstr_take(cutout);

            struct location_t loc;

            if (fc != NULL && scope_has(&fc->local_scope, cutout)) {
                loc = scope_get(&fc->local_scope, cutout);
            } else if (scope_has(&global_scope, cutout)) {
                loc = scope_get(&global_scope, cutout);
            } else {
                context_msg(
                    &node->frag,
                    "Error: the compiler is unaware of the placeholder '%s'.",
                    cutout);
                free(line);
                cb_destroy(&res);
                return cb_invalid();
            }

            char *new_line;
            *placeholder = '\0';         // before $
            placeholder_end[-1] = '\0';  // last char of placeholder
            if (loc.type == LOC_GPR || loc.type == LOC_PTR_IN_GPR) {
                log_assert(-1 != asprintf(&new_line, "%s%s%s", line,
                                          loc.gpr_reg1->qname, placeholder_end));
            } else if (loc.type == LOC_SSE) {
                log_assert(-1 != asprintf(&new_line, "%s%s%s", line,
                                          loc.sse_reg1->name, placeholder_end));
            } else if (loc.type == LOC_STACK || loc.type == LOC_PTR_ON_STACK) {
                log_assert(-1 != asprintf(&new_line, "%s%s%s", line,
                                          fmt_stack_offset(loc.stack_offset),
                                          placeholder_end));
            } else if (loc.type == LOC_SYMBOL) {
                log_assert(-1 != asprintf(&new_line, "%s%s%s", line, loc.symbol,
                                          placeholder_end));
            } else {
                context_msg(&node->frag,
                            "Error: placeholder '%s' cannot be substituted.\n",
                            cutout);
                free(line);
                cb_destroy(&res);
                return cb_invalid();
            }

            free(line);
            line = new_line;
            // repeat..
        }

        cb_add_back(&res, 0, "%s\n", line);
        free(line);
    }

    // cb_add_back(&res, 0, "%s", str);
    cb_add_back(&res, 0, "\n");

    free(orig);
    return res;

error:
    context_msg(&node->frag, "Error: invalid NASM block.\n");
    cb_destroy(&res);
    free(orig);
    return cb_invalid();
}
