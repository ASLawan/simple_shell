#ifndef SINGLY_H
#define SINGLY_H

/***** HEADER FILES ******/

#include <stdio.h>
#include <stdlib.h>

/***** STRUCTURE  *****/

typedef struct node 
{
	int data;
	struct node *next;
} node;

/**** FUNCTIONS  *****/

/* CREATE */
node *create_list();

/* INSERT */
node *add_at_begin(node *head);
node *add_at_pos(node *head);
node *add_at_end(node *head);

/*DELETE*/
node *delete_at_begin(node *head);
node *delete_at_pos(node *head);
node *delete_at_end(node *head);

/* REVERSE */
node *reverse_list(node *head);

int list_length(node *head);
void display_list(node *head);


#endif
