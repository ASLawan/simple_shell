#include "queue.h"
/**
 * display_queue - prints out all queue elements
 * @queue: array of items
 * @front: start of queue
 * @rear: end of queue
 * Return: nothing
 */

void display_queue(int queue[], int *front, int *rear)
{
	int i = *front;

	printf("Front: %d\n", *front);
	printf("Rear: %d\n", *rear);
	if (*front == -1 && *rear == -1)
	{
		printf("Queue is empty - nothing to print!\n");
	}
	else
	{
		printf("Here is your queue: \n");
		while (i < (*rear + 1))
		{
			printf("%d ", queue[i]);
			i++;
		}
	}
	printf("\n");
}
