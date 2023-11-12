#include "queue.h"
/**
 * enqueue - add item to queue
 * @queue: array of items
 * @front: start of array
 * @rear: end of array
 * Return: nothing
 */

void enqueue(int queue[], int *front, int *rear)
{
	int value, add = 1;

	while (add)
	{
		printf("Enter data to add to queue: \n");
		scanf("%d", &value);

		if (*front == -1 && *rear == -1)
		{
			*front = *rear = 0;
			queue[*rear] = value;
		}
		/*circular queue*/
		else if (((*rear + 1) % SIZE) == *front)
		{
			printf("Queue is full - Item cannot be added!\n");
		}
		else
		{
			*rear = (*rear + 1) % SIZE;
			queue[*rear] = value;
		}

		printf("Add another item(1-yes/0-no): ");
		scanf("%d", &add);
	}
}
