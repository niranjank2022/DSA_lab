#include <stdio.h>

static long int dp[1000] = {0, 1};


long int fact1(int num) {

	if (num == 0)
		return 0;
	if (dp[num - 1])
		return dp[num - 1];
	 dp[num - 1] = fact1(num - 1) + fact1(num - 2);
	 return dp[num - 1];
}

long int fact2(int num) {

	if (num == 1)
		return 0;
	if (num == 2)
		return 1;
	return fact2(num - 1) + fact2(num - 2);
}

void main() {

	int num;

	printf("Enter a number: ");
	scanf("%d", &num);

	long int fnum = fact2(num);

//	for (int i = 0; i < 1000; i++)
//		printf("%d ", dp[i]);

	printf("Factorial of %d ==> %ld\n", num, fnum);
}
