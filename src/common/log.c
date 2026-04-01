#include "log.h"

#include <execinfo.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int log_level = LOG_LEVEL_ERROR;

extern int show_stack_trace;

static const char *prog;
void               set_program_path(const char *p) {
    prog = p;
}

void set_log_level(int level) {
    log_level = level;
}

void __bbb_log(int level, const char *file, int line, const char *func, char *format,
               ...) {
    if (level > log_level) {
        return;
    }

    if (show_stack_trace && (level == LOG_LEVEL_CRIT || level == LOG_LEVEL_ERROR)) {
#define BACKTRACE_LEN 32
        void *buffer[BACKTRACE_LEN];
        int   cnt;

        cnt = backtrace(buffer, BACKTRACE_LEN);

        fprintf(stderr, "Stack trace (prog=%s, %d/%d) :\n", prog, cnt,
                BACKTRACE_LEN);
        for (int i = cnt - 1; i >= 0; i--) {
            static char command[1024];
            static char response[1024];
            int         f = 0;

            snprintf(command, sizeof(command), "addr2line -e %s %p", prog,
                     buffer[i]);

            FILE *fp = popen(command, "r");
            if (fp != NULL) {
                f = response == fgets(response, sizeof(response), fp);
                pclose(fp);
            }

            if (strstr(response, "??") != NULL) {
                f = 0;
            }

            if (!f) {
                continue;
            }

            fprintf(stderr, "  %d: %s", i, response);
        }
#undef BACKTRACE_LEN
    }

    if (level == LOG_LEVEL_CRIT) {
        fprintf(stderr, "CRIT: ");
    } else if (level == LOG_LEVEL_ERROR) {
        fprintf(stderr, "ERROR: ");
    } else if (level == LOG_LEVEL_INFO) {
        fprintf(stderr, "INFO: ");
    } else if (level == LOG_LEVEL_DEBUG) {
        fprintf(stderr, "DEBUG: ");
    }

    if (level == LOG_LEVEL_CRIT || level == LOG_LEVEL_ERROR ||
        level == LOG_LEVEL_DEBUG) {
        fprintf(stderr, "%s:%d (%s): ", file, line, func);
    }

    va_list list;
    va_start(list, format);
    if (level == LOG_LEVEL_MSG) {
        vfprintf(stdout, format, list);
        fflush(stdout);
    } else {
        vfprintf(stderr, format, list);
        fflush(stderr);
    }
    va_end(list);

    if (level == LOG_LEVEL_CRIT) {
        exit(-1);
    }
}
