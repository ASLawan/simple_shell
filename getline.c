#include "shell.h"

/**
 * get_usr_input - reads user input
 * Return: buffer
 */

char *get_usr_input(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t chars_read;

	chars_read = getline(&line, &len, stdin);

	if (chars_read == -1)
	{
		free(line);
		return (NULL);
	}

	/*free(line);*/
	return (line);

}
