#include "vmap.h"

#include "regs.h"
#include "util.h"

static const char *chunk_to_name[] = {"INT", "SSE", "MEM"};

void vmap_destroy(struct vmap_t *vmap) {
    free(vmap->names);
    free(vmap->locs);
}

struct vmap_t vmap_args(const struct vmap_args_request_t *req) {
    log_debug("=== ABI VMAP_ARGS REQUEST n=%zu ===\n", req->n);

#define TOTAL_GPR 6
    gpr_reg_t usable_gpr[TOTAL_GPR] = {r_rdi, r_rsi, r_rdx, r_rcx, r_r8, r_r9};
    size_t    usable_gpr_ptr = 0;

#define TOTAL_SSE 8
    sse_reg_t usable_sse[TOTAL_SSE] = {r_xmm0, r_xmm1, r_xmm2, r_xmm3,
                                       r_xmm4, r_xmm5, r_xmm6, r_xmm7};
    size_t    usable_sse_ptr = 0;

    size_t rbp_offset = 16;  // RBP at +0, RET at +8

    struct vmap_t answer = {0};
    answer.n = req->n;
    if (req->names != NULL) {
        answer.names = (const char **)malloc(req->n * sizeof(const char *));
        log_assert(answer.names != NULL);
        memcpy(answer.names, req->names, answer.n * sizeof(const char *));
    }
    answer.locs = (struct location_t *)malloc(req->n * sizeof(struct location_t));
    log_assert(answer.locs != NULL);

    // ==================================== actual algo

    for (size_t i = 0; i < req->n; i++) {
        size_t how_many_chunks = req->mem_len[i] / 8;

        const char *name = req->names != NULL ? req->names[i] : "NONAME";
        size_t      mem_len = req->mem_len[i];
        size_t      align = req->align[i];
        size_t      chunk1 = req->chunk1[i];
        size_t      chunk2 = req->chunk2[i];

        log_pure(
            "=== item %zu (%s): mem_len=%zu, align=%zu, chunk1=%s, chunk2=%s\n"
            "===    ugp=%zu, usp=%zu, rbpo=%zu\n"
            "===    how_many_chunks=%zu\n",
            i, name, mem_len, align, chunk_to_name[chunk1], chunk_to_name[chunk2],
            usable_gpr_ptr, usable_sse_ptr, rbp_offset, how_many_chunks);

        if (chunk1 == VMAP_CHUNK_MEM || chunk2 == VMAP_CHUNK_MEM) {
            log_pure("=== at least one chuck is MEM, goes on the stack\n");
            goto goes_on_the_stack;
        }

        if (how_many_chunks >= 3) {
            log_pure("=== 3 or more chunks, goes as a pointer\n");
            if (usable_gpr_ptr < TOTAL_GPR) {
                log_pure("=== ^^^ goes into %s\n",
                         usable_gpr[usable_gpr_ptr]->qname);
                struct location_t loc = {
                    .type = LOC_PTR_IN_GPR,
                    .true_len = mem_len,
                    .alignment = align,
                    .gpr_reg1 = usable_gpr[usable_gpr_ptr++],
                };
                answer.locs[i] = loc;
                log_pure("\n");
            } else {
                log_pure("=== ^^^ not enough registers, goes on the stack\n");
                size_t aligned_size = 8;
                log_pure("=== decided: goes on the stack: aligned_to8_size=%zu\n",
                         aligned_size);
                size_t old_rbp_offset = rbp_offset;
                rbp_offset = util_align_up(rbp_offset, 8);
                log_pure("=== aligned rbp: %zu -> %zu\n", old_rbp_offset,
                         rbp_offset);
                old_rbp_offset = rbp_offset;
                rbp_offset += aligned_size;
                log_pure("=== item location: rbp + %zu\n", old_rbp_offset);
                log_pure("=== rbp changes from %zu to %zu\n", old_rbp_offset,
                         rbp_offset);
                struct location_t loc = {
                    .type = LOC_PTR_ON_STACK,
                    .true_len = mem_len,
                    .alignment = align,
                    .stack_offset = old_rbp_offset,
                };
                answer.locs[i] = loc;
                log_pure("\n");
            }
            continue;
        }

        int    uses_two_chunks = mem_len > 8;
        size_t how_many_int =
            (chunk1 == VMAP_CHUNK_INT) + (chunk2 == VMAP_CHUNK_INT);
        size_t how_many_sse =
            (chunk1 == VMAP_CHUNK_SSE) + (chunk2 == VMAP_CHUNK_SSE);

        if (uses_two_chunks == 1 && (usable_gpr_ptr + how_many_int > TOTAL_GPR ||
                                     usable_sse_ptr + how_many_sse > TOTAL_SSE)) {
            log_pure(
                "=== not enough int/sse regs for 2 chunks, goes on the stack\n");
            goto goes_on_the_stack;
        } else if (uses_two_chunks == 0) {
            how_many_int -= chunk2 == VMAP_CHUNK_INT;
            how_many_sse -= chunk2 == VMAP_CHUNK_SSE;
            if (usable_gpr_ptr + how_many_int > TOTAL_GPR ||
                usable_sse_ptr + how_many_sse > TOTAL_SSE) {
                log_pure(
                    "=== not enough int/sse regs for 1 chunk, goes on the stack\n");
                goto goes_on_the_stack;
            }
        }

        // goes into registers, finally
        if (mem_len <= 8) {
            if (chunk1 == VMAP_CHUNK_INT) {
                struct location_t loc = {
                    .type = LOC_GPR,
                    .true_len = mem_len,
                    .alignment = align,
                    .gpr_reg1 = usable_gpr[usable_gpr_ptr++],
                };
                log_pure("=== chunk1 goes into %s\n", loc.gpr_reg1->qname);
                answer.locs[i] = loc;
            } else {
                struct location_t loc = {
                    .type = LOC_SSE,
                    .true_len = mem_len,
                    .alignment = align,
                    .sse_reg1 = usable_sse[usable_sse_ptr++],
                };
                log_pure("=== chunk1 goes into %s\n", loc.sse_reg1->name);
                answer.locs[i] = loc;
            }
        } else {
            if (chunk1 == VMAP_CHUNK_INT && chunk2 == VMAP_CHUNK_INT) {
                struct location_t loc = {
                    .type = LOC_GPR_GPR,
                    .true_len = mem_len,
                    .alignment = align,
                    .gpr_reg1 = usable_gpr[usable_gpr_ptr++],
                    .gpr_reg2 = usable_gpr[usable_gpr_ptr++],
                };
                log_pure("=== chunk1 goes into %s\n", loc.gpr_reg1->qname);
                log_pure("=== chunk2 goes into %s\n", loc.gpr_reg2->qname);
                answer.locs[i] = loc;
            } else if (chunk1 == VMAP_CHUNK_INT && chunk2 == VMAP_CHUNK_SSE) {
                struct location_t loc = {
                    .type = LOC_GPR_SSE,
                    .true_len = mem_len,
                    .alignment = align,
                    .gpr_reg1 = usable_gpr[usable_gpr_ptr++],
                    .sse_reg2 = usable_sse[usable_sse_ptr++],
                };
                log_pure("=== chunk1 goes into %s\n", loc.gpr_reg1->qname);
                log_pure("=== chunk2 goes into %s\n", loc.sse_reg2->name);
                answer.locs[i] = loc;
            } else if (chunk1 == VMAP_CHUNK_SSE && chunk2 == VMAP_CHUNK_INT) {
                struct location_t loc = {
                    .type = LOC_SSE_GPR,
                    .true_len = mem_len,
                    .alignment = align,
                    .sse_reg1 = usable_sse[usable_sse_ptr++],
                    .gpr_reg2 = usable_gpr[usable_gpr_ptr++],
                };
                log_pure("=== chunk1 goes into %s\n", loc.sse_reg1->name);
                log_pure("=== chunk2 goes into %s\n", loc.gpr_reg2->qname);
                answer.locs[i] = loc;
            } else {
                struct location_t loc = {
                    .type = LOC_SSE_SSE,
                    .true_len = mem_len,
                    .alignment = align,
                    .sse_reg1 = usable_sse[usable_sse_ptr++],
                    .sse_reg2 = usable_sse[usable_sse_ptr++],
                };
                log_pure("=== chunk1 goes into %s\n", loc.sse_reg1->name);
                log_pure("=== chunk2 goes into %s\n", loc.sse_reg2->name);
                answer.locs[i] = loc;
            }
        }

        log_pure("\n");
        continue;

    goes_on_the_stack:
        size_t aligned_size = util_align_up(mem_len, 8);
        log_pure("=== decided: goes on the stack: aligned_to8_size=%zu\n",
                 aligned_size);
        size_t old_rbp_offset = rbp_offset;
        rbp_offset = util_align_up(rbp_offset, align);
        log_pure("=== aligned rbp: %zu -> %zu\n", old_rbp_offset, rbp_offset);
        old_rbp_offset = rbp_offset;
        rbp_offset += aligned_size;
        log_pure("=== item location: rbp + %zu\n", old_rbp_offset);
        log_pure("=== rbp changes from %zu to %zu\n", old_rbp_offset, rbp_offset);
        struct location_t loc = {
            .type = LOC_STACK,
            .true_len = mem_len,
            .alignment = align,
            .stack_offset = old_rbp_offset,
        };
        answer.locs[i] = loc;
        log_pure("\n");
        continue;
    }

    log_pure("=== VMAP_ARGS REQUEST END ===\n");
    return answer;

#undef TOTAL_GPR
#undef TOTAL_SSE
}

struct vmap_t vmap_args_copy(const struct vmap_args_request_t *req) {
    log_debug("=== ABI VMAP_ARGS_COPY REQUEST n=%zu ===\n", req->n);

    struct vmap_t answer = {0};

    answer.n = req->n;
    if (req->names != NULL) {
        answer.names = (const char **)malloc(sizeof(const char *) * answer.n);
        log_assert(answer.names != NULL);
        memcpy(answer.names, req->names, answer.n * sizeof(const char *));
    }
    answer.locs = (struct location_t *)malloc(sizeof(struct location_t) * answer.n);
    log_assert(answer.locs != NULL);

    // stack:
    // [rbp+16]: old rps pointed here, and it was aligned to 16
    // [rbp+8]:  ret
    // [rbp]:    rbp
    //
    // so we know that [rbp] is aligned by 16.
    size_t offset = 0;  // and this is also aligned

    for (size_t i = 0; i < answer.n; i++) {
        log_debug(" - %d (%s):\n", i,
                  answer.names == NULL ? "NONAME" : answer.names[i]);
        size_t             mem_len = req->mem_len[i];
        size_t             align = req->align[i];
        size_t             true_len = mem_len;
        size_t             true_align = true_align;
        enum location_type type = LOC_STACK;

        log_debug("   - mem_len=%zu\n", mem_len);
        log_debug("   - align=%zu\n", align);

        if (mem_len > 16) {
            log_debug("   - will be a pointer, so mem_len=align=8\n");
            type = LOC_PTR_ON_STACK;
            mem_len = 8;
            align = 8;
        }

        log_debug("   - offset %zu -> %zu\n", offset, offset + mem_len);
        offset += mem_len;
        offset = util_align_up(offset, align);
        log_debug("   - aligned to %zu\n", offset);

        struct location_t loc = {
            .type = type,
            .true_len = true_len,
            .alignment = true_align,
            .stack_offset = -(int64_t)offset,
        };
        answer.locs[i] = loc;
        log_pure("\n");
    }

    return answer;
}
