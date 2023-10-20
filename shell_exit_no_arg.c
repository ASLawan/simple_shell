#include "shell.h"

/**
 * shell_exit - quits current shell session
 * @arr: exit command
 * @input: user command
 * Return: nothing
 */

void shell_exit(char **arr, char *input)
{
	int status = _atoi(arr[1]), i;

	free(input);
	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
	}
	exit(status);
}
