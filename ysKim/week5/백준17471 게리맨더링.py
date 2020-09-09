import copy
from itertools import combinations
ss = set()


def check_c(param, line, graph):
    for i in range(len(graph)):
        if line.count(i) == 0:
            continue
        if graph[param][i] == 1:
            if {i}.issubset(ss):
                continue
            ss.add(i)
            check_c(i, line, graph)


def isComponent(line, graph):
    if len(line) == 1:
        return True
    global ss
    g = copy.deepcopy(graph)
    ss = set()
    check_c(line[0], line, g)
    if len(ss) == len(line):
        return True
    else:
        return False


def solution(node_num, popul, graph):
    ans = 1000
    line = [i for i in range(node_num)]
    line = [x for _, x in sorted(zip(popul, line))]
    popul.sort()
    dic = dict()
    for i in range(len(line)):
        dic[line[i]] = popul[i]
    for t in range(1, int(len(popul) / 2) + 1):
        all = ([list(k) for k in combinations(line, t)])
        for comb in all:
            l2 = copy.deepcopy(line)
            sum_comb = 0
            for i in comb:
                sum_comb += dic[i]
                if l2.index(i) > -1:
                   del l2[l2.index(i)]
            if isComponent(comb, graph) and isComponent(l2, graph):
                sum_l2 = 0
                for j in l2:
                    sum_l2 += dic[j]
                ans = min(ans, abs(sum_comb - sum_l2))
                if ans == 0:
                    return ans
    if ans == 1000:
        return -1
    return ans

if __name__ == '__main__':
    node_num = int(input())
    population = input()
    p = population.split()
    p = [int(i) for i in p]
    graph = [[0 for j in range(node_num)]for i in range(node_num)]
    for i in range(node_num):
        a = input()
        s = a.split()
        for j in range(1, int(s[0]) + 1):
            graph[i][int(s[j]) - 1] = 1
            graph[int(s[j]) - 1][i] = 1
    print(solution(node_num, p, graph))
