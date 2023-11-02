#include <stdio.h>
#include <stdlib.h>

void enqueue(QueuePtr que, TreeNodePtr treenode) {
	QueueNodePtr newPtr = malloc(sizeof(QueueNode));
	if (newPtr == NULL) {
		printf("!!! MEMORY IS NOT ALLOCATED. PROGRAM DISRUPTED !!!\n");
		exit(0);
	}
	newPtr->data = treenode;
	newPtr->nextPtr = NULL;

	if (isQEmpty(que))
		que->head = newPtr;
	else
		(que->tail)->nextPtr = newPtr;
	(que->tail) = newPtr;
}

TreeNodePtr dequeue(QueuePtr que) {
	if (isQEmpty(que)) {
		printf("!! Can not dequeue in empty queue !!\n");
		return NULL;
	}

	TreeNodePtr removed = que->head->data;
	QueueNodePtr tempPtr = que->head;
	que->head = que->head->nextPtr;
	if (que->head == NULL)
		que->tail == NULL;

	free(tempPtr);
	return removed;
}

int front(QueuePtr que) {
	if (isQEmpty(que)) {
		printf("!! Can not seek front element in the queue !!\n");
		exit(0);
	}
	return que->head->data->data;
}

void display(QueuePtr que) {
	QueueNodePtr curr = que->head;
	while (curr != NULL) {
		printf("%d <- ", curr->data->data);
		curr = curr->nextPtr;
	}
	printf("END\n");
}

int isQEmpty(QueuePtr que) {
	return que->head == NULL;
}

int qlength(QueuePtr que) {
	int size = 0;
	QueueNodePtr curr = que->head;
	while (curr != NULL) {
		size++;
		curr = curr->nextPtr;
	}
	return size;
}
