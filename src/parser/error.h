#pragma once

#include "../common/common.h"
#include "tfrag.h"

extern int messages_print_location;

#define context_msg(...)                                                      \
    do {                                                                      \
        if (messages_print_location == 1) {                                   \
            printf("The following message originates from %s:%d\n", __FILE__, \
                   __LINE__);                                                 \
        }                                                                     \
        __bbb_context_msg(__VA_ARGS__);                                       \
    } while (0)

void __bbb_context_msg(const tfrag_t *frag, const char *format, ...);
