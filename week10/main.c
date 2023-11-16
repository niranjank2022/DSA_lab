#include <stdio.h>
#define MAX 10
#define INF 99999

void floydWarshall(int dist[][MAX], int V) {

	int i, j, k;
	for (k = 0; k < V; k++) {
		for (i = 0; i < V; i++) {
			for (j = 0; j < V; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
}

void main() {

	int graph[MAX][MAX];
	int n, e, a, b, c;

	printf("Enter no. of vertices: ");
	scanf("%d", &n);
	printf("Enter no. of edges: ");
	scanf("%d", &e);

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) graph[i][j] = (i == j) ? 0 : INF;

	printf("Enter edges with their weights:\n");
	for (int i = 0; i < e; i++) {
			scanf("%d%d%d", &a, &b, &c);
			graph[a][b] = c;
	}

	floydWarshall(graph, n);
	
	printf("Shortest distance between any two vertices:\n");
	printf("%6s", "Pts");
	for (int i = 0; i < n; i++)
		printf("%6d", i);

	for (int i = 0; i < n; i++) {
		printf("\n%6d", i);
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == INF)
				printf("%6s", "INF");
			else
				printf("%6d", graph[i][j]);
		}
	}

	printf("\n");
}

