//queue.h -- Header file for single ended queue implementation

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node* NODEPTR;

int enqueue(NODEPTR*, NODEPTR*, int);
int dequeue(NODEPTR*);
int isEmpty(NODEPTR);

#endif