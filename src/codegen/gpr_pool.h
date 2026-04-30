#pragma once

#include "../common/common.h"
#include "regs.h"

enum gpr_pool_item_status : int8_t {
    /* Register can be used safely. */
    GPIS_AVAILABLE = 0,
    /* Register is used by some other unrelated part of the code and can be borrowed.
     */
    GPIS_OCCUPIED,
    /* Like GPIS_OCCUPIED, but the register has been borrowed and cannot be used
     * anymore. */
    /* If borrowed, the register must be push on the stack before it is intended to
     * be used so that its original value is not overwritten. Only a register with
     * status GPIS_OCCUPIED can be borrowed; GPIS_FORBIDDEN is really, really
     * forbidden. */
    GPIS_BORROWED,
    /* Register is forbidden to be used under any circumstance. */
    GPIS_FORBIDDEN,
};

struct gpr_pool_item_t {
    gpr_reg_t                 reg;
    enum gpr_pool_item_status status;
    uint8_t BOOL              is_output : 1;
};

struct gpr_pool_t {
    struct gpr_pool_item_t items[GPR_REGS];
};

void gpr_pool_init(struct gpr_pool_t *NONULL pool) MEMSAFE;

enum gpr_pool_register_please {
    /* We ask to get an output register - therefore, it cannot borrow another output
     * register. */
    REGISTER_OUTPUT,
    /* Will. */
    REGISTER_ANY
};

/* Returns a register that can be used without care for overwritting it. Well, not
 * really, you still have to account for a borrowed register, use a different
 * function for that.
 *
 * Also, if no register can be given to you, the program crashes. Yay. */
gpr_reg_t NONULL gpr_pool_please(struct gpr_pool_t *NONULL     pool,
                                 const tfrag_t *NONULL         frag,
                                 enum gpr_pool_register_please reg) MEMSAFE;

/* Handles borrowed registers by adding push / pop instructions to the codeblock. If
 * needed, aligns to 16 (by default, the alignment inside of cb may be broken. */
void gpr_pool_thanks(struct gpr_pool_t *NONULL pool, cb_t *NONULL cb, int indent,
                     int BOOL align_to_16) MEMSAFE;

/* Sets appropriate status and flags for a register that is intended to be an output.
 * */
void gpr_pool_output(struct gpr_pool_t *NONULL pool, gpr_reg_t NONULL reg);

