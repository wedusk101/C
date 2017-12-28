#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define TRUE 1
#define FALSE 0

int main()
{
	NODEPTR stack = NULL;
	int x = 0, ch = 0, result = 0;
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
				result = push(&stack, x);
				if(result == TRUE)
					printf("Element pushed successfully.\n\n");
				else
					printf("Stack overflow! Operation aborted.\n");
				break;
				
			case 2:
				if(isEmpty(stack))
				{
					printf("Empty stack! Operation aborted.\n\n");
					break;
				}
				x = pop(&stack);
				printf("The popped element is %d.\n", x);
				break;
				
			case 3:
				if(isEmpty(stack))
				{
					printf("Empty stack! Operation aborted.\n\n");
					break;
				}
				x = peek(stack);
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