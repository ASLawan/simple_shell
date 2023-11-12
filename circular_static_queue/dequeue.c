#include "queue.h"
/**
 * dequeue - removes items from a queue
 * @queue: array of items
 * @front: start of array
 * @rear: end of array
 * Return: nothing
 */

void dequeue(int queue[], int *front, int *rear)
{
	int remove = 1;

	while (remove)
	{
		if (*front == -1 && *rear == -1)
		{
			printf("Queue is empty - nothing to remove!\n");
		}
		else if (*front == *rear)
		{
			*front = *rear = -1;
		}
		else
		{
			printf("%d has been dequeued/removed!\n", queue[*front]);
			*front = (*front + 1) % SIZE;
		}
	
		printf("Remove another item(1-yes/0-no): ");
		scanf("%d", &remove);
	}
}
