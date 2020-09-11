from itertools import permutations
import copy
def solution(n, m, coin, count_num):
    flag = True
    for t in range(n + m + 1):
        all = ([list(k) for k in permutations([j for j in range(n + m)], t)])
        for per in all:
            coin1 = copy.deepcopy(coin)
            for i in per:
                if i < n:
                    for j in range(m):
                        if coin1[i][j] == 0:
                            coin1[i][j] = 1
                        else:
                            coin1[i][j] = 0
                else:
                    for j in range(n):
                        if coin1[j][i - n] == 0:
                            coin1[j][i - n] = 1
                        else:
                            coin1[j][i - n] = 0
            flag = True
            for i in range(n):
                if coin1[i].count(1) % 2 != 0:
                    flag = False
            for j in range(m):
                col_c = [i[j] for i in coin1]
                if col_c.count(1) % 2 != 0:
                    flag = False
            if flag:
                return len(per)
    if not flag:
        return -1

if __name__ == '__main__':
    n, m = map(int, input().split())
    coin = [[0 for a in range(m)] for b in range(n)]
    for i in range(n):
        c = input()
        for j in range(m):
            coin[i][m - 1 - j] = int(c[m - 1 - j])
    print(solution(n, m, coin, 0))