#include "queue.h"
/**
 * display_queue - prints out queue
 * @queue: array of items
 * @front: start of array
 * @rear: end of array
 * Return: nothing
 */

void display_queue(int queue[], int *front, int *rear)
{
	int i = *front;


	if (*front == -1 && *rear == -1)
	{
		printf("Queue is empty - nothing to print!\n");
	}
	else
	{
		printf("Here is your Queue: \n");
		while (i != *rear)
		{
			printf("%d ", queue[i]);
			i = (i + 1) % SIZE;
		}
		printf("%d\n", queue[*rear]);
	}
}
