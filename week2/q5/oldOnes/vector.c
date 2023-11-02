#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SIZE 10

Vector init() {

	Vector vec;
	vec.length = 0;
	vec._size = DEFAULT_SIZE;
	vec.arr = (int *) malloc(vec._size * sizeof(int));
	return vec;
}

void vappend(Vector *vec, int val) {
	vinsert(vec, vec->length, val);
}

int vpop(Vector *vec) {
	vec->length--;
	int valuePopped = vec->arr[vec->length];
	return valuePopped;
}

void vinsert(Vector *vec, int i, int val) {

	void grow(Vector *, int); 

	vec->length++;
	if (vec->length == vec->_size)
		grow(vec, i);

	vec->arr[i] = val;
}

int vremove(Vector *vec, int index) {

	vec->length--;
	
	// Changing the size of vector
	int removedValue = vec->arr[index];
	int newSize = vec->_size;
	if (vec->length <= (vec->_size - 1) * 2 / 3)
		newSize = (vec->_size - 1) * 2 / 3;
	vec->_size = newSize;

	// Copying elements before index to new location
	int *newArr = (int *) malloc(newSize * sizeof(int));
	for (int i = 0; i < index; i++)
		newArr[i] = vec->arr[i];

	// Copying elements after index to new location
	for (int i = index; i < vec->length; i++)
		newArr[i] = vec->arr[i + 1];

	free(vec->arr);
	vec->arr = newArr;
	return removedValue;
}

void grow(Vector *vec, int index) {

	// Increasing the size
	int oldSize = vec->_size;
	int newSize = (oldSize * 3) / 2 + 1;
	vec->_size = newSize;


	// Copying the array elements to new location
	int *newArr = (int *) malloc(newSize * sizeof(int));
	for (int i = 0; i < index; i++)
		newArr[i] = vec->arr[i];
	for(int i = i + 1; i < vec->length; i++)
		newArr[i] = vec->arr[i - 1];

	// Free the old memory and change it to store the new memory
	free(vec->arr);
	vec->arr = newArr;
}

void vprint(Vector *vec) {

	printf("\nVector elements: \n");
	for (int i = 0; i < vec->length; i++)
		printf("%d ", vec->arr[i]);
	printf("\n");

}
