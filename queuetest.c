#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

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
				printf("Please enter the element to insert.\n\n");
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