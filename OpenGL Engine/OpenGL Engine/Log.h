#pragma once

class Log
{
private:

	Log();

	static void kill();

public:

	static void fatalError(const char *description, ...);
	static void error(const char *description, ...);
	static void log(const char *description, ...);
	static void assert(bool condition, const char *description, ...);
};

