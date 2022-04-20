#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Stack.h"
#include "Queue.h"
#include <string.h>
#include <stdlib.h>


void print(Stack* s)
{
	charNode* tmp;
	tmp = s->head;
	while (tmp != NULL)
	{
		printf("%c\n", tmp->data);
		tmp = tmp->next;
	}
}

void main()
{
	char c;

	//function 1
	printf("function number 1: \n");
	char* arr_sentence1 = "Remem#reb# thi#carp s#tice";
	flipBetweenHashes(arr_sentence1);
	printf("\n");
	char* arr_sentence2 = "#meR#embe#siht r# practice";
	flipBetweenHashes(arr_sentence2);

	//function 2
	Stack s2;
	initStack(&s2);
	int size2 = 0;
	printf("\n\nfunction number 2: \n");
	printf("how many chars? ");
	scanf("%d", &size2);
	for (int i = 1; i <= size2; i++)
	{
		printf("enter char num %d:  ", i);
		fseek(stdin, 0, SEEK_END);
		scanf("%c", &c);
		push(&s2, c);
	}
	int is_palindrome = isPalindrome(&s2);
	if (is_palindrome == 1)
		printf("this is a palindrome!");
	else
		printf("this is not a palindrome");
	


	//function 3
	Stack s3;
	initStack(&s3);
	int size3 = 0;
	printf("\n\nfunction number 3: \n");
	printf("how many chars? ");
	scanf("%d", &size3);
	for (int i = 1; i <= size3; i++)
	{
		printf("enter char num %d:  ", i);
		fseek(stdin, 0, SEEK_END);
		scanf("%c", &c);
		push(&s3, c);
	}
	printf("the stack: \n");
	print(&s3);
	int num = 0;
	printf("\nhow many chars do you want to move? ");
	scanf("%d", &num);
	rotateStack(&s3, num);
	print(&s3);
}

