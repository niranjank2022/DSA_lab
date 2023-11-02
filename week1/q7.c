#include <stdio.h>

int main() {

	int n;

	printf("Enter size: ");
	scanf("%d", &n);

//	printf("%d", 1 << 3);

	int arr[n];
	int sum = 0, max = - (1 << 31), min = (1 << 31) - 1;
	printf("%d, %d", min, max);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
		if (min > arr[i])
			min = arr[i];
		if (max < arr[i])
			max = arr[i];
	}

	printf("Sum of array elements: %d\n"
		"Average of array elements: %.2f\n"
		"Minimum among array elements: %d\n"
		"Maximum among array elements: %d\n", sum, (float) sum / n, min, max);

}
