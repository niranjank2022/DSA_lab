#include <stdio.h>
#include <stdlib.h>

void enqueue(QueueNodePtr *head, QueueNodePtr *tail, int val) {
	QueueNodePtr newPtr = malloc(sizeof(QueueNode));
	if (newPtr == NULL) {
		printf("!!! MEMORY IS NOT ALLOCATED. PROGRAM DISRUPTED !!!\n");
		exit(0);
	}
	newPtr->data = val;
	newPtr->nextPtr = NULL;

	if (isEmpty(*head))
		*head = newPtr;
	else
		(*tail)->nextPtr = newPtr;
	(*tail) = newPtr;	
}

int dequeue(QueueNodePtr *head, QueueNodePtr *tail) {
	if (isEmpty(*head)) {
		printf("!! Can not dequeue in empty queue !!\n");
		return -1;
	}

	int removed = (*head)->data;
	QueueNodePtr tempPtr = *head;
	*head =	(*head)->nextPtr;
	if (*head == NULL)
		*tail == NULL;

	free(tempPtr);
	return removed;
}

int front(QueueNodePtr head) {
	if (isEmpty(head)) {
		printf("!! Can not seek front element in the queue !!\n");
		exit(0);
	}
	return head->data;
}

void display(QueueNodePtr curr) {
	while (curr != NULL) {
		printf("%d <- ", curr->data);
		curr = curr->nextPtr;
	}
	printf("END\n");
}

int isEmpty(QueueNodePtr head) {
	return head == NULL;
}

