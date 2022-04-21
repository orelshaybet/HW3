#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>




// my functions //
int size_of_queue(Queue* q);
int sum_of_queue(Queue* q);

/***************** Queue ADT Implementation *****************/

void initQueue(Queue* q)// Boot Manager Structure
{
	q->head = NULL;
	q->tail = NULL;
}

void destroyQueue(Queue* q) // free manager structure
{
	free(q->head);
	free(q->tail);
}

void enqueue(Queue* q, unsigned int data)//add element to queue
{
	intNode* p = (intNode*)malloc(sizeof(intNode));//Allocating memory to an auxiliary queue
	if(p == NULL)
	{
		printf("memory allocation problem \n");
		return;
	}
	p->data = data;//// set element data
	p->next = NULL;
	if (isEmptyQueue(q) != 1)// not Empty?
	{
		q->tail->next = p;//Add after last
	}
	else
	{
		q->head = p;//Otherwise – it becomes first
	}
	q->tail = p; //// update queue tail
}

unsigned int dequeue(Queue* q)// this function return data and delete the head
{
	unsigned int temp = q->head->data;
	intNode* p = q->head;
	q->head = q->head->next;
	if (q->head == NULL)//if queue gets empty
	{
		q->tail = NULL;	//NULL;//both front and rear NULL				
	}
	free(p);
	return temp;

}

int isEmptyQueue(const Queue* q) //A function that checks if the queue is empty
{
	if (q->head == NULL && q->tail == NULL)
		return 1;
	else
		return 0;
}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	int size = size_of_queue(q);//The explanation in the function
	for (int i = 0; i < (size - 1); i++) 
	{
		enqueue(q, dequeue(q));	//Move the first to the last place until the last becomes first			 
	}
}

void cutAndReplace(Queue* q)
{
	Queue helper1;
	Queue helper2;
	initQueue(&helper1);//Auxiliary queue boot
	initQueue(&helper2);//Auxiliary queue boot

	int size = size_of_queue(q);//The explanation in the function
	int sum = sum_of_queue(q);//The explanation in the function
	if (size % 2 == 1) // if not even
	{
		enqueue(q, (sum / size));//Insert the average at the end of the queue 
		size++;					//and add 1 to the size
	}
	for (int i = 0; i < (size/2); i++)
	{
		enqueue(&helper2, dequeue(q));//Transfer half of the queue to an auxiliary queue
	}
	for (int i = 0; i < ((size / 2)-1); i++)
	{
		rotateQueue(q); 
		enqueue(&helper1, dequeue(q));// Transferring the last queue to an auxiliary queue
	}
	enqueue(&helper1, dequeue(q));//Transferring the last remaining in line to an auxiliary queue
	for (int i = 0; i < (size / 2); i++)
	{
		enqueue(q, dequeue(&helper1));//Return from auxiliary queue after inversion to the original queue
	}
	for (int i = 0; i < (size / 2); i++)
	{
		enqueue(q, dequeue(&helper2));//Returning the first half to the end of the original queue
	}
}

void sortKidsFirst(Queue* q)
{
	int size = size_of_queue(q);
	int* arr = (int*)malloc(size * sizeof(int));//Boot a dynamic array
	if (arr == NULL)
	{
		printf("memory allocation problem \n");
		exit(0);
	}
	for (int i = 0; i < size; i++)
	{
		arr[i] = dequeue(q);//Copy the queue to the array + Removing a number from the queue
	}
	for (int i = 0; i < size -1; ++i) // Sort the array from the smallest to the largest 
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
		enqueue(q, arr[i]); //Entering the sorted array numbers into the original queue
	}
	free(arr);// Release of the array
}

int size_of_queue(Queue* q)//An auxiliary function that checks the size of the queue
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

int sum_of_queue(Queue* q)//Auxiliary function that checks the sum of the queue
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
