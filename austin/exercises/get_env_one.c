#include "main.h"

extern char **environ;

char *_getenv(const char *name)
{
	char **env = environ;
	int name_len, num;

	name_len = strlen(name);
	while (*env)
	{
		/*use strncmp and compare first n bytes of two strings*/
		num = strncmp(name, *env, name_len);
		if (num == 0 && (*env)[name_len] == '=')
		{
			return (&(*env)[name_len] + 1);
		}
		env++;
	}	

	return (NULL);
}
