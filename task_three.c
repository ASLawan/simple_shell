#include "shell.h"
/**
 * handle_path - handles argumen,s
 * @av: argument array
 * Return: 0 success
 */
int handle_path(char **av)
{
	char *line = NULL;
	size_t BUFFER = 512;
	ssize_t chs = 0;

	line = malloc(sizeof(char) * BUFFER);
	if (line == NULL)
	{
		perror("\n");
		return (-1);
	}
	if (isatty(STDIN_FILENO))
	{
		while (true)
		{
			_printstr(":) ");
			chs = read(1, line, BUFFER);
			if (chs == -1)
			{
				free(line);
				_printstr("\n");
				exit(0);
			}
			execute_input(av, line);
		}
	}
	else
	{
		_printstr(":) ");
		chs = read(0, line, BUFFER);
		if (chs == -1)
		{
			_printstr("\n");
			free(line);
			return (-1);
		}
		execute_input(av, line);
	}
	free(line);
	return (0);
}
