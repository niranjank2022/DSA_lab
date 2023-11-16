import collections
import heapq

# class Prims():
#
#     def __init__(self, n, weightedEdges: list):
#         self.v = n
#         self.graph = [[0] * (n + 1) for i in range(n + 1)]
#         for i in range(len(weightedEdges)):
#             self.graph[weightedEdges[i][0]][weightedEdges[i][1]] = weightedEdges[i][2]
#             self.graph[weightedEdges[i][1]][weightedEdges[i][0]] = weightedEdges[i][2]
#
#     def findMinKey(self, distances, visited):
#         key = -1
#         d = float("inf")
#         for i in range(1, self.v + 1):
#             if i not in visited and distances[i] <= d:
#                 d = distances[i]
#                 key = i
#
#         return key
#
#     def prims(self):
#         # start = int(input("Enter arbitrary start vertex: "))
#         # heap = []
#         start = 1
#         distances = [float("inf")] * (self.v + 1)
#         distances[0] = distances[start] = 0
#         visited = set()
#
#         for i in range(self.v):
#             k = self.findMinKey(distances, visited)
#             visited.add(k)
#             for j in range(1, self.v):
#                 if self.graph[k][j] > 0:
#                     distances[j] = min(distances[j], self.graph[k][j])
#
#         print(distances)
#         print("Minimum cost of the Spanning Tree:", sum(distances))
#         # self.bfs(start)
#         # self.dfs(start)
#
#     def bfs(self, start):
#         print(f"BFS from the end {start}:")
#         queue = collections.deque([start])
#         visited = set()
#
#         while queue:
#             node = queue.popleft()
#             if node in visited:
#                 continue
#             visited.add(node)
#             print(node, end=' ')
#             for ch in self.spanningTree[node]:
#                 if ch not in visited:
#                     queue.append(ch)
#
#         print()
#
#     def dfs(self, start):
#         print(f"DFS from the end {start}:")
#         stack = [start]
#         visited = set()
#
#         while stack:
#             node = stack.pop()
#             if node in visited:
#                 continue
#             visited.add(node)
#             print(node, end=' ')
#             for ch in self.spanningTree[node]:
#                 if ch not in visited:
#                     stack.append(ch)
#
#         print()
#
#
# if __name__ == '__main__':
#     n = int(input('''Enter no. of edges: '''))
#     v = int(input("Enter no. of vertices: "))
#     print("Enter edges along with their weights: ")
#     weightedEdges = [list(map(int, input().split())) for i in range(n)]
#
#     obj = Prims(v, weightedEdges)
#     obj.prims()

INF = float("inf")


def _minKey(key, visited):  # Helper function for prim() below

    key_val = INF
    key_index = -1

    for i in range(len(key)):
        if key[i] < key_val and not visited[i]:
            key_val = key[i]
            key_index = i
    return key_index


def _printPrimMST(graph, parent):
    print("EDGE\tWeight")
    minCost = 0
    for i in range(1, len(parent)):
        print(f"{parent[i]} -> {i}  {graph[i][parent[i]]}")
        minCost += graph[i][parent[i]]
    print("Cost of the MST", minCost)


def prim(graph):
    n = len(graph)  # No. of vertices in the graph
    visited = [False] * n  # Array to store visited vertices
    parent = [0] * n  # Array to store the MST
    key = [INF] * n  # Minimum weight edge between i and parent[i]

    key[0] = 0  # To pick this node first
    parent[0] = -1  # Since  this  is the first one, its  parent is none i.e -1

    for i in range(n - 1):
        u = _minKey(key, visited)  # Find the unvisited vertex with minimum weight
        visited[u] = True  # Mark u as visited
        for v in range(n):
            # If v is not visited, weight of edge is non-zero and graph[u][v] < key[v],
            if not visited[v] and graph[u][v] and graph[u][v] < key[v]:
                key[v] = graph[u][v]
                parent[v] = u

    _printPrimMST(graph, parent)


if __name__ == '__main__':
    n = int(input('''Enter no. of edges: '''))
    v = int(input('''Enter no. of vertices: '''))
    print("Enter edges with weights: ")
    edges = [list(map(int, input().split())) for i in range(n)]
    # graph = [
    #     [0, 2, 0, 6, 0],
    #     [2, 0, 3, 8, 5],
    #     [0, 3, 0, 0, 7],
    #     [6, 8, 0, 0, 9],
    #     [0, 5, 7, 9, 0]
    # ]
    graph = [[0] * v for _ in range(v)]
    for u, v, w in edges:
        graph[u][v] = w
        graph[v][u] = w

    prim(graph)

"""
7, 9
0 5 10
0 1 28
5 4 25
4 6 24
4 3 22
6 3 18
3 2 12
2 1 16
6 1 14
"""
