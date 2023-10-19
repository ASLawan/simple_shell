#include "shell.h"
/**
 * simple_shell - displays interactive and non-onteractive
 * @av: arg array
 * Return: 0
 */
int simple_shell(char **av)
{

	if (isatty(STDIN_FILENO))
	{
		interact(av);
	}
	else
	{
		non_interact(av);
	}

	return (0);
}
