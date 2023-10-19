#include "shell.h"

/**
 * biggy_print - Print a message
 * @format: message to printed
 * @...: additional aguments
 * Return: None
 */

void biggy_print(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	vfprintf(stdout, format, args);
	va_end(args);
}
