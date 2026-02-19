#include "log.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

static int log_level = LOG_LEVEL_ERROR;

void set_log_level(int level) {
    log_level = level;
}

void __bbb_log(int level, const char *file, int line, const char *func, char *format,
               ...) {
    if (level > log_level) {
        return;
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
