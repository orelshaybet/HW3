#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Stack.h"
#include "Queue.h"
#include <string.h>
#include <stdlib.h>


void printstack(Stack* s)
{
	charNode* tmp;
	tmp = s->head;
	while (tmp != NULL)
	{
		printf("%c\n", tmp->data);
		tmp = tmp->next;
	}
}
void printline(Queue* line)
{
	intNode* tmp;
	tmp = line->head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

void main()
{
	//char c;

	////function 1.1
	//printf("function number 1.1: \n");
	//char* arr_sentence1 = "Remem#reb# thi#carp s#tice";
	//flipBetweenHashes(arr_sentence1);
	//printf("\n");
	//char* arr_sentence2 = "#meR#embe#siht r# practice";
	//flipBetweenHashes(arr_sentence2);

	////function 1.2
	//Stack s2;
	//initStack(&s2);
	//int size1_2 = 0;
	//printf("\n\nfunction number 1.2: \n");
	//printf("how many chars? ");
	//scanf("%d", &size1_2);
	//for (int i = 1; i <= size1_2; i++)
	//{
	//	printf("enter char num %d:  ", i);
	//	fseek(stdin, 0, SEEK_END);
	//	scanf("%c", &c);
	//	push(&s2, c);
	//}
	//int is_palindrome = isPalindrome(&s2);
	//if (is_palindrome == 1)
	//	printf("this is a palindrome!");
	//else
	//	printf("this is not a palindrome");
	//


	////function 1.3
	//Stack s3;
	//initStack(&s3);
	//int size1_3 = 0;
	//printf("\n\nfunction number 1.3: \n");
	//printf("how many chars? ");
	//scanf("%d", &size1_3);
	//for (int i = 1; i <= size1_3; i++)
	//{
	//	printf("enter char num %d:  ", i);
	//	fseek(stdin, 0, SEEK_END);
	//	scanf("%c", &c);
	//	push(&s3, c);
	//}
	//printf("the stack: \n");
	//printstack(&s3);
	//int num = 0;
	//printf("\nhow many chars do you want to move? ");
	//scanf("%d", &num);
	//rotateStack(&s3, num);
	//printstack(&s3);


//	//function 2.1
//	Queue line1;
//	int n1 = 0;
//	initQueue(&line1);
//	int size2_1 = 0;
//	printf("\n\nfunction number 2.1: \n");
//	printf("how many numbers? ");
//	scanf("%d", &size2_1);
//	for (int i = 1; i <= size2_1; i++)
//	{
//		printf("enter number num %d:  ", i);
//		scanf("%d", &n1);
//		enqueue(&line1, n1);
//	}
//	printf("the line: \n");
//	printline(&line1);
//	rotateQueue(&line1);
//	printf("\nthe line after rotate: \n");
//	printline(&line1);


	//function 2.2
	Queue line2;
	int n2 = 0;
	initQueue(&line2);
	int size2_2 = 0;
	printf("\n\nfunction number 2.2: \n");
	printf("how many numbers? ");
	scanf("%d", &size2_2);
	for (int i = 1; i <= size2_2; i++)
	{
		printf("enter number num %d:  ", i);
		scanf("%d", &n2);
		cutAndReplace(&line2);
	}
	printf("the line: \n");
	printline(&line2);
}