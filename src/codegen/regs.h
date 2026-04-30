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

static inline int gpr_reg_index(gpr_reg_t NONULL reg) {
    for (int i = 0; i < GPR_REGS; i++) {
        if (reg == r_gpr[i]) {
            return i;
        }
    }
    log_crit("Invalid GPR register.\n");
    return 0;
}

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
