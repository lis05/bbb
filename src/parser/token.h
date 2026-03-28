#pragma once

void tokens_init();
const char *token_get(const char *string); // will strdup
const char *token_move(const char *string); // will not strdup
int token_exists(const char *string);
