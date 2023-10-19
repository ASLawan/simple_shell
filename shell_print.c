#include "shell.h"

/**
 * _printstr - prints to output
 * @str: string to print
 * Return: nothing
 */

void _printstr(char *str)
{
	int str_len;

	str_len = strlen(str);

	write(STDOUT_FILENO, str, str_len);
}
