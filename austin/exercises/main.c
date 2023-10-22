#include "main.h"

int main(void)
{
	char *value;
	char *check;
	int unset;

	_setenv("NAWAL", "Lawan is resilient", 1);
	
	value = _getenv("NAWAL");
	if (value != NULL)
	{
		printf("NAWAL: %s\n", value);
	}

	unset = _unsetenv("NAWAL");

	if (unset == 0)
	{
		printf("NAWAL was successfully unset.\n");
	}
	else
	{
		printf("Failed to unset NAWAL\n");
	}

	check = _getenv("NAWAL");

	if (check != NULL)
	{
		printf("NAWAL: %s\n", check);
	}
	else
	{
		printf("NAWAL is not set\n");
	}

	return (0);
}
