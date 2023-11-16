#include <stdio.h>
#include <stdlib.h>

void DFS(int **A, int x, int n, int *visited)
{
    if (visited[x] != 1)
    {

        printf("%d ", x);
        visited[x] = 1;
        for (int y = 0; y < n; y++)
        {

            if (A[x][y] == 1 && visited[y] == 0)
            {
                DFS(A, y, n, visited);
            }
        }
    }
}
int main()
{
    int n, start;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int **A = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        A[i] = (int *)malloc(n * sizeof(int));
    }
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    int *visited = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    DFS(A, start, n, visited);

    return 0;
}
