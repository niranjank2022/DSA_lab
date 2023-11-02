#include <stdio.h>
#include <stdlib.h>

void init(Queue *q) {
	q->head = 0;
	q->tail = 0;
	q->capacity = 10;
	q->data = (int *) malloc(q->capacity * sizeof(int));
}

void enqueue(Queue *q, int element) {

	if (isFull(q)) {
		int *temp = q->data + q->head;
		temp = (int *) realloc(temp, q->capacity * 2 * sizeof(int));

		q->data = temp;
		q->head = 0;
		q->tail = q->capacity;
		q->capacity *= 2;
	}
	q->data[q->tail] = element;
	q->tail = (q->tail + 1) % q->capacity;		
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
	return q->tail == q->capacity;
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
