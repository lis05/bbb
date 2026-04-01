#include "parser.h"
#include "error.h"

void yyerror(const char *token) {
    extern tfrag_t error_frag;
    log_msg("[== Parser error!\n");
    log_msg("[== Happened in: %s, lines %zu-%zu, cols %zu-%zu, token: '%s'\n",
            error_frag.filename, error_frag.begin_line, error_frag.end_line,
            error_frag.begin_col, error_frag.end_col, error_frag.token);
    log_msg("[== Bison error message: '%s'\n", token);
    context_msg(&error_frag, "Parser error: %s\n", token);
    exit(-1);
}

void parser_init() {
}

struct program_node_t *parsing_result;

struct program_node_t *parser_parse(const char *filename) {
    log_info("Starting parser on file: %s\n", filename);

    extern FILE *yyin;
    if ((yyin = fopen(filename, "r")) == NULL) {
        log_error("Failed to open %s: %s\n", filename, strerror(errno));
        return NULL;
    }

    extern tfrag_t cur_frag;
    tfrag_init(&cur_frag, NULL, filename, 0, 0, 0, 0, 0, 0);

    extern int yyparse();
    if (yyparse()) {
        log_error("yyparse()\n");
        return NULL;
    }

    fclose(yyin);

    return parsing_result;
}
