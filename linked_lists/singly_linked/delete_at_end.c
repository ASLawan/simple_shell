#include "singly.h"

node *delete_at_end(node *head)
{
	node *temp = NULL;
	node *prev_node = NULL;

	temp = head;
	while (temp->next != NULL)
	{
		prev_node = temp;
		temp = temp->next;
	}

	if (temp == head)
	{
		head = NULL;
		return (head);
	}
	else
	{
		prev_node->next = NULL;
	}
	
	free(temp);

	return (head);
}


