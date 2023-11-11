#include "stack.h"
/**
 * push_node - creates a new node
 * Return: pointer to linked list
 */

node *push_node(void)
{
	node *top = NULL;
	node *new_node = NULL;
	int value, ph = 1;
	
	while (ph)
	{
		printf("Enter data to stack: \n");
		scanf("%d", &value);
	
		new_node = (node *)malloc(sizeof(node));
		if (new_node == NULL)
		{
			free(new_node);
			return (NULL);
		}

		new_node->data = value;
		new_node->next = top;
		top = new_node;
	
		printf("Add another node (1-yes/0-no): ");
		scanf("%d", &ph);
	}

	return (top);
}
