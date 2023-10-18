::nclude "shell.h"

/**
 * display_interactive - displays prompt
 * @av: arguments array
 * Return: 0, always (success)
 */

int display_interactive(char **av)
{
	char *usr_input = NULL, **arr = NULL;
	char *bye = "Exiting shell...";
	int flag, i = 0;

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
			free(usr_input);
			return (-1);
		}
		flag = semicolon_check(usr_input);
		if (flag == 1)
			arr = handle_semicolon(usr_input);

		/*parse and execute user input*/
		/*execute_input(av, usr_input);*/
		if (arr)
		{
			while (arr[i] != NULL)
			{
				handle_logical(av, arr[i]);
				i++;
			}
		}
		else
			handle_logical(av, usr_input);
	}

	free(usr_input);
	free(bye);
	free(arr);
	return (0);
}
