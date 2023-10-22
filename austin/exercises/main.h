#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
int _putenv(const char *name);
char *_getenv(const char *name);


#endif
