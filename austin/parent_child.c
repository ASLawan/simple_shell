#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	pid_t my_pid;
	pid_t child_pid;

	/*create child process*/
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Process not created");
		return (1);
	}

	my_pid = getpid();
	printf("My PID is %u\n", my_pid);
	
	if (child_pid == 0)
	{
		printf("(%u) Noooooooooo!\n", my_pid);
	}
	else
	{
		printf("(%u) %u, I am the parent process\n", my_pid, child_pid);
	}

	return (0);
}
