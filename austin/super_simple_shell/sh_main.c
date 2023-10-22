#include "sh_main.h"

/**
 * main - program entry point
 * @ac: argument count
 * @av: argument array
 * Return: 0, always success
 */
int main(int ac, char **av, char **env)
{
	int tkns = 0;
	char *line = NULL, *line_cpy, *tkn;
	char *delim = " \n";
	size_t len = 0;
	ssize_t chars_rd;
	(void)ac;

	/*initialize loop*/
	while (true)
	{
		/*display prompt*/
		display_prompt();

		/*read user command*/
		chars_rd = getline(&line, &len, stdin);
		if (chars_rd == -1)
		{
			perror("Exiting shell....");
			free(line);
			return (-1);
		}
		tkn = strtok(line, delim);
		while (tkn)
		{
			tkns += 1;
			tkn = strtok(NULL, delim);
		}
		tkns += 1;

		line_cpy = malloc(sizeof(char *) * tkns);
		if (line_cpy == NULL)
		{
			sh_print("Memory not allocated");
			free(line_cpy);
			return (-1);
		}
		line_cpy = strdup(line);

		/*pasrse user input*/
		av = parse_usr_input(tkns, line_cpy);

		/*execute the user commands*/
		exec_usr_input(env, av);

		/*display results*/

	}

	return (0);
}
