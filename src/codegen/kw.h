#pragma once
#include "../parser/token.h"

#define KW_CHUNK_INT token_get("#int")
#define KW_CHUNK_SSE token_get("#sse")
#define KW_CHUNK_MEM token_get("#mem")

#define KW_NASM_START token_get("%nasm")
#define KW_NASM_END token_get("%endnasm")

#define KW_ALIAS_REG token_get("reg")
