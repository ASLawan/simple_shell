#include "stack.h"
/**
 * pop_node - removes last stacked node
 * @top: pointer to head of list
 * Return: nothing
 */

void pop_node(node *top)
{
	node *temp = NULL;
	
	temp = top;

	if (top == NULL)
		printf("Underflow - stack is empty!\n");
	
	printf("%d has been removed!\n", temp->data);
	top = top->next;
	free(temp);
	
}
