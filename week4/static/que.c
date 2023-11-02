#include <stdio.h>
#include <stdlib.h>

void init(Queue *q) {
	q->head = 0;
	q->tail = 0;
}

void enqueue(Queue *q, int element) {

	if (isFull(q)) {
		printf("Cannot enqueue in filled queue.\n");
		exit(0);
	}
	q->data[q->tail] = element;
	q->tail++;
}

int dequeue(Queue *q) {

	if (isEmpty(q)) {
		printf("Cannot dequeue in empty queue.\n");
		exit(0);
	}
	int removedValue = q->data[q->head];
	q->head++;
	return removedValue;
}

int front(Queue *q) {

	if (isEmpty(q)) {
		printf("Cannot dequeue in empty queue.\n");
		exit(0);
	}
	return q->data[q->head];
}

int isFull(Queue *q) {
	return q->tail == DEFAULT_SIZE;
}

int isEmpty(Queue *q) {
	return q->head == q->tail;
}

void display(Queue *q) {
	printf("\nQueue:\n");
	int i = q->head;
	do {
		printf("%d -> ", q->data[i]);
		i++;
	} while(i != q->tail);
	printf("END\n");
}
