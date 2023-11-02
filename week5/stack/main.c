#include <stdio.h>
#include "stack.h"

void main() {
	
	StackNodePtr stack = NULL;
	int val, choice;
	int flag = 0;

	printf("Available Keys:\n(1) Push\t(2) Pop\t(3) Peek\t(4) Display\t(5) Exit\n");
	while (1) {
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				printf("Enter value to push: ");
				scanf("%d", &val);
				push(&stack, val);
				break;
			case 2:
				printf("Value popped : %d\n", pop(&stack));
				break;
			case 3:
				printf("Element at top: %d\n", peek(stack));
				break;
			case 4:
				display(stack);
				break;
			case 5:
				flag = 1;
				break;
			default:
				printf("Invalid key entered!!!\n");
		}

		if (flag)	break;
	}
}
