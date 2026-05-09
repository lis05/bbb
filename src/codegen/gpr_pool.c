#include "gpr_pool.h"

#include "../common/common.h"
#include "../parser/error.h"
#include "gen.h"

void gpr_pool_init(struct gpr_pool_t *NONULL pool) MEMSAFE {
    for (int i = 0; i < GPR_REGS; i++) {
        pool->items[i].reg = r_gpr[i];
        pool->items[i].status = GPIS_AVAILABLE;
        pool->items[i].is_output = false;
    }

    // rsp and rbp are always unavailable
    pool->items[gpr_reg_index(r_rsp)].status = GPIS_FORBIDDEN;
    pool->items[gpr_reg_index(r_rbp)].status = GPIS_FORBIDDEN;

    // these are protected by abi64
    pool->items[gpr_reg_index(r_rbx)].status = GPIS_OCCUPIED;
    pool->items[gpr_reg_index(r_r12)].status = GPIS_OCCUPIED;
    pool->items[gpr_reg_index(r_r13)].status = GPIS_OCCUPIED;
    pool->items[gpr_reg_index(r_r14)].status = GPIS_OCCUPIED;
    pool->items[gpr_reg_index(r_r15)].status = GPIS_OCCUPIED;
}

gpr_reg_t NONULL gpr_pool_please(struct gpr_pool_t *NONULL pool,
                                 const tfrag_t *NONULL     frag) MEMSAFE {
    for (int i = 0; i < GPR_REGS; i++) {
        if (pool->items[i].status == GPIS_AVAILABLE) {
            if (pool->items[i].is_output) {
                continue;
            }
            pool->items[i].status = GPIS_OCCUPIED;
            return pool->items[i].reg;
        }
    }

    for (int i = 0; i < GPR_REGS; i++) {
        if (pool->items[i].status == GPIS_OCCUPIED) {
            if (pool->items[i].is_output) {
                continue;
            }
            pool->items[i].status = GPIS_BORROWED;
            return pool->items[i].reg;
        }
    }

    context_msg(frag,
                "Error: failed to allocate a register from the GPR pool: no "
                "available registers.\n");
    log_crit("Quitting.\n");
    return NULL;
}

gpr_reg_t NONULL gpr_pool_available(struct gpr_pool_t *NONULL pool,
                                    const tfrag_t *NONULL     frag) MEMSAFE {
    for (int i = 0; i < GPR_REGS; i++) {
        if (pool->items[i].status == GPIS_AVAILABLE) {
            if (pool->items[i].is_output) {
                continue;
            }
            pool->items[i].status = GPIS_OCCUPIED;
            return pool->items[i].reg;
        }
    }

    context_msg(
        frag,
        "Error: failed to allocate an avaialble register from the GPR pool: no "
        "available registers.\n");
    log_crit("Quitting.\n");
    return NULL;
}

void gpr_pool_thanks(struct gpr_pool_t *NONULL pool, cb_t *NONULL cb, int indent,
                     int BOOL align_to_16) MEMSAFE {
    int cnt = 0;
    for (int i = 0; i < GPR_REGS; i++) {
        if (pool->items[i].status == GPIS_BORROWED) {
            cb_add_front(cb, indent, "push %s\n", pool->items[i].reg->qname);
            RV_EXPLAIN(*cb, indent, "Borrowing %s\n", pool->items[i].reg->qname);
            cnt++;
        }
    }

    if (cnt % 2 != 0 && align_to_16) {
        cb_add_front(cb, indent, "push rax\n");
        RV_EXPLAIN(*cb, indent, "Borrowing (need to align stack).\n");
    }

    for (int i = 0; i < GPR_REGS; i++) {
        if (pool->items[i].status == GPIS_BORROWED) {
            EXPLAIN(*cb, indent, "Unborrowing %s\n", pool->items[i].reg->qname);
            cb_add_back(cb, indent, "pop %s\n", pool->items[i].reg->qname);
        }
    }

    if (cnt % 2 != 0 && align_to_16) {
        EXPLAIN(*cb, indent, "Unborrowing (need to align stack).\n");
        cb_add_back(cb, indent, "pop rax\n");
    }
}

void gpr_pool_output(struct gpr_pool_t *NONULL pool, gpr_reg_t NONULL reg) {
    struct gpr_pool_item_t *item = gpr_pool_item(pool, reg);
    item->status = GPIS_FORBIDDEN;
    item->is_output = true;
}

struct gpr_pool_item_t *NONULL NOFREE gpr_pool_item(struct gpr_pool_t *NONULL pool,
                                                    gpr_reg_t                 reg) {
    return &pool->items[gpr_reg_index(reg)];
}
