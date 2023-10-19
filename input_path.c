#include "shell.h"

/**
 * get_input_path - searches for command path
 * @input: command to search for
 * Return: executable path
 */
char *get_input_path(char *input)
{
	struct stat st;
	char *inpt_path = _getenv("PATH");
	char *inpt_path_cpy, *file_path, *tkn;
	int inpt_len = _strlen(input), path_tkn_len;

	if (inpt_path == NULL)
		return (NULL);

	inpt_path_cpy = _strdup(inpt_path);
	if (inpt_path_cpy == NULL)
		return (NULL);

	tkn = _strtok(inpt_path_cpy, ":");
	while (tkn)
	{
		path_tkn_len = _strlen(tkn);
		file_path = malloc(inpt_len + path_tkn_len + 2);
		if (file_path == NULL)
			return (free(inpt_path_cpy), NULL);

		_strcpy(file_path, tkn);
		_strcat(file_path, "/");
		_strcat(file_path, input);
		if (stat(file_path, &st) == 0)
			return (free(inpt_path_cpy), file_path);

		free(file_path);
		tkn = _strtok(NULL, ":");
	}

	if (stat(input, &st) == 0)
		return (free(inpt_path_cpy), input);

	free(inpt_path_cpy);
	return (NULL);
}
