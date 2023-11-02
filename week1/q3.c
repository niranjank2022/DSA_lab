#include <stdio.h>
#include <math.h>

int isArmstrong( int );

void main() {

	int num;

	printf("Enter number: ");
	scanf("%d", &num);

//	for (int i = 0; i < 10000; i++)
//		if (isArmstrong(i))
//			printf("%d is Armstrong Number\n", i);
	if (isArmstrong(num))
		printf("%d is Armstrong Number\n", num);
	else
		printf("%d is not Armstrong\n", num);
}

int isArmstrong(int num) {

	int flag = 0, num_copy = num;
	while (num_copy) {

		flag += pow(num_copy % 10, 3);
		num_copy /= 10;
	}

	return num == flag ? 1 : 0;
}
