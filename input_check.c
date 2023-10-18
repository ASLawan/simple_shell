#include "shell.h"
/**
 * input_check - executes cammands
 * @inpt: executable
 * @arr: array
 * Return: nothing
 */
int input_check(char **arr, char *inpt)
{
	char *set = "setenv", *unset = "unsetenv", *qt = "exit";
	char *dir = "cd";
	int flag = 0;

	if (_strncmp(inpt, set, 6) == 0)
	{
		if (_setenv(arr[1], arr[2], 1) == 0)
		{
			_printstr("Successfully set\n");
			flag = 1;
		}
		else
		{
			_printstr("Failed to set");
		}
	}
	if (_strncmp(inpt, unset, 8) == 0)
	{
		if (_unsetenv(arr[1]) == 0)
		{
			_printstr("Successfully unset\n");
			flag = 1;
		}
		else
		{
			_printstr("Failed to unset\n");
		}
	}
	if (_strncmp(inpt, qt, 4) == 0 && arr[1])
		shell_exit((_atoi(arr[1])));
	if (_strncmp(inpt, qt, 4) == 0)
		_shell_exit();
	if (_strncmp(inpt, dir, 2) == 0)
		change_dir(arr[1]);
	return (flag);
}
