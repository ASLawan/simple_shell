#include "shell.h"
/**
 * execute_input - executes cammands
 * @arr: arguments array
 * @usr_input: user command
 * Return: av
 */
char **execute_input(char **arr, char *usr_input)
{
	pid_t PID;
	char *inpt = NULL, *inpt_to_execute = NULL;
	int status, flag;

	arr = parse_input(usr_input);
	inpt = arr[0];
	flag = input_check(arr, inpt);
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
					perror(inpt);
				}
			}
			else
			{
				wait(&status);
			}
		}
		else
		{
			perror(inpt);
		}
	}
	free(arr);
	return (arr);
}
