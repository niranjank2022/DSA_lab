#include <stdio.h>
#include <stdlib.h>

void push(StackNodePtr *top, int val) {

	StackNodePtr newPtr = malloc(sizeof(StackNode));
	if (newPtr == NULL) {
		printf("!!! MEMORY NOT ALLOCATED !!!\n");
		exit(0);
	}
	newPtr->data = val;
	newPtr->nextPtr = *top;
	*top = newPtr;
}

int pop(StackNodePtr *top) {
	if (isEmpty(*top)) {
		printf("!! Empty stack can not be popped !!\n");
		return -1;
	}
	int popped = (*top)->data;
	*top = (*top)->nextPtr;
	return popped;
}

int peek(StackNodePtr top) {
	return top->data;
}

// ↡↡↧⇓⇟⇣⇩⇲▼

void display(StackNodePtr top) {
	StackNodePtr currPtr = top;
	printf("\n");
	while (currPtr != NULL) {
		printf(" %d\n  |\n  ▼\n", currPtr->data);
		currPtr = currPtr->nextPtr;
	}
	printf("END\n\n");
}

int isEmpty(StackNodePtr top) {
	return top == NULL;
}
