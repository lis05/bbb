#include "parser.h"

void yyerror(const char *token) {
    log_msg("Parser error: \n");
    log_msg("%s\n", token);
    exit(-1);
}
