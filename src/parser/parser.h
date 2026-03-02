#pragma once

#include "../common/common.h"
#include "ast.h"

extern struct program_node_t *parsing_result;
void yyerror(const char *token);
void parser_init();
struct program_node_t *parser_parse(const char *filename);


