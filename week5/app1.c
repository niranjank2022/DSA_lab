#include <stdio.h>
#include "stack/stack.h"
#include <string.h>
#include <ctype.h>

char *infixToPost(char *);
int evalPostfix(char *, int);

void main() {
	char str[100];
	
	printf("Enter the expression: ");
	fgets(str, 100, stdin);

//	char *postfix;
//	postfix = (char *) infixToPost(str);
//	printf("Postfix expression: ");
	printf("Evaluated result: %d", evalPostfix(str, strlen(str)));
}

char *infixToPost(char *exp, int n) {
	
	StackNodePtr postfix = NULL;
	int num = 0;

	for (int i = 0; i < n; i++) {
		if (isdigit(exp[i])) {
			num += num * 10 + exp[i] - '0';
		}
	}
}

int evalPostfix(char *exp, int n) {

	StackNodePtr postfix = NULL;
	StackNodePtr num = NULL;
	
	for (int i = 0; i < n - 1; i++) {
		if (isdigit(exp[i]))
			push(&num, exp[i] - '0');
		else if (exp[i] == ' ' && !isEmpty(num)) {
			int val = 0;
			int base = 1;
			while (!isEmpty(num)) {
				val += pop(&num) * base;
				base *= 10;
			}
			push(&postfix, val);
		}
		else if (exp[i] == ' ' && isEmpty(num))
			continue;
		else {
			int num1, num2;
			num2 = pop(&postfix);
			num1 = pop(&postfix);

			switch (exp[i]) {
				case '+':
					push(&postfix, num1 + num2);
					break;
				case '-':
					push(&postfix, num1 - num2);
					break;
				case '*':
					push(&postfix, num1 * num2);
					break;
				case '/':
					push(&postfix, num1 / num2);
					break;
				default:
					printf("Error\n");
			}
		}
	}
	return pop(&postfix);

}
