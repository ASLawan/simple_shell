#include "sh_main.h"

/**
 * parse_usr_input - parses user input
 * @line: user input
 * @tokens: array of arguments
 * Return: array of tokens
 */

char **parse_usr_input(int n, char *line_cpy)
{
	char *tkn, **tkns;
	char *delim = " \n";
	int i = 0, j;
	
	tkns = malloc(sizeof(char *) * n);
	if (tkns == NULL)
	{
		perror("Memory not allocated");
		free(tkns);
		return (NULL);
	}

	tkn = strtok(line_cpy, delim);
	while (tkn)
	{
		tkns[i] = malloc(sizeof(char) * strlen(tkn));
		if (tkns[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(tkns[j]);
			}
			free(tkns);
			return (NULL);
		}
		strcpy(tkns[i], tkn);
		tkn = strtok(NULL, delim);
		i++;
	}
	tkns[i] = NULL;
	

	return (tkns);
}
