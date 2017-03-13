/* The following code implements a basic queue with insert and delete operations.The implementation uses
three variables, "front" , "rear" and "count", to keep track of the front of the queue, the rear of the queue
and the number of elements in the queue respectively.Since this is a linear queue implemented using an array,
where the front is incremented after each deletion, the queue eventually runs out of usable space. Mitigating
this problem here would require expensive copy and swap operations which has not been done here. Instead, the
user is given a choice to reinitialize the queue in such a situation.*/

#include<stdio.h>
#define MAXSIZE 4

struct queue
{
	int items[MAXSIZE];
	int front;
	int rear;
	int count;
};

void initQueue(struct queue*);
void enque(struct queue*, int);
void deque(struct queue*);

int main()
{
	struct queue q; // declares a struct variable
	int choice = 0, x = 0;
	initQueue(&q);
	printf("This program implements a queue with the following basic operations.\n");
	do
	{
		printf("\n----------- MENU -------------\n");
        printf("\n 1.APPEND    2.SERVE	3.REINITIALIZE   4.EXIT\n");
        printf("\n------------------------------\n");
        printf("\nPlease enter your choice (1 / 2 / 3 / 4): ");
        scanf("%d",&choice);
		switch(choice)
		{	case 1: 	printf("\nPlease enter the element to append: ");
						scanf("%d",&x);
						enque(&q, x);
						break;
			
			case 2: 	deque(&q);
						break;
			
			case 3:  	initQueue(&q);
						break;
						
			case 4: 	break;
			
			default:	printf("\nInvalid choice. Try again.\n");
		}
	}while(choice != 4);
	printf("Thank you.\n");
	return 0;
}// end of main

void initQueue(struct queue *pq) // initializes the queue
{
	pq->front = -1;
	pq->rear = -1;
	pq->count = 0;
}

void enque(struct queue *pq, int x) // inserts elements into the rear of the queue
{
	if(pq->rear == -1)
		pq->front = 0; // the front is fixed at zero for the very first insertion
	if(pq->rear < MAXSIZE - 1) // checks if the queue has run out of space for new insertions
	{
		pq->rear += 1;
		pq->items[pq->rear] = x;
		pq->count += 1; 
	}
	else
	{
		printf("Queue is full! Operation failed.\n");
		printf("Serve or reinitialize.");
		return;
	}
	printf("Element has been appended successfuly.\n");
}

void deque(struct queue *pq) // deletes elements from the front of the queue
{
	int val = 0;
	if(pq->count == 0)
	{
		printf("Queue is empty! Operation failed.\n");
		initQueue(pq); // reinitializes the empty queue
		return;
	}
	else
	{
		val = pq->items[pq->front]; // stores the served element
		pq->front += 1;
		pq->count -= 1;
	}
	printf("The element served is %d.\n", val);
}