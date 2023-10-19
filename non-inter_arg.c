#include "shell.h"
/**
 * non_interact_arg - noninteractive shell
 * @av: arg array
 * Return: 0
 */
int non_interact_arg(char **av)
{
	char *line = NULL, **arr = NULL;
	ssize_t chs, BUFFER = 1024;
	pid_t pid;
	int status;

	line = malloc(sizeof(char) * BUFFER);
	if (line == NULL)
	{
		free(line);
		return (-1);
	}
	chs = read(0, line, BUFFER);
	if (chs == -1)
	{
		free(line);
		_printstr("\n");
		exit(0);
	}
	line[chs] = '\0';
	arr = parse_input(av, line);
	pid = fork();
	if (pid < 0)
	{
		perror("./shell");
	}
	else if (pid == 0)
	{
		if (execve(arr[0], arr, environ) == -1)
		{
			perror("./shell");
		}
	}
	else
	{
		wait(&status);
	}

	free(line);
	return (0);
}
