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
	chars_read = read(0, line, len);

	if (chars_read == -1)
	{
		perror("Error");
		free(line);
		return (NULL);
	}
	if (chars_read == 0)
	{
		free(line);
		return (NULL);
	}
	line[chars_read] = '\0';
	/*free(line);*/
	return (line);

}
