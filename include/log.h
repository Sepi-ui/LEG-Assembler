#ifndef ERROR_H
#define ERROR_H

typedef enum {
	LOG_WARNING,
	LOG_DEBUG,
	LOG_TRACE,
	LOG_PERFORMANCE,
	LOG_COUNT,
	LOG_FATAL,
	LOG_ERROR,
	LOG_INFO,
}LogType;

void setLogStream(LogType type, FILE* stream);
void initializeLogStream();


void fatal_log(const char* format, ...);

void error_log(const char* format, ...);

void warning_log(const char* format, ...);

void  debug_log(const char* format, ...);

void trace_log(const char* format, ...);

void info_log(const char* format, ...);

void performance_log(const char* format, ...);
#endif
