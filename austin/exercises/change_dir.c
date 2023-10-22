#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 1024

void change_dir(char *dir)
{
	char cwd[BUFFER];
	static char prev_dir[BUFFER];
	int dir_check;

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("Error");
		return;
	}
	if (dir == NULL)
	{
		dir = getenv("HOME");
	}
	if (dir == "-")
	{
		dir = prev_dir;
	}
	dir_check = chdir(dir);
	if (dir_check != 0)
	{
		perror("Error");
		return;
	}
	setenv("PWD", dir, 1);
	strcpy(prev_dir, cwd);
}


int main()
{
	char input[BUFFER];
	char *cmd, *arg;

	while(1)
	{
		printf("Enter command: ");
		fgets(input, sizeof(input), stdin);

		cmd = strtok(input, " \n");
		arg = strtok(NULL, " \n");

		if (strcmp(cmd, "cd") == 0)
		{
			change_dir(arg);
		}
		else
		{
			printf("Unknown cmd: %s\n", cmd);
		}
	}
	return (0);
}
