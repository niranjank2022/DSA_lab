from random import *
from heapq import *


def knapsack(weight: list, profit: list, cap: int):
    n = len(weight)
    chosen = [0] * n
    heap = [(-profit[i] / weight[i], i) for i in range(n)]  # Max heap to store the profit per weight (kg)
    heapify(heap)
    res = 0
    while cap > 0:
        ppw, i = heappop(heap)
        x = 1
        if weight[i] > cap:
            x = cap / weight[i]
        chosen[i] = x
        res += profit[i] * x
        cap -= weight[i] * x

    print(chosen)
    return res


if __name__ == '__main__':
    # obj = [1, 2, 3, 4, 5, 6, 7]
    # weight = [2, 3, 5, 7, 1, 4, 1]
    # profit = [10, 5, 15, 7, 6, 18, 3]
    # capacity = 15
    c = randint(5, 20)
    weight = [randint(10, 30) for i in range(c)]
    profit = [randint(20, 40) for i in range(c)]
    print(profit, weight)
    print("Result:", knapsack(weight, profit, 30))
