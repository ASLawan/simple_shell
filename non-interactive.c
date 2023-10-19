#include "shell.h"
/**
 * non_interact - noninteractive shell
 * @av: arg array
 * Return: 0
 */
int non_interact(char **av)
{
	char *line = NULL, *tkn = NULL;
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
	tkn = strtok(line, " \n");
	av[0] = tkn;
	pid = fork();
	if (pid < 0)
	{
		perror("./shell");
	}
	else if (pid == 0)
	{
		if (execve(av[0], av, environ) == -1)
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
