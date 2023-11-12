#include "queue.h"
/**
 * enqueue - adds data to queue
 * @queue: array of data units
 * @front: start of queue
 * @rear: rear of queue
 */

void enqueue(int queue[], int *front, int *rear)
{
	int value, eq = 1;

	while(eq)
	{
		printf("Enter data to add to queue: \n");
		scanf("%d", &value);

		if (*rear == SIZE - 1)
		{
			printf("Overflow - cannot add another item\n");
		}
		else if (*front == -1 && *rear == -1)
		{
			*front = *rear = 0;
			queue[*rear] = value;
		}
		else
		{
			printf("Rear is: %d\n", *rear);
			*rear += 1;
			queue[*rear] = value;
		}

		printf("Add another data unit: \n");
		scanf("%d", &eq);
	}
	printf("Enqueued items: %d\n", *rear);
}
