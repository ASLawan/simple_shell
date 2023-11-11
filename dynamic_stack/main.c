#include "stack.h"
/**
 * main - program entry point
 * Return: 0 success always
 */

int main(void)
{
	node *top;
	int ph, pp = 1, pk;

	printf("Enter 1 or 0 to create a stack or not:  ");
	scanf("%d", &ph);

	if (ph == 1)
	{
		top = push_node();
		display_node(top);
	}
	else
		printf("No stack will be created!\n");

	printf("Enter 1 or 0 to remove node or not: ");
	scanf("%d", &pp);

	while (pp == 1)
	{
		pop_node(top);
		/*display_node(top);*/
		printf("Remove another node(1-yes/0-no): \n");
		scanf("%d", &pp);
	}
	
	display_node(top);
	printf("Enter 1 or 0 to get last node: \n");
	scanf("%d", &pk);

	if (pk == 1)
		peek_node(top);
	else
		printf("The last node will not be returned!\n");

	return (0);
}
