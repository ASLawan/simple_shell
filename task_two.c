#include "shell.h"
/**
 * shell_two - handles arguments
 * @av: argument array
 * Return: 0 success
 */
int shell_two(char **av)
{
	char *line = NULL, **arr;
	size_t len = 0;
	ssize_t chars_rd;
	pid_t pid;
	int status;

	while (true)
	{
		_printstr("#cisfun$ ");
		chars_rd = getline(&line, &len, stdin);
		if (chars_rd == -1)
		{
			if (feof(stdin))
			{
				_printstr("\n");
				exit(0);
			}
			free(line);
			return (-1);
		}
		arr = parse_input(av, line);
		pid = fork();
		if (pid < 0)
			perror("./shell");
		else if (pid == 0)
		{
			if (execve(arr[0], arr, environ) == -1)
			{
				perror("./shell");
			}
		}
		else
			wait(&status);
	}
	free(line);
	return (0);
}
