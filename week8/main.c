#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../mystl/easyarray.h"

void mergeSort( int *, int );
void quickSort( int *, int, int );
void heapSort( int *, int );
void insertionSort( int *, int );
void swap( int *, int, int );


void main() {

	int n;
	printf("Enter size: ");
	scanf("%d", &n);

	int arr1[n], arr2[n];
	int num;

	printf("Enter array elements: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		arr1[i] = arr2[i] = num;
	}

	// Random number generation
	//	srand( time(NULL) );
	//	printf("Random numbers generated...\n");
	//	for (int i = 0; i < n; i++) {
	//		arr1[i] = 1 + rand() % 100;
	//		arr2[i] = 1 + rand() % 100;
	//	}

	//	printf("Entered elements: ");
	//	printArr(arr1, n);
	//	printArr(arr2, n);

//	printf("\nAfter Mergesort: \n");
//	mergeSort(arr1, n);
//	printArr(arr1, n);

//	printf("\nAfter Quicksort: \n");
//	quickSort(arr2, 0, n - 1);
//	printArr(arr2, n);

	printf("\nAfter Heapsort: \n");
	        heapSort(arr2, n);
		        printArr(arr2, n);
}

void mergeSort(int *arr, int n) {

	void merge(int *, int, int *, int, int *, int);

	if (n > 1) {

		int mid = n / 2;
		int *left, *right;
		left = malloc(sizeof(int) * mid);
		right = malloc(sizeof(int) * (n - mid));

		for (int i = 0; i < mid; i++)
			left[i] = arr[i];
		for (int i = mid; i < n; i++)
			right[i - mid] = arr[i];

		mergeSort(left, mid);
		mergeSort(right, n - mid);
		merge(arr, n, left, mid, right, n - mid);
	}
}

void merge(int *sorted, int s, int *arr1, int a1, int *arr2, int a2) {

	int i, j, k;
	i = j = k = 0;

	while (i < a1 && j < a2) 
		if (arr1[i] <= arr2[j])
			sorted[k++] = arr1[i++];
		else
			sorted[k++] = arr2[j++];
	while (i < a1)
		sorted[k++] = arr1[i++];
	while (j < a2)
		sorted[k++] = arr2[j++];
}

void swap(int *arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void quickSort(int *arr, int low, int high) {
	if (low < high) {
		int i = low, j = high + 1, pivot = low;
		do {
			do {
				i++;
			} while (arr[i] < arr[pivot]);

			do {
				j--;
			} while (arr[j] > arr[pivot]);

			if (i < j)
				swap(arr, i, j);
		} while (i < j);

		swap(arr, j, pivot);
		quickSort(arr, low, j - 1);
		quickSort(arr, j + 1, high);
	}
}

void heapSort(int *arr, int n) {

	void heapify(int *, int, int);

	// Making the array into a heap
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// Sorting the array
	for (int i = n - 1; i > 0; i--) {
		swap(arr, 0, i);
		heapify(arr, i, 0);
	}
}

void heapify(int *arr, int n, int i) {

	int largest = i,
	    left = 2 * i + 1,
	    right = 2 * i + 2;

	if (left < n && arr[largest] < arr[left])
		largest = left;
	if (right < n && arr[largest] < arr[right])
		largest = right;

	if (i != largest) {
		swap(arr, i, largest);
		heapify(arr, n, largest);
	}
}

void insertionSort(int *arr, int n) {

	for (int i = 1; i < n; i++) {

		int j = i - 1;
		while (j >= 0 && arr[j] > arr[j + 1])
			j--;	
	}
}
