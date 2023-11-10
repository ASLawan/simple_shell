#include "stack.h"
/**
 * display_stack - prints stack elements
 * @stack: stack to print
 * Return: nothing
 */

void display(int stack[], int top)
{
	int i, items = 0; 

	for (i = top; i >= 0; i--)
	{
		printf("%d\n", stack[i]);
		items++;
	}

	printf("Number of items stacked: %d\n", items);
}
