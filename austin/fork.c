#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(void)
{
	pid_t my_pid;
	pid_t pid;

	printf("Before fork sys call: \n");
	
	pid = fork();
	if (pid == -1)
	{
		perror("Error: \n");
		return (1);
	}

	printf("After fork sys call: \n");
	my_pid = getpid();
	printf("My pid is %u\n", my_pid);

	return (0);
}
