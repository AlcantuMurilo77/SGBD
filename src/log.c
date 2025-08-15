#include "log.h"
#include "stdarg.h"
#include <time.h>

void log_message(LogLevel level, const char *file, int line, const char *fmt,
                 ...) {
  time_t t = time(NULL);
  struct tm tm_info;
  localtime_r(&t, &tm_info);
  char buffer[20];
  strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", &tm_info);

  const char *level_str = "";
  switch (level) {
  case INFO:
    level_str = "INFO";
    break;
  case ERR:
    level_str = "ERR";
    break;
  case DEBUG:
    level_str = "DEBUG";
    break;
  }

  printf("[%s] %s:%d [%s] ", buffer, file, line, level_str);
  va_list args;
  va_start(args, fmt);
  vprintf(fmt, args);
  va_end(args);
  printf("\n");
}
