#include "sh_main.h"

/**
 * sh_print - prints to stdout
 * @str: string of characters to print
 * Return: nothing
 */

void sh_print(char *str)
{
	int str_len;

	str_len = strlen(str);

	write(STDOUT_FILENO, str, str_len);
}
