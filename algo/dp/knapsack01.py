def _01knapsack(weights, profits, capacity):
    n = len(profits)
    dp = [[0] * (capacity + 1) for _ in range(n + 1)]
    for i in range(n + 1):
        for w in range(capacity + 1):
            if i == 0 or w == 0:
                dp[i][w] = 0
            elif weights[i - 1] <= w:
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + profits[i - 1])
            else:
                dp[i][w] = dp[i - 1][w]

    print(dp[n][capacity])
    # [print(row) for row in dp]
    print("Tracing the 0-1 knapsack")
    i = n
    j = capacity
    while i > 0 and j >= 0:
        if dp[i][j] != dp[i - 1][j]:
            print(f"({i - 1}) {weights[i - 1]}, {profits[i - 1]} -> 1")
            i -= 1
            j -= weights[i]
        else:
            print(f"({i - 1}) {weights[i - 1]}, {profits[i - 1]} -> 0")
            i -= 1


_01knapsack([2, 3, 4, 5], [1, 2, 5, 6], 8)
