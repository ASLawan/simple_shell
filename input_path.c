#include "shell.h"
char *get_input_path(char *input);
/**
 * get_input_path - searches for command path
 * @input: command to search for
 * Return: executable path
 */
char *get_input_path(char *input)
{
	struct stat st;
	char *inpt_path = NULL, *file_path = NULL, *inpt_path_cpy = NULL;
	char *tkn, *delim = ":";
	int inpt_len, path_tkn_len;

	inpt_path = _getenv("PATH");
	if (inpt_path)
	{
		inpt_path_cpy = malloc(sizeof(char) * (strlen(inpt_path) + 1));
		if (inpt_path_cpy == NULL)
		{
			perror("Error");
			return (NULL);
		}
		strcpy(inpt_path_cpy, inpt_path);
		inpt_len = strlen(input);
		tkn = strtok(inpt_path_cpy, delim);
		while (tkn != NULL)
		{
			path_tkn_len = strlen(tkn);
			file_path = malloc(sizeof(char) * (inpt_len + path_tkn_len + 2));
			if (file_path == NULL)
			{
				perror("Error");
				return (NULL);
			}
			strcpy(file_path, tkn);
			strcat(file_path, "/");
			strcat(file_path, input);
			strcat(file_path, "\0");
			if (stat(file_path, &st) == 0)
			{
				free(inpt_path_cpy);
				return (file_path);
			}
			else
			{
				free(file_path);
				tkn = strtok(NULL, delim);
			}
		}
		if (stat(input, &st) == 0)
		{
			free(inpt_path_cpy);
			return (input);
		}
		return (NULL);
	}
	free(file_path);
	return (NULL);
}
