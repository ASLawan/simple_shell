#include "singly.h"

int list_length(node *head)
{
	int count = 0;
	node *temp;

	temp = head;
	while (temp != NULL)
	{
		count += 1;
		temp = temp->next;
	}

	return (count);
}
