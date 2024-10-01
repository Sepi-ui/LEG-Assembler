#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include "log.h"

static FILE* log_stream[LOG_COUNT];


void setLogStream(LogType type, FILE* stream) {
if (type < LOG_COUNT) {
	log_stream[type] = stream;
	
	}
}

void initializeLogStream() {
FILE* null_stream = fopen("/dev/null", "w");
if (null_stream) {
	for (int i = 0; i< LOG_COUNT; i++) {
		setLogStream((LogType)i, null_stream);
		printf("Type nr:%d was initialized\n", i);
		};
	}
}
void log_message(FILE* stream, const char* logType, const char* format, va_list args){
	fprintf(stream, "%s", logType); //Print Log Type
	vfprintf(stream, format, args); //Print Message
	if (errno != 0) {//Check errno and print string if !0
		fprintf(stream, ": %s\n", strerror(errno));
		}else{
		fprintf(stream, "\n");
		};
}

void fatal_log(const char* format, ...) {
va_list args;
va_start(args, format);
log_message(log_stream[LOG_FATAL], "[FATAL]", format, args);
va_end(args);
}


void error_log(const char* format, ...) {
va_list args;
va_start(args, format);
log_message(log_stream[LOG_ERROR], "[ERROR]", format, args);
va_end(args);
}


void warning_log(const char* format, ...) {
va_list args;
va_start(args, format);
log_message(log_stream[LOG_WARNING], "[WARNING]", format, args);
va_end(args);
}


void debug_log(const char* format, ...) {
va_list args;
va_start(args, format);
log_message(log_stream[LOG_DEBUG], "[DEBUG]", format, args);
va_end(args);
}

void trace_log(const char* format, ...) {
va_list args;
va_start(args, format);
log_message(log_stream[LOG_TRACE], "[TRACE]", format, args);
va_end(args);
}

void info_log(const char* format, ...) {
va_list args;
va_start(args, format);
log_message(log_stream[LOG_INFO], "[INFO]", format, args);
va_end(args);
}

void performance_log(const char* format, ...) {
va_list args;
va_start(args, format);
log_message(log_stream[LOG_PERFORMANCE], "[PERFORMANCE]", format, args);
va_end(args);
}
