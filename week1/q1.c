#include <stdio.h>

void main() {

	int n1, n2, n3;

	printf("Enter no.1: ");
	scanf("%d", &n1);
	printf("Enter no.2: ");
	scanf("%d", &n2);
	printf("Enter no.3: ");
	scanf("%d", &n3);

	int gr8;
	if (n1 > n2 && n1 > n3)
		gr8 = n1;
	else if (n2 > n1 && n2 > n3)
		gr8 = n2;
	else
		gr8 = n3;

	printf("Maximum among %d, %d, %d ==> %d\n", n1, n2, n3, gr8);

}
