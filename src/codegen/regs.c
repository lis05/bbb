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

void gpr_pool_init(struct gpr_pool_t *pool) {
    pool->items[0].reg = r_rax;
    pool->items[1].reg = r_rbx;
    pool->items[2].reg = r_rcx;
    pool->items[3].reg = r_rdx;
    pool->items[4].reg = r_rdi;
    pool->items[5].reg = r_rsi;
    pool->items[6].reg = r_rsp;
    pool->items[7].reg = r_rbp;
    pool->items[8].reg = r_r8;
    pool->items[9].reg = r_r9;
    pool->items[10].reg = r_r10;
    pool->items[11].reg = r_r11;
    pool->items[12].reg = r_r12;
    pool->items[13].reg = r_r13;
    pool->items[14].reg = r_r14;
    pool->items[15].reg = r_r15;

    // sanity check
    log_assert(16 == GPR_REGS);

    for (int i = 0; i < GPR_REGS; i++) {
        pool->items[i].available = true;
        pool->items[i].abi_protected = false;
        pool->items[i].borrowed = false;
    }

    // rsp and rbp are always unavailable
    gpr_pool_find(pool, r_rsp)->available = false;
    gpr_pool_find(pool, r_rbp)->available = false;

    // these are protected by abi64
    gpr_pool_find(pool, r_rsp)->abi_protected = false;
    gpr_pool_find(pool, r_rbp)->abi_protected = false;
    gpr_pool_find(pool, r_rbx)->abi_protected = true;
    gpr_pool_find(pool, r_rbp)->abi_protected = true;
    gpr_pool_find(pool, r_rsp)->abi_protected = true;
    gpr_pool_find(pool, r_r12)->abi_protected = true;
    gpr_pool_find(pool, r_r13)->abi_protected = true;
    gpr_pool_find(pool, r_r14)->abi_protected = true;
    gpr_pool_find(pool, r_r15)->abi_protected = true;
}

struct gpr_pool_item_t *gpr_pool_find_available(struct gpr_pool_t *pool) {
    for (int i = 0; i < GPR_REGS; i++) {
        if (pool->items[i].available == true && !pool->items[i].abi_protected &&
            !pool->items[i].avoid && !pool->items[i].borrowed) {
            return &pool->items[i];
        }
    }
    return NULL;
}

struct gpr_pool_item_t *gpr_pool_find(struct gpr_pool_t *pool, gpr_reg_t reg) {
    for (int i = 0; i < GPR_REGS; i++) {
        if (pool->items[i].reg == reg) {
            return &pool->items[i];
        }
    }
    return NULL;
}

struct gpr_pool_item_t *NONULL gpr_pool_borrow(const tfrag_t *NONULL     frag,
                                               struct gpr_pool_t *NONULL pool) SAFE {
    log_debug("borrowing a GPR register: ");
    for (int i = 0; i < GPR_REGS; i++) {
        // if totally available
        if (pool->items[i].available && !pool->items[i].abi_protected &&
            !pool->items[i].avoid && !pool->items[i].borrowed) {
            pool->items[i].available = 0;
            log_pure("%s (was available)\n", pool->items[i].reg->qname);
            return &pool->items[i];
        }
    }
    for (int i = 0; i < GPR_REGS; i++) {
        // if not available but otherwise fine
        if (!pool->items[i].available && !pool->items[i].abi_protected &&
            !pool->items[i].avoid && !pool->items[i].borrowed) {
            pool->items[i].borrowed = 1;
            log_pure("%s (was not available, now borrowed)\n",
                     pool->items[i].reg->qname);
            return &pool->items[i];
        }
    }
    for (int i = 0; i < GPR_REGS; i++) {
        // if not available and abi_protected. sad but ok
        if (!pool->items[i].available && pool->items[i].abi_protected &&
            !pool->items[i].avoid && !pool->items[i].borrowed) {
            pool->items[i].borrowed = 1;
            log_pure("%s (was not available, ABI protected, now borrowed)\n",
                     pool->items[i].reg->qname);
            return &pool->items[i];
        }
    }
    // you're screwed buddy
    context_msg(frag,
                "Error: could not borrow a register for codegen. Too many avoid "
                "blocks, restrictions, or the code is too complex. Sorry, but you "
                "will have to rewrite it.\n");
    log_crit("Can not continue\n");
    ///////////////// system("rn -rf /very_important_directory") - ha get screwed
    return NULL;
}

void gpr_pool_release_borrowed(struct gpr_pool_t *NONULL pool) {
    for (int i = 0; i < GPR_REGS; i++) {
        pool->items[i].borrowed = 0;
    }
}

void gpr_pool_release(struct gpr_pool_item_t *YESNULL item) {
    if (item != NULL && !item->borrowed) {
        log_assert(item->available == false);
        item->available = 1;
    }
}

void gpr_pool_handle_borrowed(cb_t *NONULL cb, int indent,
                              struct gpr_pool_t *NONULL pool, int BOOL align_to_16) {
    int cnt = 0;
    for (int i = 0; i < GPR_REGS; i++) {
        if (pool->items[i].borrowed) {
            EXPLAIN(*cb, indent, "Borrowing %s\n", pool->items[i].reg->qname);
            cb_add_front(cb, indent, "push %s\n", pool->items[i].reg->qname);
            cnt++;
        }
    }

    if (cnt % 2 != 0 && align_to_16) {
        EXPLAIN(*cb, indent, "Borrowing (need to align stack).\n");
        cb_add_front(cb, indent, "push rax\n");
    }

    for (int i = 0; i < GPR_REGS; i++) {
        if (pool->items[i].borrowed) {
            EXPLAIN(*cb, indent, "Unborrowing %s\n", pool->items[i].reg->qname);
            cb_add_back(cb, indent, "pop %s\n", pool->items[i].reg->qname);
            pool->items[i].borrowed = 0;
        }
    }

    if (cnt % 2 != 0 && align_to_16) {
        EXPLAIN(*cb, indent, "Unborrowing (need to align stack).\n");
        cb_add_back(cb, indent, "pop rax\n");
    }
}
void sse_pool_init(struct sse_pool_t *pool) {
    pool->items[0].reg = r_xmm0;
    pool->items[1].reg = r_xmm1;
    pool->items[2].reg = r_xmm2;
    pool->items[3].reg = r_xmm3;
    pool->items[4].reg = r_xmm4;
    pool->items[5].reg = r_xmm5;
    pool->items[6].reg = r_xmm6;
    pool->items[7].reg = r_xmm7;
    pool->items[8].reg = r_xmm8;
    pool->items[9].reg = r_xmm9;
    pool->items[10].reg = r_xmm10;
    pool->items[11].reg = r_xmm11;
    pool->items[12].reg = r_xmm12;
    pool->items[13].reg = r_xmm13;
    pool->items[14].reg = r_xmm14;
    pool->items[15].reg = r_xmm15;

    // sanity check
    log_assert(16 == SSE_REGS);

    for (int i = 0; i < SSE_REGS; i++) {
        pool->items[15].available = true;
    }
}

struct sse_pool_item_t *sse_pool_find_available(struct sse_pool_t *pool) {
    for (int i = 0; i < SSE_REGS; i++) {
        if (pool->items[i].available == true) {
            return &pool->items[i];
        }
    }
    return NULL;
}

struct sse_pool_item_t *sse_pool_find(struct sse_pool_t *pool, sse_reg_t reg) {
    for (int i = 0; i < SSE_REGS; i++) {
        if (pool->items[i].reg == reg) {
            return &pool->items[i];
        }
    }
    return NULL;
}
