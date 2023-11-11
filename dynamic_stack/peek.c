#include "stack.h"
/**
 * peek_node - returns top most node
 * Return: nothing
 */

void peek_node(node *top)
{
	if (top == NULL)
	{
		printf("Stack is empty!\n");
	}
	else
	{
		printf("Top most node: %d", top->data);
	}
}
