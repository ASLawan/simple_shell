#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

int simple_shell(char **av);
int interact(char **av);
int non_interact(char **av);
void _printstr(char *str);

int handle_args(char **av);
int interact_arg(char **av);
int non_interact_arg(char **av);
char **parse_input(char **av, char *input);

#endif
