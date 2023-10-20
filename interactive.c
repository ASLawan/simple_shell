#include "shell.h"

/**
 * display_interactive - displays prompt
 * @av: arguments array
 * Return: 0, always (success)
 */

int display_interactive(char **av)
{
	char *usr_input = NULL;
	char *bye = "Exiting shell...";

	while (true)
	{
		/*display prompt*/
		display_iprompt();

		/*read user input*/
		usr_input = get_usr_input();
		if (usr_input == NULL)
		{
			_printstr("./hsh: ");
			_printstr(bye);
			_printstr("\n");
			return (-1);
		}

		/*parse and execute user input*/
		execute_input(av, usr_input);
	}

	free(usr_input);
	return (0);
}
