#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "../mystl/easyarray.h"

void main() {

	int n;
	printf("Enter 'n': ");
	scanf("%d", &n);

	int arr[n];
	bool flag = true;
	float ans = 0;
	for (int i = 0; i < n; i++) {
		arr[i] = pow(2 * i + 1, 2);
		if (flag) {
			ans += arr[i];
			flag = false;
		}
		else {
			ans -= arr[i];
			flag = true;
		}

	}
	printf("The sequence...\n");
	printArr(arr, n);

	printf("Sum of the series: %.3f\n", ans);
}
