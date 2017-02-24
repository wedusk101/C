/* The following code implements a basic stack with push and pop operations. */
#include<stdio.h>

#define MAXSTACK 4
#define TRUE 1
#define FALSE 0

struct stack
{
       int items[MAXSTACK];
       int top;
};

int empty(struct stack*); // function prototype for empty; returns TRUE if the stack is empty, FALSE otherwise
void initStack(struct stack*); // function prototype for initStack; initializes the stack to empty state 
void push(struct stack*, int); // function prototype for push 
void pop(struct stack*); // function prototype for pop 

int main(void)
{
	struct stack s;    // declares a struct variable
	int choice = 0, x = 0;
	initStack(&s);
	printf("This program implements a stack with the following basic operations.\n");
	do
	{
		printf("\n----------- MENU -------------\n");
        printf("\n 1. PUSH    2. POP    3. EXIT\n");
        printf("\n------------------------------\n");
        printf("\nPlease enter your choice (1 / 2 / 3): ");
        scanf("%d",&choice);
		switch(choice)
		{	case 1: 	printf("\nPlease enter the element to push: ");
						scanf("%d",&x);
						push(&s, x);
						break;
			
			case 2: 	pop(&s);
						break;
					
			case 3: 	break;
			
			default:	printf("\nInvalid choice. Try again.\n");
		}
	}while(choice != 3);
	return 0;
}// end of main 

int empty(struct stack *ps)
{
    	if(ps->top == -1)
		return TRUE;
    	else
        	return FALSE;
}

void initStack(struct stack *ps)
{	
	ps->top = -1;
}

void push(struct stack *ps, int x)
{
    	if(ps->top == MAXSTACK - 1)
    	{
		printf("\nStack Overflow! Cannot push into a full stack.\n");
		return;
    	}
    	else
    	{
		ps->top = ps->top + 1;
        	ps->items[ps->top] = x;
    	}
    	printf("\nElement has been pushed successfully.\n");
} 


void pop(struct stack *ps) 
{
    	int pop = 0;
    	if(empty(ps))
    	{
		printf("\nStack Underflow! Cannot pop from an empty stack.\n");
        	return;
    	}
    	else
    	{
		pop = ps->items[ps->top];
        	ps->top = ps->top - 1;
    	}
    	printf("\nPopped element is %d.\n", pop);
}
    




