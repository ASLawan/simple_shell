#include "singly.h"

node *reverse_list(node *head)
{
	node *prev_node = NULL;
	node *current_node = NULL;
	node *next_node = NULL;

	current_node = next_node = head;

	while (next_node != NULL)
	{
		next_node = next_node->next;
		current_node->next = prev_node;
		prev_node = current_node;
		current_node = next_node;
	}
	head = prev_node;

	return (head);
}
	
