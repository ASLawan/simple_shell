#include <stdio.h>
#include <string.h>
#include <unistd.h>

char *_getenv(char **envv, const char *name)
{
	int name_len, value;

	name_len = strlen(name);
	
	while(*envv)
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
	printf("PATH: %s\n", _getenv(env, "PATH"));
	printf("\n\n");
	printf("HOME: %s\n", _getenv(env, "HOME"));
	printf("\n\n");
	printf("USER: %s\n", _getenv(env, "USER"));

	return (0);
}
