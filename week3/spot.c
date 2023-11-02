#include <stdio.h>
#include "charstack.h"
#include <string.h>

int isPalindrome(char *);

void main() {

	char str[100];

	printf("Enter the string: ");
	scanf("%s", str);

	printf(isPalindrome(str) ? "YES\n" : "NO\n");
}

int isPalindrome(char *str) {

	Stack stk;
	init(&stk);

	for (int i = 0; i < strlen(str); i++)
		push(&stk, str[i]);
//	display(&stk);
	char cstr[100];
	int i;
	for (i = 0; i < strlen(str); i++)
		cstr[i] = pop(&stk);
	cstr[i] = '\0';
	if (strcmp(str, cstr) == 0)
		return 1;
	else
		return 0;
}

