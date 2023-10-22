#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/*************** HEADER FILES ****************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**************** FUNCTION PROTOTYPES ***********/

void exec_usr_input(char **envv, char **av);
char **parse_usr_input(int count, char *line_cpy);
void sh_print(char *str);
void display_prompt(void);
char *_getenv(char **envv, const char *input);
char *get_usr_input_path(char **envv, char *input);


#endif
