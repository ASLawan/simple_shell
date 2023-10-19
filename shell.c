#include "shell.h"

/**
 * main - main entry point
 * Return: zero 0
 */

int main(void)
{
	char *cmd = NULL;
	size_t cmd_size = 0;
	ssize_t chars_read;

	while (1)
	{
		d_prompt();

		chars_read = getline(&cmd, &cmd_size, stdin);

		if (chars_read == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}

		/* Remove newline at the end, if it exists */
		if (chars_read > 0 && cmd[chars_read - 1] == '\n')
		{
			cmd[chars_read - 1] = '\0';
		}

		if (strcmp(cmd, "exit") == 0)
		{
			/* Allow the user to exit the shell by typing "exit" */
			free(cmd);
			exit(EXIT_SUCCESS);
		}

		exec_cmd(cmd);
	}

	free(cmd);

	return (0);
}
