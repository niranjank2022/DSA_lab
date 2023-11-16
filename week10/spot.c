#include <stdio.h>
#include <string.h>
#include <math.h>

int lcs(int dp[][20], char *s1, char *s2, int i, int j, int n1, int n2) {

	if (i <= n1 && j <= n2 && 0 < i && 0 < j) {

		if (s1[i] == s2[j])
			dp[i][j] = 1 + lcs(dp, s1, s2, i - 1, j - 1, n1, n2);
		else
			dp[i][j] = fmax( dp[i - 1][j], dp[i][j - 1] );
	}
}

void main() {


	char str1[20], str2[20];

	printf("Enter the two strings:\n");
	scanf("%s%s", str1, str2);

	printf("%s %s\n", str1, str2);
	int n1 = strlen(str1), n2 = strlen(str2);
	int dp[n1 + 1][n2 + 1];

	for (int i = 0; i <= n1; i++)
		dp[i][0] = 0;
	for (int j = 0; j <= n2; j++)
		dp[0][j] = 0;

	for (int i = 1; i <= n1; i++)
		for (int j = 1; j <= n2; j++)
			if (str1[i - 1] == str2[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = fmax(dp[i - 1][j], dp[i][j - 1]);

	char lcs[ dp[n1][n2] ];
	int i = n1, j = n2, k = dp[n1][n2];

	while (i > 0 && j > 0) {
	
		if (str1[i - 1] == str2[j - 1]) {
			lcs[--k] = str1[i - 1];
			i--;
			j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1])
			i--;
		else
			j--;
	}

	printf("LCS of %s and %s ==> %s\n", str1, str2, lcs);
}
