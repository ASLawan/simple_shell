#include "shell.h"
/**
 * get_input - receives user input
 * Return: user input
 */

#define BUFFER 1024

char *get_input()
{
	char *buffer;
	ssize_t bytes_read;

	buffer = malloc(BUFFER * sizeof(char));
	if (buffer == NULL)
	{
		_printstr("memory not allocatd");
		free(buffer);
		return (NULL);
	}

	bytes_read = read(0, buffer, BUFFER);
	if (bytes_read == -1)
	{
		free(buffer);
		return (NULL);
	}

	buffer[bytes_read] = '\0';

	return (buffer);
}
