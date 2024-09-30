#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include "error.h"

void error_log(const char* format, ...){
	va_list args;
	va_start(args, format);

	//print Error Messages
	vfprintf(stderr, format, args);
	if (errno != 0){
	fprintf(stderr, ": %s\n", strerror(errno));	
		};
	va_end(args);
	}
