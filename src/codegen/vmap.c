#include "vmap.h"

#include "regs.h"

static const char *chunk_to_name[] = {"INT", "SSE", "MEM"};

void vmap_destroy(struct vmap_t *vmap) {
    free(vmap->names);
    free(vmap->locs_chunk1);
    free(vmap->locs_chunk2);
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
    answer.locs_chunk1 =
        (struct location_t *)malloc(req->n * sizeof(struct location_t));
    log_assert(answer.locs_chunk1 != NULL);
    answer.locs_chunk2 =
        (struct location_t *)malloc(req->n * sizeof(struct location_t));
    log_assert(answer.locs_chunk2 != NULL);

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

        // TODO FIX THIS IS STUPID AND INCORRECT, >=3 GOES AS A POINTER U DUMP FUCK
        if (how_many_chunks >= 3) {
            goto goes_on_the_stack;
            log_pure("=== 3 or more chunks, goes on the stack\n");
        }

        if (chunk1 == VMAP_CHUNK_MEM || chunk2 == VMAP_CHUNK_MEM) {
            log_pure("=== at least one chuck iS MEM, goes on the stack\n");
            goto goes_on_the_stack;
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

        if (chunk1 == VMAP_CHUNK_INT) {
            struct location_t loc;
            loc_init_gpr(&loc, usable_gpr[usable_gpr_ptr++]);
            log_pure("=== chunk1 goes into %s\n", loc.gpr_reg->qname);
            answer.locs_chunk1[i] = loc;
        } else if (chunk2 == VMAP_CHUNK_SSE) {
            struct location_t loc;
            loc_init_sse(&loc, usable_sse[usable_sse_ptr++]);
            log_pure("=== chunk1 goes into %s\n", loc.sse_reg->name);
            answer.locs_chunk1[i] = loc;
        }

        if (mem_len <= 8) {
            log_pure("\n");
            continue;
        }

        if (chunk2 == VMAP_CHUNK_INT) {
            struct location_t loc;
            loc_init_gpr(&loc, usable_gpr[usable_gpr_ptr++]);
            log_pure("=== chunk2 goes into %s\n", loc.gpr_reg->qname);
            answer.locs_chunk2[i] = loc;
        } else if (chunk2 == VMAP_CHUNK_SSE) {
            struct location_t loc;
            loc_init_sse(&loc, usable_sse[usable_sse_ptr++]);
            log_pure("=== chunk2 goes into %s\n", loc.sse_reg->name);
            answer.locs_chunk2[i] = loc;
        }

        continue;

    goes_on_the_stack:
        size_t aligned_size = req->mem_len[i] + req->mem_len[i] % req->align[i];
        log_pure("=== decided: goes on the stack: aligned_size=%zu\n", aligned_size);
        rbp_offset += rbp_offset % req->align[i];
        log_pure("=== aligned rbp: %zu\n", rbp_offset);
        rbp_offset += aligned_size;
        log_pure("=== item location: rbp + %zu\n", rbp_offset);
        struct location_t loc;
        loc_init_stack(&loc, rbp_offset);
        answer.locs_chunk1[i] = loc;
        log_pure("\n");
        continue;
    }

    log_pure("=== VMAP_ARGS REQUEST END ===\n");
    return answer;

#undef TOTAL_GPR
#undef TOTAL_SSE
}
