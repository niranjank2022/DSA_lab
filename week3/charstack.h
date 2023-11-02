// Header file for Stack ADT

struct stack {

	char *arr;
	int size;
	int length;
};

typedef struct stack Stack;

void init(Stack *);
void push(Stack *, char);
char pop(Stack *);
int isEmpty(Stack *);
int isFull(Stack *);
char peek(Stack *);
char get(Stack *, int);
void display(Stack *);

#include "charstack.c"
