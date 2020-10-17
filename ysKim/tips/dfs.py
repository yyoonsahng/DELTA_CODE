
visited = []
def dfs(here, adj):
    print(here)
    visited[here] = True
    for i in range(len(adj[here])):
        there = adj[here][i]

        if not visited[there]:
            dfs(there, adj)


def dfsAll(adj):
    global visited
    visited = [False for i in range(len(adj))]
    for i in range(len(adj)):
        if not visited[i]:
            dfs(i, adj)


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
    print(dfsAll(graph))
