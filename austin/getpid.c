#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;

	pid = getpid();
	printf("My PID is: %u\n", pid);

	return (0);
}
