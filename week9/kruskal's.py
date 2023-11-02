import collections
import heapq


class Kruskals:
    def __init__(self, edges: list):
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
                self.minCost += w

        # print("Ends in the minimum spanning tree: ")
        # ends = [e for e in self.spanningTree if len(self.spanningTree[e]) == 1]
        # [print(x, end=' ') for x in ends]
        # print("\n")
        # for e in ends:
        #     self.bfs(e)
        #     self.dfs(e)
        #     print()
        print("Minimum cost of the Spanning tree:", self.minCost)
        start = int(input("Enter starting node: "))
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


if __name__ == '__main__':
    n = int(input('''Enter no. of edges: '''))
    print("Enter edges with weights: ")
    edges = [list(map(int, input().split())) for i in range(n)]

    obj = Kruskals(edges)
    obj.kruskals()

'''
10
1 2 2
1 3 8
2 3 7
2 4 9
3 4 4
3 5 10
3 6 12
5 6 6
5 7 14
7 8 3
2 8 7 9 4 10 12 6 14 3
'''
