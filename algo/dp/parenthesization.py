import sys


def parenthesis(arr: list):
    n = len(arr)
    cost = [[0] * (n + 1) for _ in range(n)]
    kVal = [[0] * (n + 1) for _ in range(n)]

    for d in range(1, n - 1):
        for i in range(1, n):

            j = i + d

            mn = 2 ** 31
            for k in range(i, j):
                q = cost[i][k] + cost[k + 1][j] + arr[i - 1] * arr[k] * arr[j]
                if q < mn:
                    cost[i][j] = mn
                    kVal[i][j] = k
            
