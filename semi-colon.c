#include "shell.h"

char **handle_semicolon(char *input)
{
	char **arr, *arr_tkn;
	char *delim = ";";
	int tkns = 0;

	arr = malloc(sizeof(char *) * 3);
	if (arr == NULL)
	{
		free(arr);
		return (NULL);
	}
	arr_tkn = strtok(input, delim);
	while (arr_tkn != NULL)
	{
		arr[tkns] = arr_tkn;
		arr_tkn = strtok(NULL, delim);
		tkns++;
	}
	arr[tkns] = NULL;

	return (arr);
}
