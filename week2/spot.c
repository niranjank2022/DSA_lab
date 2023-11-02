#include <stdio.h>
#include <stdlib.h>
#include "../mystl/easyarray.c"

char * func1(char *, int);
void func2(char *, char *, int);

void main() {

	char string[100];
	printf("Enter a string: ");
	fgets(string, 100, stdin);
	printf("Entered string: %s\n", string);

	int k = getSize();

	int length = 0;
	for (int i = k; i < 100 && string[i]; i++, length++)	;

	char sptr[20];
	func2(string, sptr, k);
	printf("Pointer way: %s\n", sptr);

	printf("Dynamic memory way: %s\n", func1(string, k);
}

char * func1(char *string, int k) {

	char *ptr = (char *) malloc(sizeof(char) * 
			k);

	sscanf(string + k, "%s", ptr);
	printf("%s\n", ptr);
	return ptr;
}

void func2(char *string, char *ptr,int k) {

	sscanf(string + k, "%s", ptr);
}
