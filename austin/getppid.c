#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t ppid;

	ppid = getppid();
	printf("My PPID is: %u\n", ppid);

	return (0);
}
