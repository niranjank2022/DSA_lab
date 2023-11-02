#ifndef QUEUE_H
#define QUEUE_H

struct queuenode {
	int data;
	struct queuenode *nextPtr;
};

typedef struct queuenode QueueNode;
typedef QueueNode *QueueNodePtr;

void enqueue(QueueNodePtr *, QueueNodePtr *, int);
int dequeue(QueueNodePtr *, QueueNodePtr *);
int front(QueueNodePtr);
void display(QueueNodePtr);
int isEmpty(QueueNodePtr);

#endif

#include "queue.c"

