#include <stdio.h>

int main(int ac, char **av)
{
	int i = 0;

	printf("Number of arguments is: %d\n", ac);
	while (av[i])
	{
		printf("av[%d]: %s\n", i, av[i]);
		i++;
	}

	return (0);
}
