#include "main.h"

int _setenv(const char *name, const char *value, int overwrite)
{
	char *new_str;

	if (name == NULL || value == NULL)
	{
		return (-1);
	}
	if (strchr(name, '=') != NULL)
	{
		return (-1);
	}
	if (overwrite == 0 && getenv(name) != NULL)
	{
		return (-1);
	}
	new_str = malloc(strlen(name) + strlen(value) + 2);
	if (new_str == NULL)
	{
		free(new_str);
		return (-1);
	}

	strcpy(new_str, name);
	strcat(new_str, "=");
	strcat(new_str, value);

	_putenv(new_str);

	free(new_str);

	return (0);
}
