#ifndef STACK_H
#define STACK_H

/*** GLOBAL VARIABLES ***/

#define SIZE 5

/*** HEADER FILES ****/

#include <stdlib.h>
#include <stdio.h>

/*** FUNCTION PROTOTYPES ***/

int push(int stack[]);
void pop(int stack[], int top);
void peek(int stack[], int top);
void display(int stack[], int top);



#endif
