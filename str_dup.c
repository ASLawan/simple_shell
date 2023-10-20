#include "shell.h"

/**
 * _strdup - duplicates given string
 * @str: string to duplicate
 * Return: string duplicate
 */

char *_strdup(char *str)
{
	char *new_str;
	char *ptr;

	new_str = (char *) malloc(sizeof(char) * (_strlen(str) + 1));
	if (new_str == NULL)
	{
		free(new_str);
		return (NULL);
	}

	ptr = new_str;

	while (*str != '\0')
	{
		*ptr++ = *str++;
	}
	*ptr = '\0';


	return (new_str);


}
