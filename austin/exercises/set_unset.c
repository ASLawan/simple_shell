#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *value;
	char *check;


	setenv("MY_VARIABLE", "Hello, world!", 1);
	
	value = getenv("MY_VARIABLE");

	if (value != NULL)
	{
		printf("MY_VARIABLE: %s\n", value);
	}


	if (unsetenv("MY_VARIABLE") == 0)
	{
		printf("MY_VARIABLE was successfully unset.\n");
	}
	else
	{
		printf("Failed to unset MY_VARIABLE.\n");
	}

	check = getenv("MY_VARIABLE");
	if (check != NULL)
	{
		printf("MY_VARIABLE: %s\n", check);
	}
	else
	{
		printf("MY_VARIABLE is not set.\n");
	}

	return (0);
}
