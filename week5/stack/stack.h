#ifndef STACK_H
#define STACK_H

struct stacknode {
	int data;
	struct stacknode *nextPtr;
};

typedef struct stacknode StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr *, int);
int pop(StackNodePtr *);
int peek(StackNodePtr);
int isEmpty(StackNodePtr);
void display(StackNodePtr);

#endif

#include "stack.c"
