#include "shell.h"
/**
 * interact - interactive shell
 * @av: arg array
 * Return: 0
 */
int interact(char **av)
{
	char *line = NULL, *tkn = NULL;
	size_t len = 0;
	ssize_t chs;
	pid_t pid;
	int status;

	while (true)
	{
		_printstr("#cisfun$ ");
		chs = getline(&line, &len, stdin);
		if (chs == -1)
		{
			free(line);
			_printstr("\n");
			exit(0);
		}
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
	}

	free(line);
	return (0);
}
