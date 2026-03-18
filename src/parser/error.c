#include "error.h"

#include "stdarg.h"

// for now, only the first line is displayed...
void context_msg(const tfrag_t *frag, const char *format, ...) {
    FILE *fd = NULL;
    if (frag->filename == NULL) {
        log_error("Text fragment missing filename...\n");
        goto msg_print;
    }

    fd = fopen(frag->filename, "r");
    if (fd == NULL) {
        log_error("Failed to open %s: %s\n", frag->filename, strerror(errno));
        goto msg_print;
    }

    size_t line = 0;
    while (line < frag->begin_line) {
        char c = fgetc(fd);
        if (c == EOF) {
            break;
        }
        if (c == '\n') {
            line++;
        }
    }

    if (line != frag->begin_line) {
        log_error("Failed to scroll.\n");
        goto msg_print;
    }

    if (frag->begin_line == frag->end_line) {
        log_msg("In %s:%zu, cols %zu..%zu\n", frag->filename, frag->begin_line + 1,
                frag->begin_col + 1, frag->end_col);
    } else {
        log_msg("In %s, lines %zu..%zu, cols %zu..%zu\n", frag->filename,
                frag->begin_line + 1, frag->end_line + 1, frag->begin_col + 1,
                frag->end_col);
        // this might break things, but i dont care rn
    }

    log_msg(">>>     ");

    while (true) {
        char c = fgetc(fd);

        if (c == EOF) {
            break;
        }

        if (c == '\t') {
            log_msg("    ");
        } else if (c == '\n') {
            if (frag->end_line != frag->begin_line) {
                log_msg("         (... and %zu more lines)\n",
                        frag->end_line - frag->begin_line);
            }
            break;
        } else {
            log_msg("%c", c);
        }
    }

    log_msg("\n        ");
    for (size_t i = 0; i < frag->begin_col; i++) {
        log_msg(" ");
    }
    for (size_t i = 0; i < frag->end_col - frag->begin_col; i++) {
        log_msg("^");
    }
    log_msg("\n");

msg_print:
    if (fd != NULL) {
        fclose(fd);
    }

    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    printf("\n\n");
}

