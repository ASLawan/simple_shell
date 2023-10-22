#include <stdio.h>
#include <string.h>

char *_getenv(char **envv, char *name)
{
	int name_len, value;

	name_len = strlen(name);

	while (*envv)
	{
		value = strncmp(name, *envv, name_len);
		if (value == 0 && (*envv)[name_len] == '=')
		{
			return (&(*envv)[name_len + 1]);
		}
		envv++;
	}
	return (NULL);
}

int main(int ac, char **av, char **env)
{
	char *token;
	char *path;
	char *delim = ":";

	path = _getenv(env, "PATH");

	token = strtok(path, delim);

	while (token)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}

	return (0);
}
