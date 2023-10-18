#include "shell.h"
/**
 * execute_input - executes cammands
 * @av: arguments array
 * @usr_input: user command
 * Return: av
 */
#define O_WR 1
char **execute_input(char **av, char *usr_input)
{
	pid_t PID;
	char *inpt = NULL, *inpt_to_execute = NULL, **arr;
	char *set = "setenv", *unset = "unsetenv", *qt = "exit";
	char *dir = "cd";
	int status;

	arr = parse_input(av, usr_input);
	inpt = arr[0];
	if (_strncmp(inpt, set, 6) == 0)
	{
		if(_setenv(arr[1], arr[2], O_WR) == 0)
		{
			_printstr("Successfully set");
			_printstr("\n");
			return (arr);
		}
		else
		{
			_printstr("Failed to set");
			return (NULL);
		}
	}
	if (_strncmp(inpt, unset, 8) == 0)
	{
		if(_unsetenv(arr[1]) == 0)
		{
			_printstr("Successfully unset");
			_printstr("\n");
			return (arr);
		}
		else
		{
			_printstr("Failed to unset");
			return (NULL);
		}
	}
	if (_strncmp(inpt, qt, 4) == 0 && arr[1]) 
	{
		shell_exit((_atoi(arr[1])));
	}
	if (_strncmp(inpt, qt, 4) == 0)
	{
		_shell_exit();
	}
	if (_strncmp(inpt, dir, 2) == 0)
	{
		change_dir(arr[1]);
	}
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
				perror("./hsh");
			}
		}
		else
		{
			wait(&status);
		}
	}
	else
	{
		perror("./hsh");
	}

	free(arr);
	return (arr);
}
