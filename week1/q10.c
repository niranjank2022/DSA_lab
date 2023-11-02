#include <stdio.h>
#include <string.h>

void main() {


	char str1[20], str2[20];

	printf("Enter a string: ");
	scanf("%s", &str1);

	printf("Enter a string: ");
	scanf("%s", &str2);

//	int i, j;
//	for (i = 0, j = 0; str1[i] && str2[j] && str1[i] == str2[j]; i++, j++)
		;

//	if (str1[i] && str2[j] && str1[i] != str2[j])
//		printf("%s and %s are not equal.\n", str1, str2);
//	else
//		printf("%s and %s are equal.\n", str1, str2);

	if (strcmp(str1, str2))
		printf("%s and %s are not equal.\n", str1, str2);
	else
		printf("%s and %s are equal.\n", str1, str2);
}
