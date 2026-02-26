#pragma once

#include "../common/common.h"
#include "ast.h"

void yyerror(const char *token);
void parser_init();
struct program_node_t *parser_parse(FILE *fd);


