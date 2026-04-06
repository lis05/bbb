#pragma once

#include "../common/common.h"
#include "../parser/tfrag.h"
#include "cb.h"

// ===
// GPR registers
// ===

struct gpr_info {
    const char *qname;
    const char *dname;
    const char *wname;
    const char *bname;
};
typedef const struct gpr_info *gpr_reg_t;
#define GPR_REGS 16

extern const gpr_reg_t r_rax;
extern const gpr_reg_t r_rbx;
extern const gpr_reg_t r_rcx;
extern const gpr_reg_t r_rdx;
extern const gpr_reg_t r_rdi;
extern const gpr_reg_t r_rsi;
extern const gpr_reg_t r_rsp;
extern const gpr_reg_t r_rbp;
extern const gpr_reg_t r_r8;
extern const gpr_reg_t r_r9;
extern const gpr_reg_t r_r10;
extern const gpr_reg_t r_r11;
extern const gpr_reg_t r_r12;
extern const gpr_reg_t r_r13;
extern const gpr_reg_t r_r14;
extern const gpr_reg_t r_r15;
extern const gpr_reg_t r_gpr[GPR_REGS];

// ===
// SSE registers
// ===

struct sse_info {
    const char *name;
};
typedef const struct sse_info *sse_reg_t;
#define SSE_REGS 16

extern sse_reg_t r_xmm0;
extern sse_reg_t r_xmm1;
extern sse_reg_t r_xmm2;
extern sse_reg_t r_xmm3;
extern sse_reg_t r_xmm4;
extern sse_reg_t r_xmm5;
extern sse_reg_t r_xmm6;
extern sse_reg_t r_xmm7;
extern sse_reg_t r_xmm8;
extern sse_reg_t r_xmm9;
extern sse_reg_t r_xmm10;
extern sse_reg_t r_xmm11;
extern sse_reg_t r_xmm12;
extern sse_reg_t r_xmm13;
extern sse_reg_t r_xmm14;
extern sse_reg_t r_xmm15;

// ===
// GPR registers pool
// ===

struct gpr_pool_item_t {
    gpr_reg_t reg;
    uint8_t   available : 1;      // if the register is used somewhere else
    uint8_t   abi_protected : 1;  // if it is "protected" by the abi
    uint8_t   avoid : 1;  // totally unavailable, must not use under no circumstance
    uint8_t   borrowed : 1;  // not available but borrowed, must be returned
};

struct gpr_pool_t {
    struct gpr_pool_item_t items[GPR_REGS];
};

void                           gpr_pool_init(struct gpr_pool_t *pool);
struct gpr_pool_item_t        *gpr_pool_find(struct gpr_pool_t *pool, gpr_reg_t reg);
struct gpr_pool_item_t        *gpr_pool_find_available(struct gpr_pool_t *pool);
struct gpr_pool_item_t *NONULL gpr_pool_borrow(const tfrag_t *NONULL     frag,
                                               struct gpr_pool_t *NONULL pool) SAFE;
void gpr_pool_release_borrowed(struct gpr_pool_t *NONULL pool);
void gpr_pool_release(struct gpr_pool_item_t *YESNULL item);  // only for unoccupied
void gpr_pool_handle_borrowed(cb_t *NONULL cb, int indent, struct gpr_pool_t *NONULL pool,
                              int BOOL align_to_16);

// ===
// SSE registers pool
// ===

struct sse_pool_item_t {
    sse_reg_t reg;
    uint8_t   available : 1;
};

struct sse_pool_t {
    struct sse_pool_item_t items[SSE_REGS];
};

void                    sse_pool_init(struct sse_pool_t *pool);
struct sse_pool_item_t *sse_pool_find_available(struct sse_pool_t *pool);
struct sse_pool_item_t *sse_pool_find(struct sse_pool_t *pool, sse_reg_t reg);

