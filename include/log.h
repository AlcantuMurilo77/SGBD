#ifndef LOG_H
#define LOG_H

#include <stdio.h>

// Here I'll define the log level
typedef enum { INFO, ERR, DEBUG } LogLevel;

#define LOG_INFO(fmt, ...)                                                     \
  log_message(INFO, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define LOG_ERR(fmt, ...)                                                      \
  log_message(ERR, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define LOG_DEBUG(fmt, ...)                                                    \
  log_message(DEBUG, __FILE__, __LINE__, fmt, ##__VA_ARGS__)

void log_message(LogLevel level, const char *file, int line, const char *fmt,
                 ...);

#endif