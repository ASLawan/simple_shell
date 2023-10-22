#include "sh_main.h"

/**
 * get_usr_input_path - finds path to executable
 * @input: user input
 * Return: executable file
 */

char *get_usr_input_path(char **envv, char *input)
{
	struct stat st;
	char *inpt_file_path, *inpt_path_cpy, *inpt_tkn, *inpt_path;
	int inpt_len, inpt_dir_len;

	/*get path from PATH variable*/
	inpt_path = _getenv(envv, "PATH");

	if (inpt_path)
	{
		inpt_path_cpy = malloc(sizeof(char) * strlen(inpt_path));
		if (inpt_path_cpy == NULL)
		{
			perror("Memory not allocated");
			free(inpt_path_cpy);
			return (NULL);
		}
		strcpy(inpt_path_cpy, inpt_path);
		inpt_len = strlen(input);
		/*tokenize path to get directories*/
		inpt_tkn = strtok(inpt_path_cpy, ":");

		while (inpt_tkn)
		{
			inpt_dir_len = strlen(inpt_tkn);
			inpt_file_path = malloc(inpt_len + inpt_dir_len + 2);
			strcpy(inpt_file_path, inpt_tkn);
			strcat(inpt_file_path, "/");
			strcat(inpt_file_path, input);
			strcat(inpt_file_path, "\0");
			/*use stat function to verify file path*/
			if (stat(inpt_file_path, &st) == 0)
			{
				free(inpt_path_cpy);
				return (inpt_file_path);
			}
			else
			{
				free(inpt_file_path);
				inpt_tkn = strtok(NULL, ":");
			}
		}
		free(inpt_path_cpy);

		if (stat(input, &st) == 0)
		{
			return (input);
		}

		return (NULL);
	}
	return (NULL);
}
