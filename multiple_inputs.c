#include "shell.h"

char **multiple_inputs(char *input)
{
	char *cpy, *delim = " ; ", *tkn, **tkns;
	int num_tkns, i = 0, j;

	cpy = malloc(sizeof(char) * (_strlen(input) + 1));
	if (cpy == NULL)
	{
		free(cpy);
		return (NULL);
	}
	_strcpy(cpy, input);

	tkn = strtok(input, delim);
	while (tkn)
	{
		num_tkns += 1;
		tkn = strtok(NULL, delim);
	}
	num_tkns += 1;

	tkns = malloc(sizeof(char *) * num_tkns);
	if (tkns == NULL)
	{
		free(tkns);
		return (NULL);
	}
	tkn = strtok(cpy, delim);
	while (tkn)
	{
		tkns[i] = malloc(sizeof(char) * (_strlen(tkn) + 1));
		if (tkns[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(tkns[j]);
			}
			free(tkns[i]);
			return (NULL);
		}
		_strcpy(tkns[i], tkn);
		tkn = _strtok(NULL, delim);
		i++;
	}
	tkns[i] = NULL;
	free(cpy);
	return (tkns);

}
