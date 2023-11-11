#include "stack.h"
/**
 * display_node - prints stack
 * @top: pointer to first node
 * Return: list
 */

void display_node(node *top)
{
	int count = 0;
	node *temp = NULL;

	if (top == NULL)
	{
		printf("Stack is empty!\n");
	}
	else
	{
		temp = top;
		while (temp != NULL)
		{
			printf("%d\n", temp->data);
			temp = temp->next;
			count++;
		}
	}

	printf("Number of items in stack: %d\n", count);
}
