#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

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
				x = pop(&stack);
				if(x == INT_MIN)
				{
					printf("Empty stack! Operation aborted.\n\n");
					break;
				}
				printf("The popped element is %d.\n", x);
				break;
				
			case 3:
				x = peek(stack);
				if(x == INT_MIN)
				{
					printf("Empty stack! Operation aborted.\n\n");
					break;
				}
				printf("The top element is %d.\n", x);
				break;
				
			case 4:
				printf("Bye!\n");
				break;
				
			default:
				printf("Invalid choice!\n\n");
		}		
	}while(ch != 4);
	return 0;	
}