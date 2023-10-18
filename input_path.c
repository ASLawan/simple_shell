#include "shell.h"
/**
 * get_input_path - searches for command path
 * @input: command to search for
 * Return: executable path
 */
char *get_input_path(char *input)
{
	struct stat st;
	char *inpt_path, *file_path, *inpt_path_cpy;
	char *tkn, *delim = ":";
	int inpt_len, path_tkn_len;

	inpt_path = _getenv("PATH");
	if (inpt_path)
	{
		inpt_path_cpy = malloc(sizeof(char) * (_strlen(inpt_path) + 1));
		if (inpt_path_cpy == NULL)
		{
			free(inpt_path_cpy);
			perror("Error");
			return (NULL);
		}
		_strcpy(inpt_path_cpy, inpt_path);
		inpt_len = _strlen(input);
		tkn = _strtok(inpt_path_cpy, delim);
		while (tkn)
		{
			path_tkn_len = _strlen(tkn);
			file_path = malloc(sizeof(char) * (inpt_len + path_tkn_len + 2));
			if (file_path == NULL)
			{
				free(file_path);
				perror("Error");
				return (NULL);
			}
			_strcpy(file_path, tkn);
			_strcat(file_path, "/");
			_strcat(file_path, input);
			_strcat(file_path, "\0");
			if (stat(file_path, &st) == 0)
			{
				free(inpt_path_cpy);
				return (file_path);
			}
			else
			{
				free(file_path);
				tkn = _strtok(NULL, delim);
			}
		}
		if (stat(input, &st) == 0)
		{
			free(inpt_path_cpy);
			return (input);
		}
		return (NULL);
	}
	return (NULL);
}
