#include "shell.h"

/**
 * simple_shell - program entry point
 * @av: argument array
 * Return: 0 always (success)
 */

void simple_shell(char **av)
{

	if (isatty(STDIN_FILENO) == 1)
	{
		display_interactive(av);
	}
	else
	{
		display_non_interactive(av);
	}

}
