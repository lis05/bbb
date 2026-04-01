#pragma once

/*
 * These tags are intended to be a hint for ME. They will not make the compiler
 * magically check the code, but will let me remember what can be NULL, what can
 * change, etc.
 *
 * These tags should be read in the same way pointers are read, i.e.:
 *   type_t *value FINAL -> pointer value will not point to a different object
 *   type_t FINAL *value -> value pointer by the pointer will not change
 *
 * Most tags can be applied both to return values, function parameters, and
 * variables. Some tags should only be applied to functions (placed before the ')'
 * bracket);
 */

/* Suggests that the item will never be NULL. */
#define NONULL

/* The pointer may be null, and it is an intended behaviour to suggest an
 * unsuccessful operation, an empty result, or something else. */
#define YESNULL

/* Suggests that the item will never change it's value after it is assigned. */
#define FINAL

/* Suggests that the string originates from a static buffer and should be used
 * immediatelly.*/
#define ONETIME

/* Suggests that the ownership of this pointer gets transfered to the callee. */
#define SINK

/* The pointer must not be freed by you! */
#define NOFREE

/* The pointer must be freed by you! */
#define MUSTFREE

/* Will either succeed or cause the program to crash with a message. */
#define SAFE

/* If memory allocations fail, the program will crash with a message. */
#define MEMSAFE

/* Integer is a status code (0 is success, everything else is failure). */
#define STATUSCODE
