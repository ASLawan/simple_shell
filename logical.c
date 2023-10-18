#include "shell.h"

int handle_logical(char **av, char *input)
{
	char **arr, *arr_tkn;
	char *delim;
	int tkns = 0, i;

	delim = delimiter_check(input);
	arr = malloc(sizeof(char *) * 3);
	if (arr == NULL)
	{
		free(arr);
		return (1);
	}
	arr_tkn = strtok(input, delim);
	while (arr_tkn != NULL)
	{
		arr[tkns] = arr_tkn;
		arr_tkn = strtok(NULL, delim);
		tkns++;
	}
	
	for (i = 0; i < tkns; i++)
	{
		execute_input(av, arr[i]);
	}

	free(arr);
	return (0);
}
