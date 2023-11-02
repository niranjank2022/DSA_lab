#include <stdio.h>
#include "easyarray.c"

void main() {

	int n = getSize();
	int arr[n];

	getArr(arr, n);
	printArr(arr, n);

	bubbleSort(arr, n, 0);
	printArr(arr, n);

	bubbleSort(arr, n, 1);                                                                                                                         
	printArr(arr, n);
}
