#include "shell.h"

int non_interact(char **av);

/**
 * non_interact - noninteractive shell
 * @av: arg array
 * Return: 0
 */

int non_interact(char **av)
{
	char *line = NULL, *tkn = NULL;
	size_t BUFFER = 1024;
	ssize_t chs;
	pid_t pid;
	int status;

	line = (char *)malloc(BUFFER);
	if (line == NULL)
	{
		perror("Memory allocation failed");
		return (-1);
	}

	chs = read(STDIN_FILENO, line, BUFFER);
	if (chs == -1)
	{
		perror("Read error");
		free(line);
		_printstr("\n");
		exit(EXIT_FAILURE);
	}

	line[chs] = '\0';
	tkn = strtok(line, " \n");
	av[0] = tkn;
	pid = fork();

	if (pid < 0)
	{
		perror("Fork failed");
	}
	else if (pid == 0)
	{
		char *new_environ[] = { NULL };

		if (execve(av[0], av, new_environ) == -1)
		{
			perror("Execution error");
			free(line);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}

	free(line);
	return (0);
}
