#include <stdio.h>

int main() {

	int n, k;

	printf("Enter n and k: ");
	scanf("%d %d", &n, &k);

	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int last[k];
	for (int i = 0; i < k; i++)
		last[i] = arr[i];

	for (int i = 0; i < n - k; i++)
		arr[i] = arr[i + k];
	for (int i = n - k, j = 0; i < n; i++, j++)
		arr[i] = last[j];

	printf("Array elements: \n");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

}
