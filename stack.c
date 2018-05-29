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

int push(NODEPTR *list, int x)
{
	NODEPTR newNode;
	newNode = malloc(sizeof(struct node));
	if(newNode == NULL)
		return FALSE;
	newNode->info = x;
	if(*list == NULL)
	{
		newNode->next = NULL;
		*list = newNode;
		return TRUE;
	}
	newNode->next = *list;
	*list = newNode;
	return TRUE;
}

int pop(NODEPTR *list)
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
	if(list == NULL)
		return INT_MIN;
	else
		return list->info;
}

void delStack(NODEPTR *list)
{
	NODEPTR delNode;
	while(*list != NULL)
	{
		delNode = *list;
		*list = (*list)->next;
		free(delNode);
	}	
}