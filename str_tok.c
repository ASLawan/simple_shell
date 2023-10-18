#include "shell.h"

/**
 * _strtok - breaks string into words {tokens}
 * @str: string to break
 * @delim: break points
 * Return: tokens
 */

char *_strtok(char *str, const char *delim)
{
	char *start = NULL;
	static char *p = NULL;

	if (str)
	{
		p = str;
	}
	else if (!p)
	{
		return (NULL);
	}
	start = p;

	while (*p && !strchr(delim, *p))
	{
		p++;
	}
	if (*p)
	{
		*p = 0;
		p++;
	}
	else
	{
		p = 0;
	}

	return (start);
}

