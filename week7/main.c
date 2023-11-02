#include <stdio.h>
#include "stack.h"
#include "vector.h"

Vector vec = init();

int main() {

	Stack stk;
	init( &stk );

	int n, m;
	printf("Enter no. of nodes in the graph: ");
	scanf("%d", &n);
	printf("Enter no. of edges: ");
	scanf("%d", &m);

	int mat[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mat[i][j] = 0;

	printf("Enter edges (Note: Elements should range between [0 to n - 1]): ");
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		mat[x][y] = 1;
		mat[y][x] = 1;
	}

	int start;
	dfs(mat, start, n);
}

void dfs(int mat[][], int start, int n) {
	
	printf("%d ", start);
	push(start);

	for (int i = 0; i < n; i++) {
		if ( mat[start][i] == 1 && !isPresent(&vec, mat[start][i]) ) {
			dfs(mat, i);
			break;
		}
	}
	

}
