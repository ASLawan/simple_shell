#include "queue.h"
/**
 * peek_queue - return the first item on the queue
 * @queue: array of items
 * @front: start of array
 * @rear: end of array
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
		printf("First item on the queue: \n");
		printf("%d\n", queue[*front]);
	}
}
