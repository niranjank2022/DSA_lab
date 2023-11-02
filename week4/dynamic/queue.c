#include <stdio.h>
#include <stdlib.h>

void init(Queue *q) {
	q->head = 0;
	q->tail = 0;
	q->size = 0;
	q->capacity = 10;
	q->data = (int *) malloc(q->capacity * sizeof(int));
}

void enqueue(Queue *q, int element) {

	if (isFull(q)) {
		int *temp = (int *) malloc(q->capacity * 2 * sizeof(int));
		for (int i = 0; i < q->capacity; i++)
			temp[i] = q->data[(q->head + i) % q->capacity];
		q->data = temp;
		q->head = 0;
		q->tail = q->capacity;
		q->capacity *= 2;
	}
	q->size++;
	q->data[q->tail] = element;
	q->tail = (q->tail + 1) % q->capacity;		
}

int dequeue(Queue *q) {

	if (isEmpty(q)) {
		printf("Cannot dequeue in empty queue.\n");
		exit(0);
	}
	q->size--;
	int removedValue = q->data[q->head];
	q->head = (q->head + 1) % q->capacity;
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
	return q->size == q->capacity;
}

int isEmpty(Queue *q) {
	return q->size == 0;
}

void display(Queue *q) {
	printf("\nQueue:\n");
	int i = q->head;
	do {
		printf("%d -> ", q->data[i]);
		i = (i + 1) % q->capacity;
	} while(i != q->tail);
	printf("END\n");
}
