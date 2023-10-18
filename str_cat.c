#include "shell.h"

/**
 * *_strcat - concatenates two strings
 *
 * @dest: string to concatenate
 * @src: string to concatenate with
 *
 * Return: new string
 */

char *_strcat(char *dest, char *src)
{
	int len1 = 0, len2 = 0, i, j, k;

	for (i = 0; src[i] != '\0'; i++)
	{
		len1 += 1;
	}
	for (j = 0; dest[j] != '\0'; j++)
	{
		len2 += 1;
	}
	for (k = 0; k <= len1; k++)
	{
		dest[len2 + k] = src[k];
	}
	return (dest);
}
