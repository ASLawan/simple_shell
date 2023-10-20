#include "shell.h"
/**
 * main - entry point
 * @ac: arg count
 * @av: arg array
 * Return: 0
 */
int main(int ac, char **av)
{
	(void)ac;
	simple_shell(av);
	handle_args(av);
	handle_path(av);
	return (0);
}
