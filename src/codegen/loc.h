#pragma once

#include "../common/common.h"
#include "regs.h"
#include "cb.h"

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
    /* Offset on the stack relative to rbp. */
    LOC_STACK,
    /* Symbol. */
    LOC_SYMBOL,
    /* Int literal. */
    LOC_INT_LITERAL,
    /* Uint literal. */
    LOC_UINT_LITERAL,
    /* Double literal. */
    LOC_DOUBLE_LITERAL
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

        const char *symbol;

        // offset from rbp: rbp + stack_offset
        int64_t stack_offset;

        /* uncomment when the time comes
        struct {
            gpr_reg_t base;
            gpr_reg_t index;
            uint8_t   scale;
            int64_t   offset;
        } scaled;*/

        int64_t int_literal;

        uint64_t uint_literal;

        double double_literal;
    };
};

/* Copies data between two locations. LOC_PTR_IN_REG and LOC_PTR_ON_STACK are
 * treated as simply 8-byte long data, and are not *dereferenced* if ykwim.
 *
 * This function should only be used to transfer function arguments from their
 * locations onto the stack. It uses R10 register.*/
cb_t loc_args_copy(int indent, struct location_t *from,
                          struct location_t *to);
