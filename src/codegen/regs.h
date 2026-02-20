#pragma once

#include "../common/common.h"

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

extern gpr_reg_t r_rax;
extern gpr_reg_t r_rbx;
extern gpr_reg_t r_rcx;
extern gpr_reg_t r_rdx;
extern gpr_reg_t r_rdi;
extern gpr_reg_t r_rsi;
extern gpr_reg_t r_rsp;
extern gpr_reg_t r_rbp;
extern gpr_reg_t r_r8;
extern gpr_reg_t r_r9;
extern gpr_reg_t r_r10;
extern gpr_reg_t r_r11;
extern gpr_reg_t r_r12;
extern gpr_reg_t r_r13;
extern gpr_reg_t r_r14;
extern gpr_reg_t r_r15;

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
    uint8_t   available : 1;
    uint8_t   abi_protected : 1;
};

struct gpr_pool_t {
    struct gpr_pool_item_t items[GPR_REGS];
};

void                    gpr_pool_init(struct gpr_pool_t *pool);
struct gpr_pool_item_t *gpr_pool_find_available(struct gpr_pool_t *pool);
struct gpr_pool_item_t *gpr_pool_find(struct gpr_pool_t *pool, gpr_reg_t reg);

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

