#include <stdio.h>

int add(int a, int b) {

	return a + b;
}

int subtract(int a, int b) {

	return a - b;
}

int product(int a, int b) {

	return a * b;
}

int divide(int a, int b) {

	return a / b;
}

int mod(int a, int b) {

	return a % b;
}

void main() {

	//	char ch;

	//	while ((ch = getchar()) == 'x'){

	char op;
	int n1, n2, ans;

	printf("Enter operation: ");
	scanf("%c", &op);

	printf("Enter operands: ");
	scanf("%d%d", &n1, &n2);

	switch (op) {

		case '+':
			ans = add(n1, n2);
			break;
		case '-':
			ans = subtract(n1, n2);
			break;
		case '*':
			ans = product(n1, n2);
			break;
		case '/':
			if (n2 == 0) {
				printf("can't divide by 0.!!!\n");
				break;
			}
			ans = divide(n1, n2);
			break;
		case '%':
			if (n2 == 0) {
				printf("can't divide by 0.!!!\n");
				break;
			}
			ans = mod(n1, n2);
			break;
		default:
			printf("Invalid operation!!!\n");
	}

	printf("%d %c %d = %d\n", n1, op, n2, ans);

	//	}
}
