#include "token.h"
#include "../common/common.h"

char **tokens;
int tokens_len;
int tokens_cap;

void tokens_init() {
	if (tokens != NULL) {
		for (int i = 0; i < tokens_len; i++) {
			if (tokens[i] != NULL) {
				free(tokens[i]);
			}
		}

		free(tokens);
	}

	tokens_len = 0;
	tokens_cap = 200;
	tokens = calloc(tokens_cap, sizeof(char*));
	if (tokens == NULL) {
		log_crit("Failed to init the tokens table.\n");
	}
}

const char *token_get(char *string) {
	for (int i = 0; i < tokens_len; i++) {
		if (strcmp(string, tokens[i]) == 0) {
			return tokens[i];
		}
	}

	if (tokens_len == tokens_cap) {
		tokens_cap *= 2;
		tokens = realloc(tokens, tokens_cap * sizeof(char*));
		if (tokens == NULL) {
			log_crit("Failed to resize the tokens table.\n");
		}
	}

	if ((tokens[tokens_len++] = strdup(string)) == NULL) {
		log_crit("Failed to add a new tokens.\n");
	}

	return tokens[tokens_len - 1];
}

int token_exists(char *string) {
	for (int i = 0; i < tokens_len; i++) {
		if (strcmp(string, tokens[i]) == 0) {
			return 1;
		}
	}

	return 0;
}
