#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	int i;
	pid_t pid;

	for (i = 0; i < 5; i++)
	{
		pid = fork();
		if (pid < 0)
		{
			perror("Fork failed");
			return (1);
		}
		else if (pid == 0)
		{
			char *av[] = {"/bin/ls", "-l", "/tmp/", NULL};

			execve(av[0], av, NULL);
			exit(0);
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}
