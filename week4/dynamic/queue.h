// Header file containing all the declarations
#ifndef QUEUE_H
#define QUEUE_H

#define DEFAULT_SIZE 10

struct queue {
	int *data;
	int head, tail, size, capacity;
};

typedef struct queue Queue;

void init(Queue *);
void enqueue(Queue *, int);
int dequeue(Queue *);
void display(Queue *);
int front(Queue *);
void size(Queue *);
int isFull(Queue *);
int isEmpty(Queue *);

#include "queue.c"

#endif
