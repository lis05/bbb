#pragma once

#define LOG_LEVEL_CRIT -1
#define LOG_LEVEL_MSG 0
#define LOG_LEVEL_ERROR 1
#define LOG_LEVEL_INFO 2
#define LOG_LEVEL_DEBUG 3

void set_log_level(int level);

void __bbb_log(int level, const char *file, int line, const char *func, char *format,
               ...);

#define log_msg(...)                                                             \
    do {                                                                         \
        __bbb_log(LOG_LEVEL_MSG, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__); \
    } while (0)

#define log_info(...)                                                             \
    do {                                                                          \
        __bbb_log(LOG_LEVEL_INFO, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__); \
    } while (0)

#define log_debug(...)                                                             \
    do {                                                                           \
        __bbb_log(LOG_LEVEL_DEBUG, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__); \
    } while (0)

#define log_error(...)                                                             \
    do {                                                                           \
        __bbb_log(LOG_LEVEL_ERROR, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__); \
    } while (0)

#define log_crit(...)                                                             \
    do {                                                                          \
        __bbb_log(LOG_LEVEL_CRIT, __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__); \
    } while (0)

#define log_assert(what)                          \
    do {                                          \
        if ((what) == 0) {                        \
            log_crit("Assertion failed: " #what); \
        }                                         \
    } while (0)
