#include "shell.h"

int interact(char **av);

/**
 * interact - interactive shell
 * @av: arg array
 * Return: 0
 */

int interact(char **av)
{
	char *line = NULL, *tkn = NULL;
	size_t len = 512;
	ssize_t chs;
	pid_t pid;
	int status;

	while (true)
	{
		line = malloc(sizeof(char) * len);

		if (line == NULL)
		{
			perror("Error");
			return (-1);
		}

		_printstr("#cisfun$ ");

		chs = read(1, line, len);

		if (chs == -1)
		{
			free(line);
			_printstr("\n");
			exit(0);
		}

		tkn = strtok(line, " \n");
		if (tkn == NULL)
		{
			free(line);
			continue;
		}

		av[0] = tkn;
		pid = fork();

		if (pid < 0)
		{
			perror("./shell");
			free(line);
		}
		else if (pid == 0)
		{
			char *new_environ[] = { NULL };

			if (execve(av[0], av, new_environ) == -1)
			{
				perror("./shell");
				free(line);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
			free(line);
		}
	}

	return (0);
}
