#include <stdio.h>
#include "../mystl/easyarray.h"

void bSort(int [], int, int);
void swap1(int *, int *);
void swap2(int , int);

void main() {

	int size;
	size = getSize();
	int arr[size];
	getArr(arr, size);
	printArr(arr, size);

	int arr2[size], arr3[size];

	for (int i = 0; i < size; i++)
		arr2[i] = arr3[i] = arr[i];

	for (int i = 0; i < size; i++) {
		int sorted = 1;
		for (int j = 0; j < size - 1; j++)
			if (arr[j] > arr[j + 1]) {
				int flag = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = flag;
				sorted = 0;
			}
		if (sorted)
			break;
	}
	printArr(arr, size);

	printArr(arr2, size);
	bSort(arr2, size, 1);
	printArr(arr2, size);

	printArr(arr3, size);
	bSort(&arr3[0], size, 2);
	printArr(arr3, size);

}


void bSort(int arr[], int size, int swap) {

	for (int i = 0; i < size; i++) {
		int sorted = 1;
		for (int j = 0; j < size - 1; j++)
			if (arr[j] > arr[j + 1]) {
				if (swap == 1)	swap1(&arr[j], &arr[j + 1]);
				else	swap2(arr[j], arr[j + 1]);
				sorted = 0;
			}
		if (sorted)
			break;
	}
} 

void swap1(int *n1, int *n2) {

	int flag = *n1;
	*n1 = *n2;
	*n2 = flag;
}

void swap2(int n1, int n2) {

	int flag = n1;
	n1 = n2;
	n2 = flag;
}
