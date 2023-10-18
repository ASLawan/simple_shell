#include "shell.h"

char *delimiter_check(char *input)
{
	int i = 0;
	char *delim;

	while (input[i] != '\0')
	{
		if (input[i] == '&' && input[i + 1] == '&')
		{
			delim = "&& ";
			break;
		}
		if (input[i] == '|' && input[i + 1] == '|')
		{
			delim = "|| ";
			break;
		}
		i++;
	}

	return (delim);
}
