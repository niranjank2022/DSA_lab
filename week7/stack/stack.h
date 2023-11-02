
struct stack {

	int *arr;
	int size;
	int length;
};

typedef struct stack Stack;

void init(Stack *);
void push(Stack *, int);
int pop(Stack *);
int isEmpty(Stack *);
int isFull(Stack *);
int peek(Stack *);
int get(Stack *, int);
void display(Stack *);

#include "stack.c"
