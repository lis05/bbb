#include <stdlib.h>
#include <string.h>

#include "symtab.h"
#include "../common/error.h"

char **symtab;
int symtab_len;
int symtab_cap;

void symbol_init() {
	if (symtab != NULL) {
		for (int i = 0; i < symtab_len; i++) {
			if (symtab[i] != NULL) {
				free(symtab[i]);
			}
		}

		free(symtab);
	}

	symtab_len = 0;
	symtab_cap = 200;
	symtab = calloc(symtab_cap, sizeof(char*));
	if (symtab == NULL) {
		quit("Failed to init the symbol table.\n");
	}
}

const char *symbol(char *string) {
	for (int i = 0; i < symtab_len; i++) {
		if (strcmp(string, symtab[i]) == 0) {
			return symtab[i];
		}
	}

	if (symtab_len == symtab_cap) {
		symtab_cap *= 2;
		symtab = realloc(symtab, symtab_cap * sizeof(char*));
		if (symtab == NULL) {
			quit("Failed to resize the symbol table.\n");
		}
	}

	if ((symtab[symtab_len++] = strdup(string)) == NULL) {
		quit("Failed to add a new symbol.\n");
	}

	return symtab[symtab_len - 1];
}

int symbol_exists(char *string) {
	for (int i = 0; i < symtab_len; i++) {
		if (strcmp(string, symtab[i]) == 0) {
			return 1;
		}
	}

	return 0;
}
