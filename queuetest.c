#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define TRUE 1
#define FALSE 0

int main()
{
	NODEPTR head, tail;
	head = tail = NULL;
	int x = 0, ch = 0, result = 0;
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
				printf("Please enter the element to insert.\n\n");
				scanf("%d", &x);
				result = enqueue(&head, &tail, x);
				if(result == TRUE)
					printf("Element inserted successfully.\n\n");
				else
					printf("Error occurred during insertion! Operation aborted.\n");
				break;
				
			case 2:
				if(isEmpty(head))
				{
					printf("Empty queue! Operation aborted.\n\n");
					break;
				}
				x = dequeue(&head);
				printf("The deleted element is %d.\n", x);
				break;
				
			case 3:
				delQueue(&head);
				printf("Bye!\n");
				break;
				
			default:
				printf("Invalid choice!\n\n");
		}		
	}while(ch != 3);
	return 0;	
}