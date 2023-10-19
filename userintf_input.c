#include "shell.h"


/**
 * read_cmd - Read a command
 * @cmd: Buffer to store the command
 * @size: buffer size
 * Return: None
 */

void read_cmd(char *cmd, size_t size)
{
	if (fgets(cmd, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			biggy_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			biggy_print("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	cmd[strcspn(cmd, "\n")] = '\0'; /* Remove newline */
}

