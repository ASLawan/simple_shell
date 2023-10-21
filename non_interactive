#include "shell.h"

/**
 * display_non_interactive - displays prompt
 * @av: arguments array
 * Return: nothing
 */

void display_non_interactive(char **av)
{
	char *usr_input;
	(void)av;

	/*display prompt*/
	display_non_iprompt();

	/*read user input*/
	usr_input = get_input();

	/*parse and execute user input*/
	execute_input(usr_input);

	free(usr_input);

}
