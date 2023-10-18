#include "shell.h"
/**
 * parse_input - executes commands
 * @av: arguments array
 * @usr_input: command to parse
 * Return: av
 */
char **parse_input(char **av, char *usr_input)
{
	char *inpt_cpy = NULL, *delim = " \n", *tkn = NULL;
	int i = 0, j, tkns = 0;

	inpt_cpy = malloc(sizeof(char) * (_strlen(usr_input) + 1));
	if (inpt_cpy == NULL)
	{
		free(inpt_cpy);
		return (NULL);
	}
	_strcpy(inpt_cpy, usr_input);
	tkn = _strtok(usr_input, delim);
	while (tkn)
	{
		tkns += 1;
		tkn = _strtok(NULL, delim);
	}
	tkns += 1;
	av = malloc(sizeof(char *) * tkns);
	if (av == NULL)
	{
		perror("Error");
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
			free(av[i]);
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
