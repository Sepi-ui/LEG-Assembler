#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include "log.h"

void error_log(const char* format, ...){
	va_list Eargs;
	va_start(Eargs, format);

	//print Error Messages
	vfprintf(stderr, format, Eargs);
	if (errno != 0){
	fprintf(stderr, ": %s\n", strerror(errno));	
		};
	va_end(Eargs);
	}

void warning_log(const char* format, ...){
	va_list Wargs;
	va_start(Wargs, format);

	//Print Warning Message
	vfprintf(stderr, format, Wargs);
	if (errno != 0){
		fprintf(stderr, ": %s\n", strerror(errno));
		};
	va_end(Wargs);
	}


void debug_log(const char* format, ...){
	va_list Dargs;
	va_start(Dargs, format);

	//Print Warning Message
	vfprintf(stderr, format, Dargs);
	if (errno != 0){
		fprintf(stderr, ": %s\n", strerror(errno));
		};
	va_end(Dargs);
	}


void trace_log(const char* format, ...){
	va_list Targs;
	va_start(Targs, format);

	//Print Warning Message
	vfprintf(stderr, format, Targs);
	if (errno != 0){
		fprintf(stderr, ": %s\n", strerror(errno));
		};
	va_end(Targs);
	}


void info_log(const char* format, ...){
	va_list Largs;
	va_start(Largs, format);

	//Print Warning Message
	vfprintf(stderr, format, Largs);
	if (errno != 0){
		fprintf(stderr, ": %s\n", strerror(errno));
		};
	va_end(Largs);
	}


void performance_log(const char* format, ...){
	va_list Pargs;
	va_start(Pargs, format);

	//Print Warning Message
	vfprintf(stderr, format, Pargs);
	if (errno != 0){
		fprintf(stderr, ": %s\n", strerror(errno));
		};
	va_end(Pargs);
	}






