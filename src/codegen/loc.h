#pragma once

#include "../common/common.h"
#include "../parser/tfrag.h"
#include "cb.h"
#include "lblg.h"
#include "regs.h"

enum location_type {
    /* A single GPR register. */
    LOC_GPR = 0,
    /* A single SSE register. */
    LOC_SSE,
    /* Longer (9..16 bytes) value in GPR and GPR registers. */
    LOC_GPR_GPR,
    /* Longer (9..16 bytes) value in GPR and SSE registers. */
    LOC_GPR_SSE,
    /* Longer (9..16 bytes) value in SSE and GPR registers. */
    LOC_SSE_GPR,
    /* Longer (9..16 bytes) value in SSE and SSE registers. */
    LOC_SSE_SSE,
    /* Pointer to data is stored in a GPR register. */
    LOC_PTR_IN_GPR,
    /* Pointer to data is stored on the stack. */
    LOC_PTR_ON_STACK,
    /* Memory address. */
    LOC_MEM,
    /* Symbol. */
    LOC_SYMBOL,
    /* Int literal. */
    LOC_INT_LITERAL,
    /* Uint literal. */
    LOC_UINT_LITERAL,
};

struct location_t {
    enum location_type type;

    /* True data length is used to copy data between places.
     * When the data is split between 2 chunks, the first one will always be of 8
     * bytes; the second chunk, thus, will have true_len - 8 of meaningful data. */
    size_t true_len;

    /* Same as above, used to copying. */
    size_t alignment;

    union {
        struct {
            union {
                gpr_reg_t gpr_reg1;
                sse_reg_t sse_reg1;
            };
            union {
                gpr_reg_t gpr_reg2;
                sse_reg_t sse_reg2;
            };
        };

        // base + index * scale + offset
        struct {
            gpr_reg_t base;
            gpr_reg_t index;
            size_t scale;
            int64_t offset;
        };

        const char *symbol;

        int64_t int_literal;

        uint64_t uint_literal;
    };
};

/* Copies data between two locations. LOC_PTR_IN_REG and LOC_PTR_ON_STACK are
 * treated as simply 8-byte long data, and are not *dereferenced* if ykwim.
 *
 * This function should only be used to transfer function arguments from their
 * locations onto the stack. It uses R10 register.*/
cb_t loc_args_copy(int indent, struct location_t *from, struct location_t *to,
                   struct label_generator_t *lblg, struct gpr_pool_t *pool,
                   const tfrag_t *frag);

/* Copies a number of bytes from one location to another. */
cb_t loc_move_data(int indent, struct location_t *from, struct location_t *to,
                   size_t len, struct gpr_pool_t *pool, const tfrag_t *frag);
