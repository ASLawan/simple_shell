#include "shell.h"
/**
 * _unsetenv - unsets environment variables
 * @name: variable to unset
 * Return: 0 on success
 */

int _unsetenv(char *name)
{
	int count = 0, i, index = -1;

	while (environ[count] != NULL)
	{
		count++;
	}

	for (i = 0; i < count; i++)
	{
		if (_strncmp(name, environ[i], _strlen(name)) == 0)
		{
			if (environ[i][_strlen(name)] == '=')
			{
				index = i;
				break;
			}
		}
	}

	if (index != -1)
	{
		for (i = index; i < count - 1; i++)
		{
			environ[i] = environ[i + 1];
		}
		environ[count - 1] = NULL;
		return (0);
	}
	return (-1);
}
