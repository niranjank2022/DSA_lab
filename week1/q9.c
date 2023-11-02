#include <stdio.h>
#include "easyarray.c"

void main() {

	int size = getSize();
	int arr[size];

	getArr(arr, size);
	printArr(arr, size);

	int oddEven[2] = {0};
	for (int i = 0; i < size; i++)
		oddEven[arr[i] % 2]++;

	printf("Count of Odd Numbers: %d"
		"\nCount of Even Numbers: %d\n", oddEven[1], oddEven[0]);
}
