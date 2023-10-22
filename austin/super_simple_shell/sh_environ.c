#include "sh_main.h"

/**
 * _getenv - gets path of command
 * @input: path to search
 * @envv: environment variable
 * Return: full path
 */

char *_getenv(char **envv, const char *input)
{
	int inpt_len, value;

	inpt_len = strlen(input);

	while (*envv)
	{
		value = strncmp(input, *envv, inpt_len);
		if (value == 0 && (*envv)[inpt_len] == '=')
		{
			return (&(*envv)[inpt_len + 1]);
		}
		envv++;
	}
	
	return (NULL);
}
