#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>




/***************** My Functions *****************/
charNode* add_to_head(charNode* head, charNode* newnode);
void remove_item(charNode** head);
void printStack(charNode* head);
int size_of_stack(charNode* head);

/***************** Stack ADT Implementation *****************/

void initStack(Stack* s)
{
	s->head = NULL;
}

void destroyStack(Stack* s)
{
		free(s->head);
}

void push(Stack* s, char data)
{
	charNode* newnode = (charNode*)malloc(sizeof(charNode));
	if (newnode == NULL)
	{
		printf("push: memory allocation problem \n");
			return;
	}
	newnode->data = data;
	s->head = add_to_head(s->head, newnode);
}

charNode *add_to_head(charNode* head, charNode* newnode)
{
	newnode->next = head;
	head = newnode;
	return head;
}


char pop(Stack* s)
{
	char res;
	if (s->head == NULL)
	{
		printf("\nSTACK IS EMPTY");
		return "0";
	}
	res = s->head->data;				
	remove_item(&(s->head));
	return res;
}

void remove_item(charNode **head)
{
	if (*head == NULL) //if stack is empty
		return;
	charNode* tmp = *head;
	*head = (*head)->next;
	free(tmp);
}


int isEmptyStack(const Stack* s)
{
	if (s->head == NULL)
		return 1;
	else
		return 0;
}

/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{
	Stack s;
	initStack(&s);
	while (*sentence != NULL)       
	{
		if (*sentence != '#')
		{
			printf("%c", *sentence);
		}
		if (*sentence == '#')
		{													
			sentence++;
			while ((*sentence) != '#')		
			{
				push(&s, *sentence);
				sentence++;
			}
			while (!isEmptyStack(&s))
			{
				printf("%c", pop(&s));
			}
			destroyStack(&s);

		}
		sentence++;
	}
}

int isPalindrome(Stack* s)
{
	int size = size_of_stack(s);
	if (size == 0) 
	{
		return 1;
	}
	Stack tmp;
	initStack(&tmp);
	char* arr = (char*)malloc(size * sizeof(char));
	char val;
	for (int i = 0; i < size; i++)
	{
		val = pop(s);
		arr[i] = val;
		push(&tmp, val);
	}
	while (!isEmptyStack(&tmp))
	{
		push(s, pop(&tmp));
	}
	destroyStack(&tmp);
	for (int i = 0; i < (size / 2); i++)
	{
		if (arr[i] != arr[size - i - 1])
		{
			return 0;
		}
	}
	return 1;
}
	

int size_of_stack(Stack* s)
{
	Stack tmp;
	initStack(&tmp);
	int counter = 0;
	while ( !isEmptyStack(s))
	{
		char val = pop(s);
		push(&tmp, val);
		counter++;
	}
	while (!isEmptyStack(&tmp))
	{
		push(s, pop(&tmp));
	}
	return counter;
}


void rotateStack(Stack* s, int n)
{
	int size = size_of_stack(s);
	if (size <= 1) // if stack is empty or one object
	{
		return;
	}
	Stack help_stack_1;
	Stack help_stack_2;
	initStack(&help_stack_1);
	initStack(&help_stack_2);
	char val;
	for (int i = 0; i < size - n; i++) // Insert into help stack 1
	{
		val = pop(s);
		push(&help_stack_1, val);
		
	}
	for (int i = 0; i < n; i++)   // Insert into help stack 2
	{
		val = pop(s);
		push(&help_stack_2, val);

	}
	for (int i = 0; i < size - n; i++) // Insert from help stack 1 into original stack 
	{
		val = pop(&help_stack_1);
		push(s, val);
	}
	for (int i = 0; i < n; i++) // Insert from help stack 2 into original stack
	{
		val = pop(&help_stack_2);
		push(s, val);
	}
	destroyStack(&help_stack_1);
	destroyStack(&help_stack_2);
}
