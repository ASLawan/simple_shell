#ifndef STACK_H
#define STACK_H

/*** HEADER FILES  ***/

#include <stdio.h>
#include <stdlib.h>

/*** STRUCTURE  ***/

typedef struct node 
{
	int data;
	struct node *next;
} node;

/*** FUNCTION PROTOTYPES  ***/

node *push_node(void);
void pop_node(node *top);
void peek_node(node *top);
void display_node(node *top);


#endif
