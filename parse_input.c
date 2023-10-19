#include "shell.h"
/**
 * parse_input - executes commands
 * @usr_input: command to parse
 * Return: av
 */
char **parse_input(char *usr_input)
{
	char *inpt_cpy = NULL, *delim = " \n", *tkn = NULL, **av = NULL;
	int i = 0, j, tkns = 0;

	inpt_cpy = malloc(sizeof(char) * (_strlen(usr_input) + 1));
	if (inpt_cpy == NULL)
		return (NULL);
	_strcpy(inpt_cpy, usr_input);
	tkn = strtok(usr_input, delim);
	while (tkn != NULL)
	{
		tkns++;
		tkn = strtok(NULL, delim);
	}
	tkns++;
	av = malloc(sizeof(char *) * tkns);
	if (av == NULL)
	{
		free(av);
		return (NULL);
	}
	tkn = strtok(inpt_cpy, delim);
	while (tkn != NULL)
	{
		av[i] = malloc(sizeof(char) * _strlen(tkn) + 1);
		if (av[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(av[j]);
			}
			free(av);
			return (NULL);
		}
		_strcpy(av[i], tkn);
		tkn = strtok(NULL, delim);
		i++;
	}
	av[i] = NULL;
	free(inpt_cpy);
	return (av);
}
