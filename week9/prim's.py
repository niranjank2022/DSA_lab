import collections
import heapq


class Prims():

    def __init__(self, weightedEdges: list):
        self.graph = collections.defaultdict(list)
        self.spanningTree = collections.defaultdict(list)
        self.minCost = 0
        for i in range(len(weightedEdges)):
            s, e, w = weightedEdges[i]
            self.graph[s].append((e, w))
            self.graph[e].append((s, w))

        self.n = len(self.graph)

    def prims(self):
        start = int(input("Enter arbitrary start vertex: "))
        heap = []

        last = start
        visited = set()
        while len(self.spanningTree) != self.n:

            for e, w in self.graph[last]:
                heapq.heappush(heap, (w, e))

            w, target = heapq.heappop(heap)
            while target in visited:
                w, target = heapq.heappop(heap)
            visited.add(last)
            self.minCost += w
            self.spanningTree[last].append(target)
            self.spanningTree[target].append(last)
            last = target

        print("Minimum cost of the Spanning Tree:", self.minCost)
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


if __name__ == '__main__':
    n = int(input('''Enter no. of edges: '''))
    print("Enter edges along with their weights: ")
    weightedEdges = [list(map(int, input().split())) for i in range(n)]

    obj = Prims(weightedEdges)
    obj.prims()

"""
1 6 10
1 2 28
6 5 25
5 7 24
5 4 22
7 4 18
4 3 12
3 2 16
7 2 14
"""
