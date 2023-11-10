#include "stack.h"
/**
 * push - adds item to stack
 * @x: item to add to stack
 * Return: int 
 */

int push(int stack[])
{
	int value;
	int top = -1, push = 1;
	
	while (push == 1)
	{
		printf("Enter data to add to stack: \n");
		scanf("%d", &value);

		if (top == SIZE - 1)
		{
			printf("Stack is full!");
			break;
		}
		else
		{
			top++;
			stack[top] = value;
		}
		printf("Push another item (1-yes/0-no): ");
		scanf("%d", &push);
	}

	return (top);
}
