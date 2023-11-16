import collections
import heapq


class Kruskals:
    def __init__(self, edges: list[list[int]]):
        self.weightedEdges = edges
        self.spanningTree = collections.defaultdict(list)
        self.weightedEdges.sort()
        self.minCost = 0

    def kruskals(self) -> None:
        self.weightedEdges.sort(key=lambda x: x[2])

        for s, e, w in self.weightedEdges:
            if not self.hasCycle(s, e):
                self.spanningTree[s].append(e)
                self.spanningTree[e].append(s)
                print(self.minCost)
                self.minCost += w

        # print("Ends in the minimum spanning tree: ")
        # ends = [e for e in self.spanningTree if len(self.spanningTree[e]) == 1]
        # [print(x, end=' ') for x in ends]
        # print("\n")
        # for e in ends:
        #     self.bfs(e)
        #     self.dfs(e)
        #     print()
        start = int(input("Enter starting node: "))
        print("Minimum cost of the spanning tree:", self.minCost)
        self.bfs(start)
        self.dfs(start)

    def bfs(self, start):
        print(f"BFS from the end {start}:")
        queue = collections.deque([start])
        visited = set()

        while queue:
            node = queue.popleft()
            if node in visited:
                continue
            visited.add(node)
            print(node, end=' ')
            for ch in self.spanningTree[node]:
                if ch not in visited:
                    queue.append(ch)

        print()

    def dfs(self, start):
        print(f"DFS from the end {start}:")
        stack = [start]
        visited = set()

        while stack:
            node = stack.pop()
            if node in visited:
                continue
            visited.add(node)
            print(node, end=' ')
            for ch in self.spanningTree[node]:
                if ch not in visited:
                    stack.append(ch)

        print()

    def hasCycle(self, start, end):
        queue = collections.deque([start])
        visited = set()

        while queue:
            node = queue.popleft()
            if node in visited:
                continue
            visited.add(node)
            if node == end:
                return True
            for ch in self.spanningTree[node]:
                if ch not in visited:
                    queue.append(ch)

        return False


# if __name__ == '__main__':
#     n = int(input('''Enter no. of edges: '''))
#     print("Enter edges with weights: ")
#     edges = [list(map(int, input().split())) for i in range(n)]
#
#     obj = Kruskals(edges)
#     obj.kruskals()


def _findParent(parent, node):
    if parent[node] != node:
        parent[node] = _findParent(parent, parent[node])

    return parent[node]


def _unionSet(parent, rank, u, v):
    if rank[u] < rank[v]:
        parent[u] = v
    elif rank[u] > rank[v]:
        parent[v] = u
    else:
        parent[v] = u
        rank[u] += 1


def kruskal(edges):
    n = len(edges)
    parent = [i for i in range(n)]
    rank = [0] * n
    edges.sort(key=lambda x: x[2])

    minCost = 0
    print("Edges of the MST:")
    for i in range(n):
        v1 = _findParent(parent, edges[i][0])
        v2 = _findParent(parent, edges[i][1])
        w = edges[i][2]

        if v1 != v2:
            _unionSet(parent, rank, v1, v2)
            minCost += w
            print(f"{edges[i][0]} -> {edges[i][1]}\t{edges[i][2]}")

    print("Minimum cost of the MST:", minCost)


n = int(input('''Enter no. of edges: '''))
print("Enter edges with weights: ")
edges = [list(map(int, input().split())) for i in range(n)]
kruskal(edges)

'''
10
0 1 2
0 2 8
1 2 7
1 3 9
2 3 4
2 4 10
2 5 12
4 5 6
4 6 14
6 7 3
'''
