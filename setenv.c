#include "shell.h"
/**
 * _setenv - sets environment variable
 * @name: name of variable to set
 * @value: value to set
 * @overwrite: to overwrite or not
 * Return: o in success
 */
int _setenv(char *name, char *value, int overwrite)
{
	int sett, vlen, nlen;
	char *new_set = NULL;

	if (name == NULL || name[0] == '\0'
	|| strchr(name, '=') != NULL || value == NULL)
	{
		return (-1);
	}

	if (_getenv(name) != NULL && overwrite == 0)
	{
		return (0);
	}
	_unsetenv(name);
	nlen = strlen(name);
	vlen = strlen(value);
	new_set = malloc(sizeof(char) * (vlen + nlen + 2));
	if (new_set == NULL)
	{
		return (-1);
	}
	strcpy(new_set, name);
	strcat(new_set, "=");
	strcat(new_set, value);
	sett = _putenv(new_set);
	if (sett != 0)
	{
		return (-1);
	}
	free(new_set);
	return (0);
}
