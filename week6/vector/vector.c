#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SIZE 10

void init(Vector *vec) {
	vec->length = 0;
	vec->arr = malloc(sizeof(int) * vec->length);
}

void vappend(Vector *vec, int val) {
	vinsert(vec, vec->length, val);
}

int vpop(Vector *vec) {
	vec->length--;
	int valuePopped = vec->arr[vec->length];
	return valuePopped;
}

void vinsert(Vector *vec, int index, int val) {
	vec->length++;
	vec->arr = realloc(vec->arr, vec->length * sizeof(int));
	for (int i = vec->length - 1; i > index; i--)
		vec->arr[i] = vec->arr[i - 1];
	vec->arr[index] = val;
}

int vremove(Vector *vec, int index) {
	vec->length--;
	int removedValue = vec->arr[index];
	for (int i = index; i < vec->length; i++)
		vec->arr[i] = vec->arr[i + 1];
	return removedValue;
}

void vprint(Vector *vec) {
	printf("\nVector elements: \n");
	for (int i = 0; i < vec->length; i++)
		printf("%d ", vec->arr[i]);
	printf("\n");
}

int vget(Vector *vec, int index) {
	if (index >= 0 && index < vec->length) {
		return vec->arr[index];
	}
	return -1;
}

int vindex(Vector *vec, int value, int start, int end) {
	for (int i = start; i <= end; i++)
		if (vec->arr[i] == value)
			return i;
	return -1;
}
