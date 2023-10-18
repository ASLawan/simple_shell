#include "shell.h"

/**
 * _getenv - prints environment variable
 * @input: path to search for
 * Return: path
 */


char *_getenv(char *input)
{
	char **envv;
	int inpt_len, value;

	envv = environ;
	inpt_len = _strlen(input);

	while (*envv)
	{
		value = _strncmp(input, *envv, inpt_len);
		if (value == 0 && (*envv)[inpt_len] == '=')
		{
			return (&(*envv)[inpt_len + 1]);
		}
		envv++;
	}

	return (NULL);
}
