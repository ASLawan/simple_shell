#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int ac, char **av)
{
	char *path;
	char *file_path;
	char *delim = ":";
	char *dir_path;

	if (ac < 2)
	{
		printf("Usage: which filename ...\n");
		return (1);
	}
	/*Get current PATH env variable*/
	path = getenv("PATH");
	if (path == NULL)
	{
		printf("Error: PATH environment variable is not set\n");
		return (1);
	}
	/*tokenize PATH to get dirctories*/
	dir_path = strtok(path, delim);

	while (dir_path)
	{
		/*create a new path to the file by adding filename to dir*/
		file_path = malloc(strlen(dir_path) + strlen(av[1]) + 2);
		if (file_path == NULL)
		{
			printf("Memory not allocated\n");
			return (1);
		}
		/*use sprintf compose file path*/
		sprintf(file_path, "%s/%s", dir_path, av[1]);

		/*use stat to check if filepath composed exists*/
		struct stat st;
		
		if (stat(file_path, &st) == 0)
		{
			printf("%s\n", file_path);
			free(file_path);
			break;
		}
		free(file_path);

		/*next dir_path*/
		dir_path = strtok(NULL, delim);
	}
	/*print error msg if file not found*/
	if (dir_path == NULL)
	{
		printf("Error: File '%s' not found in PATH\n", av[1]);
		return (1);
	}
	return (0);
}
