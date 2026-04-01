#pragma once

/* Permanents STRings - ones that get allocated once, can be compared for equality
 * by simply comparing the pointers, and are freed at the end of the program. */

typedef NOFREE const char *pstr_t;

void pstr_init() MEMSAFE;
void pstr_destroy() MEMSAFE;

/* Returns a pstr_t for the provided string. */
pstr_t NONULL pstr_take(char *str NONULL SINK) MEMSAFE;

/* Returns a pstr_t for the provided string. */
pstr_t NONULL pstr_copy(const char *str NONULL) MEMSAFE;



