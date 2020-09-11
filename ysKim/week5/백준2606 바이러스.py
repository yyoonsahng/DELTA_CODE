import sys
infect = set()
def check_infected(g, check_int):
    for i in range(len(g)):
        if g[check_int][i] == 1:
            if {i}.issubset(infect):
                continue
            infect.add(i)
            check_infected(g, i)

def solution(g):
    check_infected(g, 0)

if __name__ == '__main__':
    c_num = int(input())
    pair = int(input())
    g = [[0 for j in range(c_num)] for i in range(c_num)]
    for i in range(pair):
        pair1, pair2 = map(int, input().split())
        g[pair1 - 1][pair2 - 1] = 1
        g[pair2 - 1][pair1 - 1] = 1
    if c_num == 1:
        print(0)
        sys.exit(1)
    solution(g)
    print(len(infect) - 1)