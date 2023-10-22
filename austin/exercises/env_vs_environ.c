#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
	int i = 0;

	printf("The number of arguments is: %d\n", ac);
	while (av[i])
	{
		printf("av[%d]: %s\n", i, av[i]);
		i++;
	}

	printf("\nThe address of 'env' is: %p\n", env);
	printf("The address of 'environ' is: %p\n", environ);

	return (0);
}
