import copy
def make_padding(key, lock):
    nlock = []
    for i in range(len(lock[0]) + (key - 1) * 2):
        l = []
        for j in range(len(lock[0]) + (key - 1) * 2):
            l.append(2)
        nlock.append(l)
    for i in range(key - 1, len(nlock) - (key - 1)):
        for j in range(key - 1, len(nlock) - (key - 1)):
            nlock[i][j] = lock[i - (key - 1)][j - (key - 1)]
    return nlock


def getlock(lock, key):
    a = []
    for i in range(len(key) - 1, len(lock) - (len(key) - 1)):
        t = []
        for j in range(len(key) - 1, len(lock) - (len(key) - 1)):
            t.append(lock[i][j])
        a.append(t)
    return a
def check_key(lock, key):
    check_a = []
    for i in range(len(key) - 1, len(lock) - (len(key) - 1)):
        c = []
        for j in range(len(key) - 1, len(lock) - (len(key) - 1)):
            c.append(1)
        check_a.append(c)
    ans = False
    for i in range(4):
        for j in range(len(lock) - len(key) + 1):
            for k in range(len(lock) - len(key) + 1):
                lock_1 = calculate(key, lock, j, k)
                part_lock = getlock(lock_1, key)
                #print(part_lock)
                if part_lock == check_a:
                    return True
        rotate(key)
    return ans
def calculate(key, lock, row, col):
    lock_1 = copy.deepcopy(lock)
    for i in range(len(key)):
        for j in range(len(key)):
            lock_1[row + i][col + j] = int(str(bin(lock[row + i][col + j] ^ key[i][j])), 2)
    return lock_1
def rotate(key):
    c_key = copy.deepcopy(key)
    for i in range(len(key[0])):
        a = [j[i] for j in c_key]
        key[i] = a
        key[i].reverse()

def solution(key, lock):
    answer = True
    lock = make_padding(len(key[0]), lock)
    #print(lock)
    answer = check_key(lock, key)
    return answer

if __name__ == '__main__':
    key = [[0, 0, 0], [1, 0, 0], [0, 1, 1]]
    lock = [[1, 1, 1], [1, 1, 0], [1, 0, 1]]
    #print(int(str(bin(1 ^ 0)), 2))
    print(solution(key, lock))

