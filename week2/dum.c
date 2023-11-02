#include <stdio.h>
#include <stdlib.h>
#include "../mystl/easyarray.c"

void main() {

	int *ptr;
	ptr = (int *) malloc(10 * sizeof(int));
	for (int i = 0; i < 20; i++)
		printf("%d ",*(ptr + i));
	printf("\n");

	for (int i = 0; i < 10; i++)
		ptr[i] = i + 3;
	
	for (int i = 0; i < 20; i++)
		printf("%d ",*(ptr + i));
	printf("\n");
	ptr = realloc(ptr, 20);

	for (int i = 0; i < 20; i++)
		                printf("%d ", *(ptr + i));

	printArr(ptr, 10);
}
