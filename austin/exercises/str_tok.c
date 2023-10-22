#include "main.h"

char *_strtok(char *str, const char *delim)
{
	char *start;
	static char *p = 0;

	if(str)
	{
		p = str;
	}
	else if (!p)
	{
		return (NULL);
	}
	start = p;

	while (*p && !strchr(delim, *p))
	{
		p++;
	}
	if (*p)
	{
		*p = 0;
		p++;
	}
	else
	{
		p = 0;
	}

	return (start);
}

int main(void)
{
	char str[] = "Hello:Lawan:how:are:you:doing";
	char *tkn;

	tkn = _strtok(str, ":");

	while (tkn != NULL)
	{
		printf("%s\n", tkn);
		tkn = _strtok(NULL, ":");
	}

	return (0);
}
