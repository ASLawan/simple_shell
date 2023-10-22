#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	const char *prompt = "$ ";
	char *line = NULL;
	size_t len = 0;
	ssize_t chars_read; /*number of xters read, retuened by geline*/

	while (true)
	{
		write(STDOUT_FILENO, prompt, 2);

		chars_read = getline(&line, &len, stdin);

		if (chars_read == -1)
		{
			free(line);
			return (-1);
		}

		write(STDOUT_FILENO, line, chars_read);
	}
	
	free(line);
	return (0);
}
