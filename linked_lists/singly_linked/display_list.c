#include "singly.h"

void display_list(node *head)
{
	node *temp = head;

	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
