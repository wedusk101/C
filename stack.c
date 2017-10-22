//queue.c -- Stack implementation
#include "stack.h"

#define TRUE 1
#define FALSE 0

struct node
{
	int info;
	struct node *next;	
};

int isEmpty(NODEPTR list)
{
	if(list == NULL)
		return TRUE;
	else 
		return FALSE;
}

void push(NODEPTR *list, int x)
{
	NODEPTR newNode;
	newNode = malloc(sizeof(struct node));
	if(newNode == NULL)
	{
		printf("Stack overflow! Operation aborted.\n");
		return;
	}
	newNode->info = x;
	if(*list == NULL)
	{
		newNode->next = NULL;
		*list = newNode;
		printf("Element pushed successfully.\n\n");
		return;
	}
	newNode->next = *list;
	*list = newNode;
	printf("Element pushed successfully.\n\n");
}

int pop(NODEPTR* list)
{
	NODEPTR delNode;
	int val = 0;
	if(*list == NULL)
		return INT_MIN;
	val = (*list)->info;
	delNode = *list;
	*list = (*list)->next;
	free(delNode);
	return val;	
}

int peek(NODEPTR list)
{
	int val = 0;
	if(list == NULL)
		return INT_MIN;
	val = list->info;
	return val;
}