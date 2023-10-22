#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char **tokenize(int ac, char **av)
{
	char **tkns;
	char *tkn, *delim = " ";
	int i = 0, j;

	tkns = malloc(sizeof(char *) * ac);
	if (tkns == NULL)
	{
		return (NULL);
	}

	tkn = strtok(av[1], delim);

	while (tkn)
	{
		tkns[i] = malloc(strlen(tkn) + 1);
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

int main(int ac, char **av)
{
	char **tkns;
	int i;

	tkns = tokenize(ac, av);
	if (tkns == NULL)
	{
		return (-1);
	}

	for (i = 0; tkns[i] != NULL; i++)
	{
		fwrite(tkns[i], strlen(tkns[i]), 1, stdout);
		fwrite(" ", 1, 1, stdout);
	}
	fwrite("\n", 1, 1, stdout);

	for (i = 0; tkns[i] != NULL; i++)
	{
		free(tkns[i]);
	}
	free(tkns);

	return (0);
}
