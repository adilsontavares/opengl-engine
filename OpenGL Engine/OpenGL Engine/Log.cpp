#include "Log.h"
#include <stdio.h>
#include <cstdlib>
#include <stdarg.h>

#define LOGF(file, format) \
{ \
	va_list argptr; \
	va_start(argptr, format); \
	vfprintf(file, format, argptr); \
	va_end(argptr); \
}

void Log::kill()
{
	getchar();
	exit(1);
}

void Log::fatalError(const char * description, ...)
{
	printf("FATAL ERROR: ");
	LOGF(stderr, description);
	printf("\n");
	kill();
}

void Log::error(const char * description, ...)
{
	printf("ERROR: ");
	LOGF(stderr, description);
	printf("\n");
}

void Log::log(const char * description, ...)
{
	LOGF(stdout, description);
	printf("\n");
}

void Log::assert(bool condition, const char * description, ...)
{
	if (!condition)
	{
		printf("ASSERTION FAILED: ");
		LOGF(stderr, description);
		printf("\n");
		kill();
	}
}
