#include "singly.h"

node *add_at_end(node *head)
{
	int value, choice = 1;
	node *new_node = NULL;
	node *temp = NULL;

	while (choice)
	{
		new_node = (node *)malloc(sizeof(node));
		if (new_node == NULL)
		{
			free(new_node);
			return (NULL);
		}
		printf("Enter data to insert: ");
		scanf("%d", &value);
		
		new_node->data = value;
		new_node->next = NULL;
		temp = head;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;

		printf("Insert another node(1-yes/0-no): ");
		scanf("%d", &choice);
	}
	return (head);
}
