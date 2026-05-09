#include "regs.h"

#include "../common/common.h"
#include "../parser/error.h"
#include "gen.h"

static const struct gpr_info _r_rax = {"rax", "eax", "ax", "al"};
static const struct gpr_info _r_rbx = {"rbx", "ebx", "bx", "bl"};
static const struct gpr_info _r_rcx = {"rcx", "ecx", "cx", "cl"};
static const struct gpr_info _r_rdx = {"rdx", "edx", "dx", "dl"};
static const struct gpr_info _r_rdi = {"rdi", "edi", "di", "dil"};
static const struct gpr_info _r_rsi = {"rsi", "esi", "si", "sil"};
static const struct gpr_info _r_rsp = {"rsp", "esp", "sp", "spl"};
static const struct gpr_info _r_rbp = {"rbp", "ebp", "bp", "bpl"};
static const struct gpr_info _r_r8 = {"r8", "r8d", "r8w", "r8b"};
static const struct gpr_info _r_r9 = {"r9", "r9d", "r9w", "r9b"};
static const struct gpr_info _r_r10 = {"r10", "r10d", "r10w", "r10b"};
static const struct gpr_info _r_r11 = {"r11", "r11d", "r11w", "r11b"};
static const struct gpr_info _r_r12 = {"r12", "r12d", "r12w", "r12b"};
static const struct gpr_info _r_r13 = {"r13", "r13d", "r13w", "r13b"};
static const struct gpr_info _r_r14 = {"r14", "r14d", "r14w", "r14b"};
static const struct gpr_info _r_r15 = {"r15", "r15d", "r15w", "r15b"};
static const struct sse_info _r_xmm0 = {"xmm0"};
static const struct sse_info _r_xmm1 = {"xmm1"};
static const struct sse_info _r_xmm2 = {"xmm2"};
static const struct sse_info _r_xmm3 = {"xmm3"};
static const struct sse_info _r_xmm4 = {"xmm4"};
static const struct sse_info _r_xmm5 = {"xmm5"};
static const struct sse_info _r_xmm6 = {"xmm6"};
static const struct sse_info _r_xmm7 = {"xmm7"};
static const struct sse_info _r_xmm8 = {"xmm8"};
static const struct sse_info _r_xmm9 = {"xmm9"};
static const struct sse_info _r_xmm10 = {"xmm10"};
static const struct sse_info _r_xmm11 = {"xmm11"};
static const struct sse_info _r_xmm12 = {"xmm12"};
static const struct sse_info _r_xmm13 = {"xmm13"};
static const struct sse_info _r_xmm14 = {"xmm14"};
static const struct sse_info _r_xmm15 = {"xmm15"};

const gpr_reg_t r_rax = &_r_rax;
const gpr_reg_t r_rbx = &_r_rbx;
const gpr_reg_t r_rcx = &_r_rcx;
const gpr_reg_t r_rdx = &_r_rdx;
const gpr_reg_t r_rdi = &_r_rdi;
const gpr_reg_t r_rsi = &_r_rsi;
const gpr_reg_t r_rsp = &_r_rsp;
const gpr_reg_t r_rbp = &_r_rbp;
const gpr_reg_t r_r8 = &_r_r8;
const gpr_reg_t r_r9 = &_r_r9;
const gpr_reg_t r_r10 = &_r_r10;
const gpr_reg_t r_r11 = &_r_r11;
const gpr_reg_t r_r12 = &_r_r12;
const gpr_reg_t r_r13 = &_r_r13;
const gpr_reg_t r_r14 = &_r_r14;
const gpr_reg_t r_r15 = &_r_r15;
sse_reg_t       r_xmm0 = &_r_xmm0;
sse_reg_t       r_xmm1 = &_r_xmm1;
sse_reg_t       r_xmm2 = &_r_xmm2;
sse_reg_t       r_xmm3 = &_r_xmm3;
sse_reg_t       r_xmm4 = &_r_xmm4;
sse_reg_t       r_xmm5 = &_r_xmm5;
sse_reg_t       r_xmm6 = &_r_xmm6;
sse_reg_t       r_xmm7 = &_r_xmm7;
sse_reg_t       r_xmm8 = &_r_xmm8;
sse_reg_t       r_xmm9 = &_r_xmm9;
sse_reg_t       r_xmm10 = &_r_xmm10;
sse_reg_t       r_xmm11 = &_r_xmm11;
sse_reg_t       r_xmm12 = &_r_xmm12;
sse_reg_t       r_xmm13 = &_r_xmm13;
sse_reg_t       r_xmm14 = &_r_xmm14;
sse_reg_t       r_xmm15 = &_r_xmm15;

const gpr_reg_t r_gpr[GPR_REGS] = {r_rax, r_rbx, r_rcx, r_rdx, r_rdi, r_rsi,
                                   r_rsp, r_rbp, r_r8,  r_r9,  r_r10, r_r11,
                                   r_r12, r_r13, r_r14, r_r15};
// sse_reg_t r_sse[SSE_REGS] = {r_xmm0,  r_xmm1,  r_xmm2,  r_xmm3, r_xmm4,  r_xmm5,
//                              r_xmm6,  r_xmm7,  r_xmm8,  r_xmm9, r_xmm10, r_xmm11,
//                              r_xmm12, r_xmm13, r_xmm14, r_xmm15};
