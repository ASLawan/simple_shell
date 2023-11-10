#include "stack.h"
/**
 * peek - returns the topmost item in the stack
 * Return: nothing
 */

void peek(int stack[], int top)
{
	if (top == -1)
	{
		printf("Stack is empty!\n");;
	}
	else
	{
		printf("Topmost item: %d\n", stack[top]);
	}
}
