

def bfs(start, adj):
    discovered = [False for i in range(len(adj))]
    q = []
    order = []
    discovered[start] = True
    q.append(start)
    while not len(q) == 0:
        here = q[0]
        del q[0]
        order.append(here)
        for i in range(len(adj[here])):
            there = adj[here][i]

            if not discovered[there]:
                q.append(there)
                discovered[there] = True
    return order

if __name__ == '__main__':
    node_num = int(input())
    population = input()
    p = population.split()
    p = [int(i) for i in p]
    #graph = [[0 for j in range(node_num)] for i in range(node_num)]
    graph = [[] for i in range(node_num)]
    for i in range(node_num):
        a = input()
        s = a.split()
        for j in range(1, int(s[0]) + 1):
            graph[i].append(int(s[j]) - 1)
            graph[int(s[j]) - 1].append(i)
    print(bfs(0, graph))
