#include "singly.h"

node *delete_at_pos(node *head)
{
	int pos, i = 1; 
	node *temp = NULL;
	node *next_node = NULL;

	printf("Enter position delete from: ");
	scanf("%d", &pos);

	temp = head;
	while (i < pos - 1)
	{
		temp = temp->next;
		i++;
	}

	next_node = temp->next;
	temp->next = next_node->next;

	free(temp);

	return (head);
}
