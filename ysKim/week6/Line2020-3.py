
t = 1000
re = 0
def countP(n, l):
    global t
    count = 0
    save = n
    if n // 10 == 0:
        t = min(t, l)
        print(t)
        return l
    while n != 0:
        n //= 10
        count += 1
    for i in range(count - 1):
        m = 10
        for j in range(i):
            m *= 10
        a = save // m
        b = save % m
        k = a + b
        countP(k, l + 1)
    return t


def solution(n):
    answer = []
    ans = n
    answer = countP(ans, 0)
    return answer


if __name__ == '__main__':
    print(solution(73425))