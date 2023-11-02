#include <stdio.h>

long int fact(int num) {

	if (num == 0 || num == 1)	return 1;

	if (num > 1)
		return num * fact(num - 1);

	return 0;
}

void main() {

	int num;

	printf("Enter a number: ");
	scanf("%d", &num);

	long int fnum = fact(num);
	printf("Factorial of %d ==> %d", num, fnum);

}
