// Header file containing all the declarations
#ifndef QUE_H
#define QUE_H

#define DEFAULT_SIZE 10

struct queue {

	int data[DEFAULT_SIZE];
	int head, tail, size;
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

#include "que.c"

#endif
