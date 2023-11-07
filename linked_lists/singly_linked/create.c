#include "singly.h"

node *create_list()
{
	node *head = NULL;
	node *new_node = NULL;
	node *temp = NULL;
	int choice = 1, value;

	while (choice)
	{
		new_node = (node *)malloc(sizeof(node));
		if (new_node == NULL)
		{
			free(new_node);
			return (NULL);
		}
		printf("Enter data to add to list: ");
		scanf("%d", &value);

		new_node->data = value;
		new_node->next = NULL;
		if (head == NULL)
		{
			head = temp = new_node;
		}
		else
		{
			temp->next = new_node;
			temp = new_node;
		}
		printf("Do you want to continue(1-yes/0-no): ");
		scanf("%d", &choice);
	}

	
	return (head);
}
