#include "main.h"

extern char **environ;

int _unsetenv(const char *name)
{
	int count = 0, i, index = -1;

	while (environ[count] != NULL)
	{
		count++;
	}

	for (i = 0; i < count; i++)
	{
		if (strncmp(name, environ[i], strlen(name)) == 0)
		{
			if (environ[i][strlen(name)] == '=')
			{
				index = i;
				break;
			}
		}
	}

	if (index != -1)
	{
		for(i = index; i < count - 1; i ++)
		{
			environ[i] = environ[i + 1];
		}
		environ[count - 1] = NULL;
		return (0);
	}
	
	return (-1);
}
