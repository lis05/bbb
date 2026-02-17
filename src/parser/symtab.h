#pragma once

// inits the symbol table.
void symbol_init();

// returns a symbol string for the non-const input.
// registers a new symbol if it is not yet present in the table.
const char *symbol(char *string);

// returns whether a symbol exists.
int symbol_exists(char *string);
