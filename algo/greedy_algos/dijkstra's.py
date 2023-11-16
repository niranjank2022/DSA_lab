INF = float("inf")


def minDistance(dist, visited):
    val = INF
    idx = -1
    for i in range(len(dist)):
        if not visited[i] and dist[i] <= val:
            val = dist[i]
            idx = i

    return idx


def dijkstra(graph, src):
    n = len(graph)
    dist = [INF] * n
    visited = [False] * n

    dist[src] = 0
    for i in range(n - 1):

        u = minDistance(dist, visited)
        visited[u] = True
        if u == INF:
            continue

        for v in range(n):
            if not visited[v] and graph[u][v] != 0 and dist[v] > dist[u] + graph[u][v]:
                dist[v] = dist[u] + graph[u][v]

    print("Distance of nodes from the source", src)
    [print(f"{src} -> {dist[i]}") for i in range(n)]


if __name__ == '__main__':
    n = int(input('''Enter no. of edges: '''))
    v = int(input('''Enter no. of vertices: '''))
    print("Enter edges with weights: ")
    edges = [list(map(int, input().split())) for i in range(n)]
    graph = [[0] * v for _ in range(v)]
    for u, v, w in edges:
        graph[u][v] = w
        graph[v][u] = w

    dijkstra(graph, 0)
