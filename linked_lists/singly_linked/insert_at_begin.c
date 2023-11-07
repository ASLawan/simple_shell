#include "singly.h"

node *add_at_begin(node *head)
{
	int value = 1, choice;
	node *new_node = NULL;
	
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
		new_node->next = head;
		head = new_node;
	
		printf("Insert another node(1-yes/0-no): ");
		scanf("%d", &choice);
	}
	
	return (head);
}
