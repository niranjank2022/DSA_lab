#include <stdio.h>

int getSize(void) {

	int num;
	printf("Enter size: ");
	scanf("%d", &num);
	return num;
}

void printArr(int arr[], int size) {
	printf("Array elements:\n");
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void getArr(int arr[], int size) {
	printf("Enter array elements: \n");
	for (int i = 0; i < size; i++)
		scanf("%d", &arr[i]);
	printf("\n");
}

void bubbleSort(int arr[], int size, int reverse) {

	for (int i = 0; i < size - 2; i++)
		for (int j = 0; j < size - 1; j++)
			if ((!reverse && arr[j] > arr[j + 1]) || (reverse && arr[j] < arr[j + 1])) {
				int flag = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = flag;
			}
}
