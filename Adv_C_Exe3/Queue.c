#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>




// my functions //
int size_of_queue(Queue* q);
int sum_of_queue(Queue* q);

/***************** Queue ADT Implementation *****************/

void initQueue(Queue* q)
{
	q->head = NULL;
	q->tail = NULL;
}

void destroyQueue(Queue* q)
{
	free(q->head);
	free(q->tail);
}

void enqueue(Queue* q, unsigned int data)
{
	intNode* p = (intNode*)malloc(sizeof(intNode));
	if (p == NULL)
	{
		printf("memory allocation problem \n");
		return;
	}
	p->data = data;
	p->next = NULL;
	if (isEmptyQueue(q) != 1)
	{
		q->tail->next = p;
	}
	else
	{
		q->head = p;
	}
	q->tail = p;
}

unsigned int dequeue(Queue* q)
{
	unsigned int temp = q->head->data;
	intNode* p = q->head;
	q->head = q->head->next;
	if (q->head == NULL)
	{
		q->tail = NULL;					
	}
	free(p);
	return temp;

}

int isEmptyQueue(const Queue* q)
{
	if (q->head == NULL && q->tail == NULL)
		return 1;
	else
		return 0;
}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	int size = size_of_queue(q);
	for (int i = 0; i < (size - 1); i++) 
	{
		enqueue(q, dequeue(q));				 
	}
}

void cutAndReplace(Queue* q)
{
	Queue helper1;
	Queue helper2;

	int size = size_of_queue(q);
	int sum = sum_of_queue(q);
	if (size % 2 == 1)
	{
		enqueue(q, (sum / size));
	}
	for (int i = 0; i < (size/2); i++)
	{
		enqueue(&helper2, dequeue(q));
	}
	for (int i = 0; i < (size / 2); i++)
	{
		rotateQueue(&q);
		enqueue(&helper1, dequeue(q));
	}
	for (int i = 0; i < (size / 2); i++)
	{
		enqueue(q, dequeue(&helper1));
	}
	for (int i = 0; i < (size / 2); i++)
	{
		enqueue(q, dequeue(&helper2));
	}
	destroyQueue(&helper1);
	destroyQueue(&helper2);
}

void sortKidsFirst(Queue* q)
{
	int size = size_of_queue(q);
	int* arr = (int*)malloc(size * sizeof(int));
	if (arr == NULL)
	{
		printf("memory allocation problem \n");
		exit(0);
	}
	for (int i = 0; i < size; i++)
	{
		arr[i] = dequeue(q);
	}
	for (int i = 0; i < size -1; ++i) // arr[i] will be the smallest of i..N-1 
	{
		for (int j = i + 1; j < size; ++j)
		{
			if (arr[i] > arr[j])
			{
				int t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		enqueue(q, arr[i]);
	}
	free(arr);
}

int size_of_queue(Queue* q)
{
	Queue tmp;
	initQueue(&tmp);
	int counter = 0;
	while (!isEmptyQueue(q))
	{
		unsigned int val = dequeue(q);
		enqueue(&tmp, val);
		counter++;
	}
	while (!isEmptyQueue(&tmp))
	{
		enqueue(q, dequeue(&tmp));
	}
	destroyQueue(&tmp);
	return counter;
}

int sum_of_queue(Queue* q)
{
	Queue tmp;
	initQueue(&tmp);
	int sum = 0;
	while (!isEmptyQueue(q))
	{
		unsigned int val = dequeue(q);
		enqueue(&tmp, val);
		sum += val;
	}
	while (!isEmptyQueue(&tmp))
	{
		enqueue(q, dequeue(&tmp));
	}
	destroyQueue(&tmp);
	return sum;
}
