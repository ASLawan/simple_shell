#include "queue.h"
/**
 * dequeue - removes data units from a queue
 * @queue: array of items
 * @front: start of rear
 * @rear: end of queue
 * Return: nothing
 */

void dequeue(int queue[], int *front, int *rear)
{
	int dq = 1;

	while (dq)
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
			printf("%d has been Dequeued/Removed\n", queue[*front]);
			*front++;
		}

		printf("Dequeue another unit(1-yes/0-no): ");
		scanf("%d", &dq);
	}
}
