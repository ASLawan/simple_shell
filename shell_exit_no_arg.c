#include "shell.h"

/**
 * shell_exit - quits current shell session
 * @status: exit command
 * Return: nothing
 */

void shell_exit(int status)
{
	exit(status);
}
