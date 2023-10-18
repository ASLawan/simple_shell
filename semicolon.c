#include "shell.h"

int semicolon_check(char *input)
{
	int i = 0, flag = 0;

	while (input[i] != '\0')
	{
		if (input[i] == ';')
		{
			flag = 1;
			break;
		}
		i++;
	}

	return (flag);
}
