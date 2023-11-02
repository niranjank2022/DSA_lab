from collections import defaultdict, deque

print("\n" * 50)

n = int(input("Enter no. of edges: "))

print("Enter edges of the graph: ")

graph = defaultdict(list)
visited = set()
last = []

for i in range(n):
    x, y = list(map(int, input().split()))
    graph[x].append(y)
    graph[y].append(x)

start = int(input("Enter starting edge: "))

def dfs(start):
    
    if start not in visited:
        print(start, end=' ')
        visited.add(start)
        last.append(start)
        for elem in graph[start]:
            if elem not in visited:
                dfs(elem)

def bfs(start):
    cvisited = set()
    queue = deque()
    queue.append(start)

    while queue:
        curr = queue.popleft()
        if curr not in cvisited:
            cvisited.add(curr)
            print(curr, end=" ")
            for e in graph[curr]:
                if e not in cvisited:
                    queue.append(e)                


print("DFS of the graph: ", end=" ")
dfs(start)

print()
print("BFS of the graph: ", end=" ")
bfs(start)
