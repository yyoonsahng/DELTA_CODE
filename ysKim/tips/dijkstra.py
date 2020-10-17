import sys

def dijkstra(K, V, graph):
    INF = sys.maxsize
    # s는 해당 노드를 방문 했는지 여부를 저장하는 변수이다
    s = [False] * V
    # d는 memoization을 위한 array이다. d[i]는 정점 K에서 i까지 가는 최소한의 거리가 저장되어 있다.
    d = [INF] * V
    d[K - 1] = 0

    while True:
        m = INF
        N = -1

        # 방문하지 않은 노드 중 d값이 가장 작은 값을 선택해 그 노드의 번호를 N에 저장한다.
        # 즉, 방문하지 않은 노드 중 K 정점과 가장 가까운 노드를 선택한다.
        for j in range(V):
            if not s[j] and m > d[j]:
                m = d[j]
                N = j

        # 방문하지 않은 노드 중 현재 K 정점과 가장 가까운 노드와의 거리가 INF 라는 뜻은
        # 방문하지 않은 남아있는 모든 노드가 A에서 도달할 수 없는 노드라는 의미이므로 반복문을 빠져나간다.
        if m == INF:
            break

        # N번 노드를 '방문'한다.
        # '방문'한다는 의미는 모든 노드를 탐색하며 N번 노드를 통해서 가면 더 빨리 갈 수 있는 노드가 있는지 확인하고,
        # 더 빨리 갈 수 있다면 해당 노드(노드의 번호 j라고 하자)의 d[j]를 업데이트 해준다.
        s[N] = True

        for j in range(V):
            if s[j]: continue
            via = d[N] + graph[N][j]
            if d[j] > via:
                d[j] = via

    return d

if __name__ == "__main__":
    node_num = int(input())
    population = input()

    graph = [[sys.maxsize for j in range(node_num)] for i in range(node_num)]
    for i in range(node_num):
        a = input()
        s = a.split()
        for j in range(1, int(s[0]) + 1):
            graph[i][int(s[j]) - 1] = 1
            graph[int(s[j]) - 1][i] = 1
    #각 Node로부터 K까지의 최단거리를 구하고싶음 - 1부터 시작한다.
    K = int(input())


    for d in dijkstra(K, node_num, graph):
        print(d if d != sys.maxsize else "INF")