#include "shell.h"

/**
 * *_strchr - locates a character in a string
 *
 * @s: the string to check in
 * @c: the character to look for
 *
 * Return: character if found or NULL if not
 */

char *_strchr(char *s, char c)
{
		unsigned int i = 0;

	for (; *(s + i) != '\0'; i++)
		if (*(s + i) == c)
			return (s + i);
	if (*(s + i) == c)
		return (s + i);
	return ('\0');
}
