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
typedef const struct gpr_info *gpr_reg;
#define GPR_REGS 16

extern gpr_reg r_rax;
extern gpr_reg r_rbx;
extern gpr_reg r_rcx;
extern gpr_reg r_rdx;
extern gpr_reg r_rdi;
extern gpr_reg r_rsi;
extern gpr_reg r_rsp;
extern gpr_reg r_rbp;
extern gpr_reg r_r8;
extern gpr_reg r_r9;
extern gpr_reg r_r10;
extern gpr_reg r_r11;
extern gpr_reg r_r12;
extern gpr_reg r_r13;
extern gpr_reg r_r14;
extern gpr_reg r_r15;

// ===
// SSE registers
// ===

struct sse_info {
    const char *name;
};
typedef const struct sse_info *sse_reg;
#define SSE_REGS 16

extern sse_reg r_xmm0;
extern sse_reg r_xmm1;
extern sse_reg r_xmm2;
extern sse_reg r_xmm3;
extern sse_reg r_xmm4;
extern sse_reg r_xmm5;
extern sse_reg r_xmm6;
extern sse_reg r_xmm7;
extern sse_reg r_xmm8;
extern sse_reg r_xmm9;
extern sse_reg r_xmm10;
extern sse_reg r_xmm11;
extern sse_reg r_xmm12;
extern sse_reg r_xmm13;
extern sse_reg r_xmm14;
extern sse_reg r_xmm15;

// ===
// GPR registers pool
// ===

struct gpr_pool_item {
    gpr_reg reg;
    uint8_t available : 1;
    uint8_t abi_protected : 1;
};

struct gpr_pool {
    struct gpr_pool_item items[GPR_REGS];
};

void                  gpr_pool_init(struct gpr_pool *pool);
struct gpr_pool_item *gpr_pool_find_available(struct gpr_pool *pool);
struct gpr_pool_item *gpr_pool_find(struct gpr_pool *pool, gpr_reg reg);

// ===
// SSE registers pool
// ===

struct sse_pool_item {
    sse_reg reg;
    uint8_t available : 1;
};

struct sse_pool {
    struct sse_pool_item items[SSE_REGS];
};

void                  sse_pool_init(struct sse_pool *pool);
struct sse_pool_item *sse_pool_find_available(struct sse_pool *pool);
struct sse_pool_item *sse_pool_find(struct sse_pool *pool, sse_reg reg);

