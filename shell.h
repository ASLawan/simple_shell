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





int shell_one(char **av);
char **parse_input(char **av, char *usr_input);


/***** FUNCTION PROTOTYPES *******/

char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *str, char c);
char *_strdup(char *str);
int _strlen(char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
void _printstr(char *str);
void betty_check(void);



#endif
