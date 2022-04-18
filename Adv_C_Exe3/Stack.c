#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>



// צומת ברשימה המקושר ת
typedef struct charNode {
	char data;
	struct charNode* next;
} charNode;
// מבנה מנהל של מחסני ת
typedef struct Stack {
	charNode* head;
} Stack;

/***************** My Functions *****************/
charNode* add_to_head(charNode* head, charNode* newnode);
void remove_item(charNode** head);
void printStack(charNode* head);
int size_of_stack(charNode* head);
charNode* the_lust_one(Stack* s);

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
	int size;
	Stack s;
	initStack(&s);
	while (&sentence != NULL)
	{
		if (&sentence != "#")
		{
			printf("%c", sentence);
		}
		if (&sentence == "#")
		{
			sentence++;
			while (&(sentence) != "#")		
			{
				push(&s, sentence);
				sentence++;
			}
			printStack(&s);
			destroyStack(&s);

		}
		sentence++;
	}
}

void printStack(Stack* s)
{
	Stack tmp;
	initStack(&tmp);
	while ( !isEmptyStack(s))
	{
		char val = pop(s);
		printf("%c", val);
		push(&tmp, val);
	}
	while (!isEmptyStack(&tmp))
	{
		push(s, pop(&tmp));
	}
}

int isPalindrome(Stack* s)
{
	int size = size_of_stack(s->head);
	if (size == 0) // if the stack is empty
		return 1;

	char* str = (char*)malloc(size * sizeof(char));// make array of char
	if (str == NULL)
	{
		printf("memory allocation problem \n");
		exit(0);
	}
	charNode* ptr = s->head;
	for (int i = 0; i < size; i++) // copy the stack to array
	{
		str[i] = ptr->data;
		ptr = ptr->next;
	}	
	for (int i = 0; i < size / 2; i++)
	{
		if (str[i] != str[size - i - 1])
		{
			return 0;
		}
	}
	return 1;
}
	

int size_of_stack(charNode* head)
{
	int size = 0;
	charNode* tmp;
	tmp = head;
	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	free(tmp);
	return size;
}

void rotateStack(Stack* s, int n)
{
	for (int i = 0; i < n; i++)
	{
		charNode* new_head = the_last_one(s);
		new_head->next = s->head;  // move the older head to be secound
		s->head = new_head;		// move the new_head to be the first
		while (s->head->next != NULL)// free the last of the stack
		{

		}
	}
}

charNode* the_last_one(Stack* s)
{
	charNode* tmp;
	tmp = s->head;
	while (tmp != NULL)
	{
		tmp = tmp->next;
	}
	return tmp;
}