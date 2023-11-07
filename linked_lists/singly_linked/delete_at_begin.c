#include "singly.h"

node *delete_at_begin(node *head)
{
	node *temp = NULL;

	if (head == NULL)
	{
		return (head);
	}
	else
	{
		temp = head;
		head = head->next;
	}
	free(temp);

	return (head);
}
