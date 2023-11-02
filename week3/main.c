#include <stdio.h>
#include "stack.h"

int main() {

	Stack stk;
	int ch;
	int num;
	int flag = 0;

	printf("!!! Welcome to the Stack Manipulation Program !!!\n"
		"Here is how you can use this menu-driven program!\n"
		"1) Initialization\n2) Push\n3) Pop\n4) Peek\n5) Get element\n6) Display the stack\n9) Exit the menu\n");

	while (1) {
		
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch (ch) {
		
			case 1:
				init(&stk);
				break;
			case 2:	
				printf("Enter element to push: ");
				scanf("%d", &num);
				push(&stk, num);
				break;
			case 3:	
				printf("Popped element: %d\n", pop(&stk));
				break;
			case 4:	
				printf("Element at the top of stack: %d\n", peek(&stk));
				break;
			case 5:	
				printf("Enter index of element: ");
				scanf("%d", &num);
				printf("Element: %d\n", get(&stk, num));
				break;
			case 6:
				printf("Elements in the stack (from bottom to top): ");
				display(&stk);
				break;

			case 9:
				flag = 1;
				break;


		}

		if (flag)
			break;
		fflush(stdin);
	}
}
