#include "queue.h"
/**
 * main - program entry point
 * Return: 0 on success and 1 otherwise
 */

int queue[SIZE];
int front = -1;
int rear = -1;

int main(void)
{
	int create = 1, remove = 1, peek = 1;

	
	printf("Enter 1 or 0 to create a queue or not: ");
	scanf("%d", &create);

	if (create == 1)
	{
		enqueue(queue, &front, &rear);
		display_queue(queue, &front, &rear);
	}
	else
	{
		printf("No queue has been created\n");
	}
	printf("Enter 1 or 0 to remove items or not: \n");
	scanf("%d", &remove);

	if (remove == 1)
	{
		dequeue(queue, &front, &rear);
		display_queue(queue, &front, &rear);
	}
	else
	{
		printf("No item is removed from queue!\n");

	}
	printf("Enter 1 or 0 to see the item infront of the queue or not: \n");
	scanf("%d", &peek);

	if (peek == 1)
	{
		peek_queue(queue, &front, &rear);
	}
	else
	{
		printf("No peeking\n");
		return (1);
	}

	return (0);
}
