#include "shell.h"
/**
 * _putenv - inserts new env variable
 * @name: variable to insert
 * Return: 0 on success
 */
int _putenv(char *name)
{
	char **env, **new_env;
	int num_vars = 0, i;

	if (name == NULL)
	{
		return (-1);
	}
	env = environ;
	while (env[num_vars] != NULL)
	{
		num_vars++;
	}
	new_env = malloc(sizeof(char *) * (num_vars + 2));
	if (new_env == NULL)
	{
		return (-1);
	}
	for (i = 0; i < num_vars; i++)
	{
		new_env[i] = env[i];
	}
	new_env[num_vars] = strdup(name);
	if (new_env[num_vars] == NULL)
	{
		free(new_env);
		return (-1);
	}
	environ = new_env;
	free(new_env);
	return (0);
}
