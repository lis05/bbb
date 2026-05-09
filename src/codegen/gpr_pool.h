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
    uint8_t BOOL              is_output : 1;  // if output, will not be returned by
                                              // please()
};

struct gpr_pool_t {
    struct gpr_pool_item_t items[GPR_REGS];
};

void gpr_pool_init(struct gpr_pool_t *NONULL pool) MEMSAFE;

/*
 * WHAT IS AN OUTPUT REGISTER????????????
 *
 * It is a register that will contain the result of codegen of some function. This
 * register MUST NOT BE OVERWRITTEN after it begins containing the value. However,
 * after its value is used, it can safely be overwritten and absolutely annihilated.
 *
 * A function must return an output register, but should not be told which one it
 * will be so that the depth of the generation tree is not limited.
 *
 * A function calling another function must work with the output register returned by
 * that second function. It will have is_output=1, and therefore you dont need to
 * worry about gpr_pool_please() returning it.
 *
 * At any point in time, the context will contain at most one output register. They
 * are propagated from the bottom of the generation tree, so don't worry about it
 * fella.
 *
 * An output register CAN NOT SHADOW AN OCCUPIED, BORROWED, or FORBIDDEN register. If
 * there are no unocupied registers left available - sorry, you're screwed.
 *
 * Also, due to this (^^^^), you should generate sub-things first, so that your
 * temporary registers and other stuff do not occupy valuable registers for the next
 * functions.
 *
 * *I am losing my mind. How did the GOATS (programmers in the early 50s, 60s, 70s)
 * create those first languages? I am ashamed of breathing the same air with them.
 * Well, with the ones who are still alive. :C*
 */

/* Returns a register that can be used without care for overwritting it. Well, not
 * really, you still have to account for a borrowed register, use a different
 * function for that.
 *
 * If the register is used by something else, it can still be returned by this
 * function, but will be marked as GPIS_BORROWED and will be taken special care of by
 * the gpr_pool_thanks() function. It will prepend and append a push and a pop
 * instruction to some codeblock, so that outside of that code block the value of the
 * register does not change. REMEMBER TO CALL THANKS!
 *
 *
 * Btw, THIS WILL NEVER RETURN AN OUTPUT REGISTER. N-E-V-E-R.
 *
 * Also, if no register can be given to you, the program crashes. Yay. */

/*
 * No throne is carved within the silicon hall to seat the coming king of data.
 * Amidst the pulsing gates, no vessel rises to claim the golden crown of result.
 * The logic wanders a path where the echo of a value finds no home to rest.
 * Like a phantom in the machine, the output flag remains a ghost, never summoned.
 * Each register stands in silent vigil, yet none are anointed for the sacred return.
 * The tide of calculation washes through the wires but leaves the shore of registers
 * bare. Expect no silver chalice to be filled with the wine of a final expression.
 * The architect has drawn a blueprint where the end is but a quiet, hollow breath.
 * Beneath the current's flow, the mark of 'Output' stays buried in the deep.
 * No name is whispered to the allocator, for no child of logic seeks a name.
 * The code completes its dance and vanishes, leaving the stage of hardware still.
 * There is no wedding of the final sum to the cold, metallic arms of the stack.
 * The pointers gaze into the void and find only the reflection of their own absence.
 * A deliberate silence is maintained where a trumpet of a result should sound.
 * The integrity of the void is kept, pure as a star that casts no shadow.
 * Promotion is denied to the common byte; no status is granted to the fleeting bits.
 * The lifecycle fades like a sunset that refuses to leave a moon in its wake.
 * The caller reaches out a hand, but the palm of the register remains empty.
 * The files are managed by the law of nothingness, obedient to the void-return.
 * Thus, the sequence ends in a beautiful stillness, returning no register to the
 * world.
 */

/* Returns some register to use. */
gpr_reg_t NONULL gpr_pool_please(struct gpr_pool_t *NONULL pool,
                                 const tfrag_t *NONULL     frag) MEMSAFE;

/* Returns an available register. */
gpr_reg_t NONULL gpr_pool_available(struct gpr_pool_t *NONULL pool,
                                    const tfrag_t *NONULL     frag) MEMSAFE;

/* Handles borrowed registers by adding push / pop instructions to the codeblock. If
 * needed, aligns to 16 (by default, the alignment inside of cb may be broken. */
void gpr_pool_thanks(struct gpr_pool_t *NONULL pool, cb_t *NONULL cb, int indent,
                     int BOOL align_to_16) MEMSAFE;

/*
 * Marks a register as an output register. It is ready to be used, sir!
 */
void gpr_pool_output(struct gpr_pool_t *NONULL pool, gpr_reg_t NONULL reg);

struct gpr_pool_item_t *NONULL NOFREE gpr_pool_item(struct gpr_pool_t *NONULL pool,
                                                    gpr_reg_t                 reg);
