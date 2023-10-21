#include "shell.h"
char **execute_inpute(char *usr_input);
/**
 * execute_input - executes cammands
 * @usr_input: user command
 * Return: av
 */
int execute_input(char *usr_input)
{
	pid_t PID;
	char *inpt = NULL, *inpt_to_execute = NULL, **arr;
	int status, flag, i, exit_status = 0;

	arr = parse_input(usr_input);
	inpt = arr[0];
	flag = input_check(arr, inpt, usr_input);
	if (flag != 1)
	{
		inpt_to_execute = get_input_path(inpt);
		if (inpt_to_execute)
		{
			PID = fork();
			if (PID == -1)
			{
				perror("Error");
			}
			else if (PID == 0)
			{
				if (execve(inpt_to_execute, arr, environ) == -1)
				{
					free(inpt_to_execute);
					perror("Error");
				}
			}
			else
			{
				wait(&status);
			}
			free(inpt_to_execute);
		}
		else
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", inpt);
			exit_status = 127;
		}
	}
	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
	}
	free(arr);
	return (exit_status);
}
