#include "shell.h"
/**
 * check_space - checks for empty spaces
 * @input: user command
 * Return: nothing
 */
char check_space(char *input)
{
	char *tkn = input;

	if (input == NULL)
		return ('\0');
	while (*tkn == ' ')
	{
		tkn++;
	}
	return (*tkn);
}
/**
 * main - program entry point
 * @av: arguments array
 * Return: 0, always (success)
 */
int main(void)
{
	char *line = NULL;
	size_t n = 0;
	int count, exit_status = 0;

	while (true)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			display_iprompt();
		}
		/*read user input*/
		count  = getline(&line, &n, stdin);
		if (count == -1)
		{
			free(line);
			exit(exit_status);
		}
		line[count - 1] = '\0';
		if (check_space(line) == '\0')
		{
			continue;
		}
		/*parse and execute user input*/
		if (line)
		{
			exit_status = execute_input(line);
		}
	}
	free(line);
	return (0);
}
