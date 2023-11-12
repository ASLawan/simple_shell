#include "queue.h"
/**
 * peek_queue - returns first item on the list
 * @queue: array of items
 * @front: index - start of array
 * @rear: index - end of array
 * Return: nothing
 */

void peek_queue(int queue[], int *front, int *rear)
{
	if (*front == -1 && *rear == -1)
	{
		printf("Queue is empty!\n");
	}
	else
	{
		printf("First item on the queue: %d\n", queue[*front]);
	}
}
