#include "../codegen/vmap.h"
#include "../tests/tests.h"

#define PREPARE_VMAP_REQUEST(req, num)                             \
    do {                                                           \
        (req).n = (num);                                           \
        (req).names = NULL;                                        \
        (req).mem_len = (size_t *)malloc(sizeof(size_t) * (num));  \
        log_assert((req).mem_len != NULL);                          \
        (req).align = (size_t *)malloc(sizeof(size_t) * (num));    \
        log_assert((req).align != NULL);                            \
        (req).chunk1 = (uint8_t *)malloc(sizeof(uint8_t) * (num)); \
        log_assert((req).chunk1 != NULL);                           \
        (req).chunk2 = (uint8_t *)malloc(sizeof(uint8_t) * (num)); \
        log_assert((req).chunk2 != NULL);                           \
    } while (0)

#define DESTROY_VMAP_REQUEST(req) \
    do {                          \
        free(req.names);          \
        free(req.mem_len);        \
        free(req.align);          \
        free(req.chunk1);         \
        free(req.chunk2);         \
    } while (0)

#define REQ_ITEM(req, i, _mem_len, _align, _chunk1, _chunk2) \
    do {                                                     \
        req.mem_len[i] = (_mem_len);                         \
        req.align[i] = (_align);                             \
        req.chunk1[i] = (VMAP_CHUNK_##_chunk1);              \
        req.chunk2[i] = (VMAP_CHUNK_##_chunk2);              \
    } while (0)

#define ASSERT_GPR(loc, reg) \
    TASSERT((loc).type == LOC_GPR && (loc).gpr_reg1 == (reg))

#define ASSERT_SSE(loc, reg) \
    TASSERT((loc).type == LOC_SSE && (loc).sse_reg1 == (reg))

#define ASSERT_GPR_GPR(loc, reg1, reg2)                              \
    TASSERT((loc).type == LOC_GPR_GPR && (loc).gpr_reg1 == (reg1) && \
            (loc).gpr_reg2 == (reg2))

#define ASSERT_GPR_SSE(loc, reg1, reg2)                              \
    TASSERT((loc).type == LOC_GPR_SSE && (loc).gpr_reg1 == (reg1) && \
            (loc).sse_reg2 == (reg2))

#define ASSERT_SSE_GPR(loc, reg1, reg2)                              \
    TASSERT((loc).type == LOC_SSE_GPR && (loc).sse_reg1 == (reg1) && \
            (loc).gpr_reg2 == (reg2))

#define ASSERT_SSE_SSE(loc, reg1, reg2)                              \
    TASSERT((loc).type == LOC_SSE_SSE && (loc).sse_reg1 == (reg1) && \
            (loc).sse_reg2 == (reg2))

#define ASSERT_PTR_IN_GPR(loc, reg, t_len)                             \
    TASSERT((loc).type == LOC_PTR_IN_GPR && (loc).gpr_reg1 == (reg) && \
            (loc).true_len == t_len);

#define ASSERT_PTR_ON_STACK(loc, offset, t_len)                                 \
    TASSERT((loc).type == LOC_PTR_ON_STACK && (loc).stack_offset == (offset) && \
            (loc).true_len == (t_len))

#define ASSERT_STACK(loc, offset) \
    TASSERT((loc).type == LOC_STACK && (loc).stack_offset == (offset))
