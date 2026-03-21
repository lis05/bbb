#pragma once

#include "../common/common.h"
#include "loc.h"

#define VMAP_CHUNK_INT 0
#define VMAP_CHUNK_SSE 1
#define VMAP_CHUNK_MEM 2

struct vmap_t {
    size_t             n;
    const char       **names;  // may be null
    struct location_t *locs_chunk1;
    struct location_t *locs_chunk2;  // not applicable if not applicable lol
};

void vmap_destroy(struct vmap_t *vmap);

// ===============================
// mapping of function arguments
// ===============================

struct vmap_args_request_t {
    size_t       n;
    const char **names;
    size_t      *mem_len;
    uint8_t     *align;  // alignment bigger than 16 is not possible. also must be
                         // a power of two.
    uint8_t *chunk1;
    uint8_t *chunk2;  // only 2 chunks can be specified.
};

// maps arguments passed to function to their locations when being passed
struct vmap_t vmap_args(const struct vmap_args_request_t *req);

// maps arguments passed to function to their locations after they are copied by bbb
// on the stack. these locations MUST be on the stack.
struct vmap_t vmap_args_copy(const struct vmap_args_request_t *req);

// ===============================
// mapping of function return value
// ===============================

struct vmap_ret_request_t {
    size_t  len;
    uint8_t align;
    uint8_t chunk1;
    uint8_t chunk2;
};

// maps return value of a function to its location.
// if a returned value is >16 bytes, this should be RAX (pointer passed in RDI)
struct vmap_t vmap_ret(const struct vmap_args_request_t *req);

// ===============================
// mapping of local variables
// ===============================

// note: only maps to stack, register aliases have to be handled
// separatelly
struct vmap_vars_request_t {
    size_t        n;
    const char   *names;
    const size_t *mem_len;  // null if alias
    // only up to 16 is supported for now;
    // in theory, adding aligning of more than 16
    // should be easy, but i do not want to implement it
    // right now. it would require more complicated locations
    // for the vars, some memory gaps, and more computing.
    const size_t *align;         // null if alias
    size_t        stack_offset;  // kinda like rsp -> rsp + offset
};

// maps local variables to stack locations
struct vmap_t vmap_vars(const struct vmap_vars_request_t *req);

