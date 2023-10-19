#include "shell.h"

/**
 * *_strcpy - copy string
 *
 * @dest: buffer
 * @src: pointer
 *
 * Return: string
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (i >= 0)
	{
		*(dest + i) = *(src + i);
		if (*(src + i) == '\0')
			break;
		i++;
	}
	return (dest);
}
