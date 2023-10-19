#include "shell.h"
/**
 * handle_args - displays interactive and non-onteractive
 * @av: arg array
 * Return: 0
 */
int handle_args(char **av)
{

	if (isatty(STDIN_FILENO))
	{
		interact_arg(av);
	}
	else
	{
		non_interact_arg(av);
	}

	return (0);
}
