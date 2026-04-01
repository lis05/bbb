#pragma once

#include <stddef.h>

#include "tags.h"

void *NONULL MUSTFREE calloc_safe(size_t how_many, size_t size_of_one) MEMSAFE;
void *NONULL MUSTFREE memdup_safe(const void *ptr NONULL, size_t size) MEMSAFE;
char *NONULL MUSTFREE strdup_safe(const char *str NONULL) MEMSAFE;
void *NONULL MUSTFREE realloc_safe(void *ptr NONULL SINK, size_t size) MEMSAFE;
