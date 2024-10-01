#ifndef ERROR_H
#define ERROR_H

void fatal_log(const char* format, ...);

void error_log(const char* format, ...);

void warning_log(const char* format, ...);

void  debug_log(const char* format, ...);

void trace_log(const char* format, ...);

void info_log(const char* format, ...);

void performance_log(const char* format, ...);
#endif
