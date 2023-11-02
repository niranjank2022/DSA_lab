#include <stdio.h>
#include <stdlib.h>

void init(Queue *q) {
	q->head = 0;
	q->tail = 0;
	q->size = 0;
}

void enqueue(Queue *q, int element) {

	if (isFull(q)) {
		printf("Cannot enqueue in filled queue.\n");
		exit(0);
	}
	q->size++;
	q->data[q->tail] = element;
	q->tail = (q->tail + 1) % DEFAULT_SIZE;		
}

int dequeue(Queue *q) {

	if (isEmpty(q)) {
		printf("Cannot dequeue in empty queue.\n");
		exit(0);
	}
	q->size--;
	int removedValue = q->data[q->head];
	q->head = (q->head + 1) % DEFAULT_SIZE;
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
	return q->size == DEFAULT_SIZE;
}

int isEmpty(Queue *q) {
	return q->size == 0;
}

void display(Queue *q) {
	printf("\nQueue:\n");
	int i = q->head;
	do {
		printf("%d -> ", q->data[i]);
		i = (i + 1) % DEFAULT_SIZE;
	} while(i != q->tail);
	printf("END\n");
}
