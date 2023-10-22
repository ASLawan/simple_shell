#include "sh_main.h"

/**
 * exec_usr_input - executes user commands
 * @path: user command
 * @count: number of arguments
 * Return: nothing
 */

void exec_usr_input(char **envv, char **av)
{
	char *input = NULL;
	char *input_to_execute = NULL;
	pid_t pid;
	int status;
	

	if (av)
	{
		pid = fork();

		if (pid < 0)
		{
			perror("Error: ");
		}
		else if(pid == 0)
		{
			input = av[0];
			input_to_execute = get_usr_input_path(envv,input);
			if (execve(input_to_execute, av, NULL) == -1)
			{
				perror("Error: ");
			}
		}
		else
		{
			wait(&status);
		}
	}
}
