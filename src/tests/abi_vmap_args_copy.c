#include "abi_vmap_helper.h"
#include "tests.h"

DEFINE_TEST(single_simple) {
    struct vmap_args_request_t req = {0};
    PREPARE_VMAP_REQUEST(req, 1);

    REQ_ITEM(req, 0, 8, 8, INT, INT);

    struct vmap_t answer = vmap_args_copy(&req);
    DESTROY_VMAP_REQUEST(req);

    TASSERT(answer.n == 1);
    ASSERT_STACK(answer.locs[0], -8);

    vmap_destroy(&answer);
    TEST_OK
    TEST_FAIL
}

DEFINE_TEST(small_but_diff_align) {
    struct vmap_args_request_t req = {0};
    PREPARE_VMAP_REQUEST(req, 3);

    REQ_ITEM(req, 0, 8, 8, INT, INT);
    REQ_ITEM(req, 1, 10, 16, INT, INT);
    REQ_ITEM(req, 2, 4, 4, INT, INT);

    struct vmap_t answer = vmap_args_copy(&req);
    DESTROY_VMAP_REQUEST(req);

    TASSERT(answer.n == 3);
    ASSERT_STACK(answer.locs[0], -8);
    ASSERT_STACK(answer.locs[1], -32);
    ASSERT_STACK(answer.locs[2], -36);

    vmap_destroy(&answer);
    TEST_OK
    TEST_FAIL
}

DEFINE_TEST(mixed_diff_align) {
    struct vmap_args_request_t req = {0};
    PREPARE_VMAP_REQUEST(req, 4);

    REQ_ITEM(req, 0, 1, 2, INT, INT);
    REQ_ITEM(req, 1, 1024, 16, INT, INT);
    REQ_ITEM(req, 2, 10, 16, INT, INT);
    REQ_ITEM(req, 3, 4, 4, INT, INT);

    struct vmap_t answer = vmap_args_copy(&req);
    DESTROY_VMAP_REQUEST(req);

    TASSERT(answer.n == 4);
    ASSERT_STACK(answer.locs[0], -2);
    ASSERT_PTR_ON_STACK(answer.locs[1], -16, 1024);
    ASSERT_STACK(answer.locs[2], -32);
    ASSERT_STACK(answer.locs[3], -36);

    vmap_destroy(&answer);
    TEST_OK
    TEST_FAIL
}

RUN_TESTS
