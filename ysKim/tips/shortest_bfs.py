
def bfs(start, distance, parent, adj):
    distance = [-1 for i in range(len(adj))]
    parent = [-1 for i in range(len(adj))]

    q = []
    distance[start] = 0
    parent[start] = start
    q.append(start)
    while not len(q) == 0:
        here = q[0]
        del q[0]

        for i in range(len(adj[here])):
            there = adj[here][i]

            if distance[there] == -1:
                q.append(there)
                distance[there] = distance[here] + 1
                parent[there] = here

    print(distance)
    print(parent)
    return distance, parent

def shortestPath(v, parent):
    path = [v]
    while parent[v] != v:
        v = parent[v]
        path.append(v)
    path.reverse()
    return path

if __name__ == '__main__':
    node_num = int(input())
    population = input()
    p = population.split()
    p = [int(i) for i in p]
    # graph = [[0 for j in range(node_num)] for i in range(node_num)]
    graph = [[] for i in range(node_num)]
    for i in range(node_num):
        a = input()
        s = a.split()
        for j in range(1, int(s[0]) + 1):
            graph[i].append(int(s[j]) - 1)
            graph[int(s[j]) - 1].append(i)
    parent = []
    distance = []
    distance, parent = bfs(0, distance, parent, graph)
    print(shortestPath(5, parent))# 0에서 5까지의 shortest path
