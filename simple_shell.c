#include "shell.h"

/**
 * main - program start point
 * @ac: argument count
 * @av: argument array
 * Return: 0 always (success)
 */

int main(int ac, char **av)
{
	(void)ac;

	if (isatty(STDIN_FILENO) == 1)
	{
		display_interactive(av);
	}
	else
	{
		display_non_interactive(av);
	}

	return (0);
}
