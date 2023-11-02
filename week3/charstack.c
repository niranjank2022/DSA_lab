#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50

void init(Stack *stk) {
	stk->length = 0;
	stk->size = MAX_SIZE;
	stk->arr = (char *) malloc(MAX_SIZE * sizeof(char));
}

void push(Stack *stk, char element) {

	if (isFull(stk)) {
		stk->size = (stk->size * 3) / 2;
		stk->arr = (char *) realloc(stk->arr, stk->size * sizeof(char));
	}

	stk->arr[stk->length++] = element;
} 

char pop(Stack *stk) {
	if (isEmpty(stk))
		perror("StackEmptyError: Can't pop in empty stack.\n");
	return stk->arr[--stk->length];
}

char peek(Stack *stk) {
	char val = pop(stk);
	push(stk, val);
	return val;
}

int isEmpty(Stack *stk) {
	return stk->length == 0;
}

int isFull(Stack *stk) {
	return stk->length == stk->size;
}

char get(Stack *stk, int index) {
	if (isEmpty(stk))
		perror("StackEmptyError: Can't retrieve element.\n");
	if (index < 0 || index >= stk->length)
		perror("IndexError: Stack index out of range.\n");
	return stk->arr[index];
}

void display(Stack *stk) {
	printf("\n");
	for (int i = 0; i < stk->length; i++)
		printf("%c ", stk->arr[i]);
	printf("\b\b\n");
}
