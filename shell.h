#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdarg.h>

int main(void);
void biggy_print(const char *format, ...);
void d_prompt(void);
void exec_cmd(const char *cmd, ...);
void read_cmd(char *cmd, size_t size);

#endif
