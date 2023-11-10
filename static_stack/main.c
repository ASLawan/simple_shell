#include "stack.h"
/**
 * main - program entry point
 * Return: 0 success always
 */

int stack[SIZE];
int top = -1;

int main(void)
{
	int ph, pp, pk;

	printf("Would you like to create a stack(1-yes/0-no): \n");
	scanf("%d", &ph);
	
	if (ph == 1)
		top = push(stack);
	else
		printf("That's okay!");

	printf("\nHere is your stack: \n");
	display(stack, top);

	printf("Enter 1 to remove last stack item: \n");
	scanf("%d", &pp);

	if (pp == 1)
		pop(stack, top);
	else
		printf("That's okay!");
	printf("\nHere is the stack after pop: \n");
	display(stack, top);

	printf("Enter 1 to see the last stacked item: \n");
	scanf("%d", &pk);

	if (pk == 1)
		peek(stack, top);
	else
		printf("Here is the stack");
	display(stack, top);

	
	return (0);
}
