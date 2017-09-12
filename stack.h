//stack.h -- Header file for a single ended queue

#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node* NODEPTR;

void push(NODEPTR*, int);
int pop(NODEPTR*);
int peek(NODEPTR);

#endif