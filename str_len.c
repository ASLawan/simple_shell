#include "shell.h"

/**
 * _strlen - computes length of string
 *
 * @s: string whose length is to be completed
 *
 * Return: returns a number
 */

int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len += 1;
		s++;
	}

	return (len);
}
