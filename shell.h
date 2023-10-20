#ifndef SHELL_H
#define SHELL_H

/********** GLOBAL VARIABLES ******/
extern char **environ;

/******** HEADER FILES *********/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>

/***** FUNCTION PROTOTYPES *******/

char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *str, char c);
char *_strdup(char *str);
int _strlen(char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
void _printstr(char *str);
void display_iprompt(void);
void display_non_iprompt(void);
/*char *get_usr_input(void);*/
char *get_usr_input(void);
char *get_input(void);

char **execute_input(char *input);
char **parse_input(char *input);

char *_getenv(char *input);
char *get_input_path(char *input);
char *_strtok(char *str, const char *delim);

int display_interactive(char **av);
void display_non_interactive(char **av);
void shell_exit(char **arr, char *input);
void _shell_exit(char **, char *input);

int _setenv(char *name, char *value, int overwrite);
int _putenv(char *name);
int _unsetenv(char *name);

void change_dir(char *dir);
int _atoi(char *s);
int input_check(char **arr, char *inpt, char *usr_input);



#endif
