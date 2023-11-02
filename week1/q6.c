#include <stdio.h>
#include <math.h>

int isPrime(int num) {
	if (num == 2)	return 1;

	for (int i = 2; i <= sqrt(num) + 1; i++)
		if (num % i == 0)
			return 0;

	return 1;
}

void main() {

	int n;
	printf("Enter n: ");
	scanf("%d", &n);

	int arr[n];
	int j;

	for (int i = 2, j = 0; j < n; i++) {
	
		if (isPrime(i)) {
		
			arr[j++] = i;
		}
	}

	printf("Series of prime:\n");

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	printf("\n");

}
