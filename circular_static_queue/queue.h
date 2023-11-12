#ifndef QUEUE_H
#define QUEUE_H

/*** MACROS ***/
#define SIZE 5

/*** HEADER FILES ***/
#include <stdio.h>
#include <stdlib.h>

/*** FUNCTION PROTOTYPES ***/
void enqueue(int queue[], int *front, int *rear);
void dequeue(int queue[], int *front, int *rear);
void display_queue(int queue[], int *front, int *rear);
void peek_queue(int queue[], int *front, int *rear);


#endif
