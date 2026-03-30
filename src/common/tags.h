#pragma once

/*
 * These tags are intended to be a hint for ME. They will not make the compiler
 * magically check the code, but will let me remember what can be NULL, what can
 * change, etc.
 */

/* Suggests that the item will never be NULL. */
#define NONULL

/* Suggests that the item will never change it's value after it is assigned. */
#define FINAL


