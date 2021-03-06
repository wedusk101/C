//queue.c -- Single ended queue implementation
#include "queue.h"

#define TRUE 1
#define FALSE 0

struct node
{
	int info;
	struct node *next;	
};

int isEmpty(NODEPTR head)
{
	if(head == NULL)
		return TRUE;
	else
		return FALSE;
}

int enqueue(NODEPTR *head, NODEPTR *tail, int x)
{
	NODEPTR newNode;
	newNode = malloc(sizeof(struct node));
	if(newNode == NULL)
	{
		perror("Error allocating memory.\n");
		return FALSE;
	}
	newNode->info = x;
	newNode->next = NULL;
	if(*head == NULL)
	{
		*tail = newNode;
		*head = *tail;
		return TRUE;
	}
	(*tail)->next = newNode;
	*tail = newNode;
	return TRUE;
}

int dequeue(NODEPTR *head)
{
	NODEPTR delNode;
	int val = 0;
	if(*head == NULL)
		return INT_MIN;
	val = (*head)->info;
	delNode = *head;
	*head = (*head)->next;
	free(delNode);
	return val;	
}

void delQueue(NODEPTR *head)
{
	NODEPTR delNode;
	while(*head != NULL)
	{
		delNode = *head;
		*head = (*head)->next;
		free(delNode);
	}
}