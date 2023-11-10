#include "stack.h"
/**
 * pop - removes item from stack
 * Return: nothing
 */
void pop(int stack[], int top)
{
	int item, pop = 1;

	while (pop)
	{
		if (top == -1)
		{
			printf("Underflow!--- nothing to remove\n");
			break;
		}
		else
		{
			item = stack[top];
			top--;
			printf("%d was removed from stack!\n", item);
		}
		printf("Remove another item (1-yes/0-no): ");
		scanf("%d", &pop);
	}
}
