#include "abi_vmap_helper.h"
#include "../tests/tests.h"

DEFINE_TEST(single_int_reg) {
    struct vmap_args_request_t req = {0};
    PREPARE_VMAP_REQUEST(req, 1);

    REQ_ITEM(req, 0, 8, 8, INT, INT);

    struct vmap_t answer = vmap_args(&req);
    DESTROY_VMAP_REQUEST(req);

    TASSERT(answer.n == 1);
    ASSERT_GPR(answer.locs[0], r_rdi);

    vmap_destroy(&answer);
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
    ASSERT_GPR(answer.locs[0], r_rdi);
    ASSERT_GPR(answer.locs[1], r_rsi);
    ASSERT_GPR(answer.locs[2], r_rdx);
    ASSERT_GPR(answer.locs[3], r_rcx);
    ASSERT_SSE(answer.locs[4], r_xmm0);
    ASSERT_SSE(answer.locs[5], r_xmm1);
    ASSERT_SSE(answer.locs[6], r_xmm2);
    ASSERT_SSE(answer.locs[7], r_xmm3);

    vmap_destroy(&answer);
    TEST_OK
    TEST_FAIL
}

DEFINE_TEST(too_many_regs) {
    struct vmap_args_request_t req = {0};
    PREPARE_VMAP_REQUEST(req, 15);

    for (int i = 0; i < 15; i++) {
        REQ_ITEM(req, i, 8, 8, INT, INT);
    }

    struct vmap_t answer = vmap_args(&req);
    DESTROY_VMAP_REQUEST(req);

    TASSERT(answer.n == 15);
    ASSERT_GPR(answer.locs[0], r_rdi);
    ASSERT_GPR(answer.locs[1], r_rsi);
    ASSERT_GPR(answer.locs[2], r_rdx);
    ASSERT_GPR(answer.locs[3], r_rcx);
    ASSERT_GPR(answer.locs[4], r_r8);
    ASSERT_GPR(answer.locs[5], r_r9);
    for (int i = 6; i < 15; i++) {
        ASSERT_STACK(answer.locs[i], 16 + 8 * (i - 6));
    }

    vmap_destroy(&answer);
    TEST_OK
    TEST_FAIL
}

DEFINE_TEST(single_big_as_ptr) {
    struct vmap_args_request_t req = {0};
    PREPARE_VMAP_REQUEST(req, 1);

    REQ_ITEM(req, 0, 1024, 8, INT, INT);

    struct vmap_t answer = vmap_args(&req);
    DESTROY_VMAP_REQUEST(req);

    TASSERT(answer.n == 1);
    ASSERT_PTR_IN_GPR(answer.locs[0], r_rdi, 1024);

    vmap_destroy(&answer);
    TEST_OK
    TEST_FAIL
}

DEFINE_TEST(split_struct_int_sse) {
    struct vmap_args_request_t req = {0};
    PREPARE_VMAP_REQUEST(req, 1);

    REQ_ITEM(req, 0, 16, 8, INT, SSE);

    struct vmap_t answer = vmap_args(&req);
    DESTROY_VMAP_REQUEST(req);

    TASSERT(answer.n == 1);
    ASSERT_GPR_SSE(answer.locs[0], r_rdi, r_xmm0);

    vmap_destroy(&answer);
    TEST_OK
    TEST_FAIL
}

DEFINE_TEST(exhaustion_spills_entire_struct) {
    struct vmap_args_request_t req = {0};
    PREPARE_VMAP_REQUEST(req, 6);

    for (int i = 0; i < 5; i++) {
        REQ_ITEM(req, i, 8, 8, INT, INT);
    }
    REQ_ITEM(req, 5, 16, 8, INT, INT);

    struct vmap_t answer = vmap_args(&req);
    DESTROY_VMAP_REQUEST(req);

    TASSERT(answer.n == 6);
    ASSERT_GPR(answer.locs[0], r_rdi);
    ASSERT_GPR(answer.locs[1], r_rsi);
    ASSERT_GPR(answer.locs[2], r_rdx);
    ASSERT_GPR(answer.locs[3], r_rcx);
    ASSERT_GPR(answer.locs[4], r_r8);
    ASSERT_STACK(answer.locs[5], 16);

    vmap_destroy(&answer);
    TEST_OK
    TEST_FAIL
}

DEFINE_TEST(stack_alignment_16) {
    struct vmap_args_request_t req = {0};
    PREPARE_VMAP_REQUEST(req, 8);

    for (int i = 0; i < 6; i++) {
        REQ_ITEM(req, i, 8, 8, INT, INT);
    }
    REQ_ITEM(req, 6, 8, 8, INT, INT);
    REQ_ITEM(req, 7, 8, 16, INT, INT);

    struct vmap_t answer = vmap_args(&req);
    DESTROY_VMAP_REQUEST(req);

    TASSERT(answer.n == 8);
    ASSERT_STACK(answer.locs[6], 16);
    ASSERT_STACK(answer.locs[7], 32);

    vmap_destroy(&answer);
    TEST_OK
    TEST_FAIL
}

DEFINE_TEST(explicit_mem_bypass) {
    struct vmap_args_request_t req = {0};
    PREPARE_VMAP_REQUEST(req, 1);

    REQ_ITEM(req, 0, 8, 8, MEM, MEM);

    struct vmap_t answer = vmap_args(&req);
    DESTROY_VMAP_REQUEST(req);

    TASSERT(answer.n == 1);
    ASSERT_STACK(answer.locs[0], 16);

    vmap_destroy(&answer);
    TEST_OK
    TEST_FAIL
}

DEFINE_TEST(total_exhaustion) {
    struct vmap_args_request_t req = {0};
    PREPARE_VMAP_REQUEST(req, 6 + 8 + 2);

    for (int i = 0; i < 6; i++) {
        REQ_ITEM(req, i, 8, 8, INT, INT);
    }
    for (int i = 6; i < 6 + 8; i++) {
        REQ_ITEM(req, i, 8, 8, SSE, SSE);
    }
    REQ_ITEM(req, 6 + 8, 8, 8, INT, INT);
    REQ_ITEM(req, 6 + 8 + 1, 8, 8, INT, INT);

    struct vmap_t answer = vmap_args(&req);
    DESTROY_VMAP_REQUEST(req);

    TASSERT(answer.n == 6 + 8 + 2);
    ASSERT_GPR(answer.locs[0], r_rdi);
    ASSERT_GPR(answer.locs[1], r_rsi);
    ASSERT_GPR(answer.locs[2], r_rdx);
    ASSERT_GPR(answer.locs[3], r_rcx);
    ASSERT_GPR(answer.locs[4], r_r8);
    ASSERT_GPR(answer.locs[5], r_r9);
    ASSERT_SSE(answer.locs[6], r_xmm0);
    ASSERT_SSE(answer.locs[7], r_xmm1);
    ASSERT_SSE(answer.locs[8], r_xmm2);
    ASSERT_SSE(answer.locs[9], r_xmm3);
    ASSERT_SSE(answer.locs[10], r_xmm4);
    ASSERT_SSE(answer.locs[11], r_xmm5);
    ASSERT_SSE(answer.locs[12], r_xmm6);
    ASSERT_SSE(answer.locs[13], r_xmm7);
    ASSERT_STACK(answer.locs[14], 16);
    ASSERT_STACK(answer.locs[15], 24);

    vmap_destroy(&answer);
    TEST_OK
    TEST_FAIL
}

DEFINE_TEST(pointer_spills_to_stack) {
    struct vmap_args_request_t req = {0};
    PREPARE_VMAP_REQUEST(req, 7);

    for (int i = 0; i < 6; i++) {
        REQ_ITEM(req, i, 8, 8, INT, INT);
    }
    REQ_ITEM(req, 6, 1024, 8, INT, INT);

    struct vmap_t answer = vmap_args(&req);
    DESTROY_VMAP_REQUEST(req);

    ASSERT_PTR_ON_STACK(answer.locs[6], 16, 1024);

    vmap_destroy(&answer);
    TEST_OK
    TEST_FAIL
}

DEFINE_TEST(half_is_mem) {
    struct vmap_args_request_t req = {0};
    PREPARE_VMAP_REQUEST(req, 1);

    REQ_ITEM(req, 0, 16, 8, INT, MEM);

    struct vmap_t answer = vmap_args(&req);
    DESTROY_VMAP_REQUEST(req);

    ASSERT_STACK(answer.locs[0], 16);

    vmap_destroy(&answer);
    TEST_OK
    TEST_FAIL
}

RUN_TESTS;
