#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>




/***************** My Functions *****************/
charNode* add_to_head(charNode* head, charNode* newnode);
void remove_item(charNode** head);

int size_of_stack(charNode* head);

/***************** Stack ADT Implementation *****************/

void initStack(Stack* s)
{
	s->head = NULL; // Boot stack
}

void destroyStack(Stack* s)
{
		free(s->head); //Release the head
}

void push(Stack* s, char data)
{
	charNode* newnode = (charNode*)malloc(sizeof(charNode)); //boot new node
	if (newnode == NULL)
	{
		printf("push: memory allocation problem \n");
			return;
	}
	newnode->data = data; //copy the char to the new node
	s->head = add_to_head(s->head, newnode); // Put the new node at the top of the stack and
											 //move the old head to be next in the stack
}

char pop(Stack* s)
{
	if (s->head == NULL)
	{
		printf("\nSTACK IS EMPTY");
		return "0";
	}
	char res = s->head->data;// A local variable that holds the first letter in the stack
	remove_item(&(s->head)); // The explanation is attached in the function
	return res;
}

int isEmptyStack(const Stack* s) // A function that checks if the stack is empty
{
	if (s->head == NULL)
		return 1;
	else
		return 0;
}



charNode* add_to_head(charNode* head, charNode* newnode) // my function
{
	newnode->next = head;
	head = newnode;
	return head;
}

void remove_item(charNode** head) // my function
{
	if (*head == NULL) //if stack is empty -> return
		return;
	charNode* tmp = *head;
	*head = (*head)->next; // Transfer the second letter to the top of the stack
	free(tmp); //Deleting the old stack head
}

/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{
	Stack s;
	initStack(&s);
	while (*sentence != NULL)       //As long as not the end of the stack
	{
		if (*sentence != '#') // Print letters not inside # __ #
		{
			printf("%c", *sentence);
		}
		if (*sentence == '#') // Print letters inside # _ #
		{													
			sentence++; // So as not to print '#'
			while ((*sentence) != '#')		//Insert all the letters in '# __ #' into the stack
			{
				push(&s, *sentence);
				sentence++; 
			}
			while (!isEmptyStack(&s))// Remove from the cartridge and print the letters until the cartridge is empty
			{
				printf("%c", pop(&s));
			}
			destroyStack(&s); //Release the stack head

		}
		sentence++; // Move on to the next letter
	}
}

int isPalindrome(Stack* s) // A function that checks whether the stack is a palindrome without losing the stack
{
	int size = size_of_stack(s); // The explanation in the function
	if (size == 0 || size == 1) 
	{
		return 1;
	}
	Stack tmp;
	initStack(&tmp); // Boot auxiliary stack
	char* arr = (char*)malloc(size * sizeof(char));
	char val;
	for (int i = 0; i < size; i++)//Transfer the stack to an array and
								  //auxiliary stack (In order not to lose the letters and their order)
	{
		val = pop(s);
		arr[i] = val; 
		push(&tmp, val);
	}
	while (!isEmptyStack(&tmp)) // Return the letters from the auxiliary stack to the original stack
	{
		push(s, pop(&tmp));
	}
	destroyStack(&tmp); // Releasing the Auxiliary Cartridge
	for (int i = 0; i < (size / 2); i++) // Examination of the array if it is a palindrome
	{
		if (arr[i] != arr[size - i - 1])
		{
			return 0;
		}
	}
	return 1; // If the loop is over it means the stack is a palindrome
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
	initStack(&help_stack_1); // Boot Auxiliary help stack 1
	initStack(&help_stack_2); // Boot Auxiliary help stack 2
	char val;
	for (int i = 0; i < size - n; i++) // Insert the first letters of an auxiliary stack 1
	{
		val = pop(s);
		push(&help_stack_1, val);
		
	}
	for (int i = 0; i < n; i++)   // Insert the letters we want to transfer into an auxiliary stack 2
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



int size_of_stack(Stack* s) // my function   //Transfer the stack to the auxiliary stack +
						                     //count the letters and empty the auxiliary stack
{
	Stack tmp;
	initStack(&tmp);
	int counter = 0;
	while (!isEmptyStack(s))
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

