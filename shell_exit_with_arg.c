#include "shell.h"

/**
 * _shell_exit - quits current shell session
 * @arr: argument array
 * @input: user command
 * Return: nothing
 */

void _shell_exit(char **arr, char *input)
{
	free(input);
	free(arr[0]);
	free(arr);
	exit(EXIT_SUCCESS);
}
