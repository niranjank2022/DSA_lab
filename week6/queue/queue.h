/**
 * This source file is customized inorder to easen the handling of the menu-driven program for BST
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "../btree/btree.h"

struct queuenode {
	TreeNodePtr data;
	struct queuenode *nextPtr;
};

typedef struct queuenode QueueNode;
typedef QueueNode *QueueNodePtr;

struct queue {
	QueueNodePtr head;
	QueueNodePtr tail;
};

typedef struct queue Queue;
typedef Queue *QueuePtr;

void enqueue(QueuePtr, TreeNodePtr);
TreeNodePtr dequeue(QueuePtr);
int front(QueuePtr);
void display(QueuePtr);
int isQEmpty(QueuePtr);
int qlength(QueuePtr);

#endif

#include "queue.c"

