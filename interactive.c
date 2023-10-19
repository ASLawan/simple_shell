#include "shell.h"

/**
 * display_interactive - displays prompt
 * @av: arguments array
 * Return: 0, always (success)
 */

int display_interactive(char **av)
{
	char *line = NULL;
	size_t len = 0;

	while (true)
	{
		/*display prompt*/
		display_iprompt();

		/*read user input*/
		getline(&line, &len, stdin);
		
		execute_input(av, line);
	}
	free(line);
	return (0);
}
