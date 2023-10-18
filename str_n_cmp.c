#include "shell.h"

/**
 * _strncmp - compares n characters in two strings
 * @s1: string one
 * @s2: string two
 * @n: number of characters
 * Return: 0 if n characters are same
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != '\0' &&  s2[i] != '\0')
		{
			if (s1[i] != s2[i])
			{
				return (s1[i] - s2[i]);
			}
		}
	}

	return (0);

}
