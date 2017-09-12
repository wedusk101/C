/*The following program implements a single ended queue with basic enqueue and dequeue operations using a single linked list.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
	int info;
	struct node *next;	
};

typedef struct node* NODEPTR;

void enqueue(NODEPTR*, NODEPTR*, int);
int dequeue(NODEPTR*);

int main()
{
	NODEPTR head, tail;
	head = tail = NULL;
	int x = 0, ch = 0;
	do
	{
		printf("Please enter your choice.\n\n");
		printf("1. ENQUEUE\n");
		printf("2. DEQUEUE\n");
		printf("3. EXIT\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				printf("Please enter the element to push.\n\n");
				scanf("%d", &x);
				enqueue(&head, &tail, x);
				break;
				
			case 2:
				x = dequeue(&head);
				if(x == INT_MIN)
				{
					printf("Empty queue! Operation aborted.\n\n");
					break;
				}
				printf("The deleted element is %d.\n", x);
				break;
				
			case 3:
				printf("Bye!\n");
				break;
				
			default:
				printf("Invalid choice!\n\n");
		}		
	}while(ch != 3);
	return 0;
}

void enqueue(NODEPTR *head, NODEPTR *tail, int x)
{
	NODEPTR newNode;
	newNode = malloc(sizeof(struct node));
	if(newNode == NULL)
	{
		printf("Error occured during insertion! Operation aborted.\n");
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