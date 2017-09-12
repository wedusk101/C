//queue.h -- Header file for a single ended queue

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node* NODEPTR;

void enqueue(NODEPTR*, NODEPTR*, int);
int dequeue(NODEPTR*);

#endif