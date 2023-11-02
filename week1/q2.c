#include <stdio.h>

void main() {

	int num, rnum = 0;

	printf("Enter number: ");
	scanf("%d", &num);
	
	printf("Reverse of %d is ", num);
	while (num > 0) {
		rnum = rnum * 10 + (num % 10);
		num /= 10;
	}

	printf("%d\n", rnum);
}
