#pragma once
#include <stdlib.h>
#include <stdio.h>

#define __ERROR(quit, ...) do {\
		printf("ERROR: %s:%d (%s): ", __FILE__, __LINE__, __FUNCTION__); \
		printf(__VA_ARGS__); \
		if ((quit)) exit(-1); \
	} while (0)

#define error(...) __ERROR(0, __VA_ARGS__)
#define quit(...) __ERROR(1, __VA_ARGS__)
