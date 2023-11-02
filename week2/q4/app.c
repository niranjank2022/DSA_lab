#include <stdio.h>
#include "complex.h"

void main() {

	char ch = 'y';
	do {
		comp c1, c2, ans;
		char op;
		int flag = 1;

		printf("Enter operation (+, -, *, /, |(Modulus), ~(Conjugate)): ");
		op = getchar();
		if (op == '|' || op == '~') {
			printf("Complex Number 1:\n");
			c1 = getComp();
			if (op == '|') {
				printf("Modulus value: %.2f\n", cmod(&c1));
				flag = 0;
			}
			else if (op == '~')
				ans = conjugate(&c1);
		}

		else {
			printf("Complex Number 1:\n");
			c1 = getComp();                                                                                                             
			printf("Complex Number 2:\n");
			c2 = getComp();
			switch (op) {
				case '+':
					ans = cadd(&c1, &c2);
					break;
				case '-':
					ans = csub(&c1, &c2);
					break;
				case '*':
					ans = cprod(&c1, &c2);
					break;
				case '/':
					ans = cdiv(&c1, &c2);
					break;
				default:
					printf("*** Invalid operation. ***\n");
					flag = 0;

			}
		}

		if (flag) {
			printf("Result: ");
			cprint(&ans);
		}

		printf("Do you want to continue (y/n)? ");
		scanf(" %c", &ch);
		printf("\n##\t##\n");
	} while (ch == 'y');


}
