//queue.c -- Single ended queue implementation
#include "queue.h"

struct node
{
	int info;
	struct node *next;	
};

void enqueue(NODEPTR *head, NODEPTR *tail, int x)
{
	NODEPTR newNode;
	newNode = malloc(sizeof(struct node));
	if(newNode == NULL)
	{
		printf("Error occurred during insertion! Operation aborted.\n");
		return;
	}
	newNode->info = x;
	newNode->next = NULL;
	if(*head == NULL)
	{
		*tail = newNode;
		*head = *tail;
		printf("Element inserted successfully.\n\n");
		return;
	}
	(*tail)->next = newNode;
	*tail = newNode;
	printf("Element inserted successfully.\n\n");
}

int dequeue(NODEPTR* head)
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