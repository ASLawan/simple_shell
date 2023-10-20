#include "shell.h"

/**
 * get_usr_input - reads user input
 * Return: buffer
 */

char *get_usr_input(void)
{
	char *line = NULL;
	size_t len = 1024;
	ssize_t chars_read;

	line = malloc(sizeof(char) * len);
	if (line == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	chars_read = read(1, line, len);

	if (chars_read == -1)
	{
		perror("Error");
		return (NULL);
	}

	/*free(line);*/
	return (line);

}
