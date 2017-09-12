/*The following program implements a stack with basic push, pop and peek operations using a single linked list.*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *next;	
};

typedef struct node* NODEPTR;

void push(NODEPTR*, int);
void pop(NODEPTR*);
void peek(NODEPTR);

int main()
{
	NODEPTR stack = NULL;
	int x = 0, ch = 0;
	do
	{
		printf("Please enter your choice.\n\n");
		printf("1. PUSH\n");
		printf("2. POP\n");
		printf("3. PEEK\n");
		printf("4. EXIT\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				printf("Please enter the element to push.\n\n");
				scanf("%d", &x);
				push(&stack, x);
				break;
				
			case 2:
				pop(&stack);
				break;
				
			case 3:
				peek(stack);
				break;
				
			case 4:
				printf("Bye!\n");
				break;
				
			default:
				printf("Invalid choice!\n\n");
		}		
	}while(ch != 4);	
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

void pop(NODEPTR* list)
{
	NODEPTR delNode;
	int val = 0;
	if(*list == NULL)
	{
		printf("Empty stack! Operation aborted.\n\n");
		return;
	}
	val = (*list)->info;
	delNode = *list;
	*list = (*list)->next;
	printf("The popped element is %d.\n\n", val);
	free(delNode);	
}

void peek(NODEPTR list)
{
	int val = 0;
	if(list == NULL)
	{
		printf("Empty stack! Operation aborted.\n\n");
		return;
	}
	val = list->info;
	printf("The top element is %d.\n\n", val);	
}