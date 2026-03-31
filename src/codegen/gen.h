#pragma once

#include "../common/common.h"
#include "../parser/ast.h"
#include "../parser/error.h"
#include "cb.h"
#include "fc.h"
#include "kw.h"
#include "layout.h"
#include "scope.h"
#include "settings.h"
#include "util.h"
#include "vmap.h"

#define EXPLAIN(cbref, indent, ...)                          \
    do {                                                     \
        if (add_explanatory_comments) {                      \
            cb_add_back(&(cbref), indent, "; " __VA_ARGS__); \
        }                                                    \
    } while (0)

#define EXPLAIN_NL(cbref)                   \
    do {                                    \
        if (add_explanatory_comments) {     \
            cb_add_back(&(cbref), 0, "\n"); \
        }                                   \
    } while (0)

#define LOG_ENTER(frag_ptr, indent)                                   \
    log_debug("Entered source %zu:%zu ... %zu:%zu with indent=%zu\n", \
              (frag_ptr)->begin_line + 1, (frag_ptr)->begin_col + 1,  \
              (frag_ptr)->end_line + 1, (frag_ptr)->end_col, (indent));

/* Has lower priority than local scope. */
extern struct scope_t global_scope;

/* Strings and floats.
 * All strings and all floats will be added here. Their locations will be added to
 * global scope, with names consisting of a space, s / f (for string / float), and
 * then the value of the string/float. This way there will be no collisions. */
extern cb_t data_section;

cb_t gen(struct program_node_t *prog);

