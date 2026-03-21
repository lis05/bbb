#pragma once

#include "../common/common.h"

// small testing framework
// intended to be used in a single .c file

#define TERROR(...)             \
    {                           \
        log_error(__VA_ARGS__); \
    }

#define TEST_FAIL    \
    __bbb_test_fail: \
    __attribute__((unused)) return -1;

#define TEST_OK    \
    __bbb_test_ok: \
    __attribute__((unused)) return 0;

#define TASSERT(what)                                  \
    do {                                               \
        if ((what) != 1) {                             \
            TERROR("Assertion '" #what "' failed.\n"); \
            goto __bbb_test_fail;                      \
        }                                              \
    } while (0)

typedef int (*__bbb_test_case_t)();
#define MAX_TESTS 2048  // if you have more meaningful tests, i will kill myself
static size_t            __bbb_total_tests;
static __bbb_test_case_t __bbb_registered_tests[MAX_TESTS];
static const char       *__bbb_registered_tests_names[MAX_TESTS];

static void __bbb_register_test(__bbb_test_case_t test, const char *name) {
    __bbb_registered_tests[__bbb_total_tests] = test;
    __bbb_registered_tests_names[__bbb_total_tests++] = name;
}

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

#define DEFINE_TEST(name)                                                       \
    static int                               test_##name(void);                 \
    static void __attribute__((constructor)) __bbb_register_test_##name(void) { \
        const char *file_path = __FILE__;                                       \
        const char *last_slash = strrchr(file_path, '/');                       \
        const char *base = last_slash ? last_slash + 1 : file_path;             \
        char       *file_name = strndup(base, strcspn(base, "."));              \
                                                                                \
        char *full_test_name;                                                   \
        int   _ __attribute__((unused)) =                                       \
            asprintf(&full_test_name, "test_%s_%s", file_name, #name);          \
                                                                                \
        __bbb_register_test(test_##name, full_test_name);                       \
        free(file_name);                                                        \
    }                                                                           \
    static int test_##name(void)

#define RUN_TESTS                                                           \
    int main() {                                                            \
        set_log_level(100);                                                 \
        int res = 0;                                                        \
        for (size_t i = 0; i < __bbb_total_tests; i++) {                    \
            int ret = __bbb_registered_tests[i]();                          \
            fflush(stdout);                                                 \
            fflush(stderr);                                                 \
            if (ret == 0) {                                                 \
                printf(ANSI_COLOR_GREEN);                                   \
            } else {                                                        \
                printf(ANSI_COLOR_RED);                                     \
            }                                                               \
            printf("   %zu. %s: ", i + 1, __bbb_registered_tests_names[i]); \
            if (ret == 0) {                                                 \
                printf("PASSED\n");                                         \
            } else {                                                        \
                printf("FAILED\n");                                         \
                res = -1;                                                   \
            }                                                               \
            printf("%s", ANSI_COLOR_RESET);                                 \
            fflush(stdout);                                                 \
            fflush(stderr);                                                 \
        }                                                                   \
        return res;                                                         \
    }

