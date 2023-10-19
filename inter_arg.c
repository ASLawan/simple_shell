#include "shell.h"
/**
 * interact_arg - interactive shell
 * @av: arg array
 * Return: 0
 */
int interact_arg(char **av)
{
	char *line = NULL, **arr = NULL;
	size_t len = 0;
	ssize_t chs = 0;
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
			return (-1);
		}
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
	}
	return (0);
}
