#include "../codegen/vmap.h"
#include "../tests/tests.h"

#define PREPARE_VMAP_REQUEST(req, num)                         \
    do {                                                       \
        req.n = num;                                           \
        req.names = NULL;                                      \
        req.mem_len = (size_t *)malloc(sizeof(size_t) * num);  \
        req.align = (uint8_t *)malloc(sizeof(uint8_t) * num);  \
        req.chunk1 = (uint8_t *)malloc(sizeof(uint8_t) * num); \
        req.chunk2 = (uint8_t *)malloc(sizeof(uint8_t) * num); \
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
    TASSERT((loc).type == LOC_GPR_REGISTER && (loc).gpr_reg == reg)

DEFINE_TEST(single_int_reg) {
    struct vmap_args_request_t req = {0};
    PREPARE_VMAP_REQUEST(req, 1);

    REQ_ITEM(req, 0, 8, 8, INT, INT);

    struct vmap_t answer = vmap_args(&req);
    DESTROY_VMAP_REQUEST(req);

    TASSERT(answer.n == 1);
    ASSERT_GPR(answer.locs_chunk1[0], r_rdi);

    TEST_OK
    TEST_FAIL
}

DEFINE_TEST(multiple_mixed_regs) {
    struct vmap_args_request_t req = {0};
    PREPARE_VMAP_REQUEST(req, 8);

    REQ_ITEM(req, 0, 8, 8, INT, INT);
    REQ_ITEM(req, 1, 8, 8, INT, INT);
    REQ_ITEM(req, 2, 8, 8, INT, INT);
    REQ_ITEM(req, 3, 8, 8, INT, INT);
    REQ_ITEM(req, 4, 8, 8, SSE, SSE);
    REQ_ITEM(req, 5, 8, 8, SSE, SSE);
    REQ_ITEM(req, 6, 8, 8, SSE, SSE);
    REQ_ITEM(req, 7, 8, 8, SSE, SSE);

    struct vmap_t answer = vmap_args(&req);
    DESTROY_VMAP_REQUEST(req);

    TASSERT(answer.n == 8);
    ASSERT_GPR(answer.locs_chunk1[0], r_rdi);
    ASSERT_GPR(answer.locs_chunk1[1], r_rsi);
    ASSERT_GPR(answer.locs_chunk1[2], r_rdx);
    ASSERT_GPR(answer.locs_chunk1[3], r_rcx);
    ASSERT_GPR(answer.locs_chunk1[4], r_xmm0);
    ASSERT_GPR(answer.locs_chunk1[5], r_xmm1);
    ASSERT_GPR(answer.locs_chunk1[6], r_xmm2);
    ASSERT_GPR(answer.locs_chunk1[7], r_xmm3);
    TEST_OK
    TEST_FAIL
}

RUN_TESTS;
