#include <stdio.h>
#include "easyarray.h"


void burr(int []);
void main() {

	int arr[] = {1, 2, 6, 7, 3};

	printArr(arr, 5);
	bubbleSort(arr, 5, 0);
	printArr(arr, 5);

	printf("%d %d\n", sizeof(arr), sizeof(int));
	burr(arr);
}

void burr(int arr[]) {

	printf("%d  %d", sizeof arr, sizeof(int));
}
