#include "shell.h"
/**
 * shell_one - prints commands
 * @av: array
 * Return: 0, success
 */
int shell_one(char **av)
{
	char *line = NULL, *tkn = NULL;
	size_t len = 0;
	ssize_t chars_rd;
	pid_t pid;
	int status;

	while (true)
	{
		_printstr("#cisfun$ ");
		chars_rd = getline(&line, &len, stdin);
		if (feof(stdin) || chars_rd == -1)
		{
			_printstr("\n");
			exit(0);
			free(line);
			return (-1);
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
