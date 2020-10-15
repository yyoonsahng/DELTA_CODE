import sys

p1 = [[0, 1, 0], [1, 1, 1], [0, 1, 0]]
p2 = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
p3 = [[0, 0, 0], [1, 1, 1], [0, 0, 0]]
p4 = [[0, 1, 0], [0, 1, 1], [0, 0, 0]]
p5 = [[0, 0, 0], [0, 1, 1], [0, 1, 0]]
p6 = [[0, 0, 0], [1, 1, 0], [0, 1, 0]]
p7 = [[0, 1, 0], [1, 1, 0], [0, 0, 0]]
p = [p1, p2, p3, p4, p5, p6, p7]
is_checked = []
r_time = 0


def connected(a, b, dir):
    if dir == 0:  # 오른쪽
        if p[a - 1][1][2] == 1 and p[b - 1][1][0] == 1:
            return True
        else:
            return False
    elif dir == 1:  # 왼쪽
        if p[a - 1][1][0] == 1 and p[b - 1][1][2] == 1:
            return True
        else:
            return False
    elif dir == 2:  # 위
        if p[a - 1][0][1] == 1 and p[b - 1][2][1] == 1:
            return True
        else:
            return False
    else:  # 아래
        if p[a - 1][2][1] == 1 and p[b - 1][0][1] == 1:
            return True
        else:
            return False


def move(map, row, col, dir, time):
    # time 고려해줘야함!
    global r_time
    global is_checked
    if dir == 0:
        if col + 1 < len(map[0]):
            if map[row][col + 1] != 0 and connected(map[row][col], map[row][col + 1], dir):
                is_checked[row][col + 1] = 1
                if time == r_time:
                    return 0
                else:
                    l = [0, 2, 3]
                    for d in l:
                        move(map, row, col + 1, d, time + 1)

    elif dir == 1:
        if col - 1 >= 0:
            if map[row][col - 1] != 0 and connected(map[row][col], map[row][col - 1], dir):
                is_checked[row][col - 1] = 1
                if time >= r_time:
                    return 0
                else:
                    l = [1, 2, 3]
                    for d in l:
                        move(map, row, col - 1, d, time + 1)
    elif dir == 2:
        if row - 1 >= 0:
            if map[row - 1][col] != 0 and connected(map[row][col], map[row - 1][col], dir):
                is_checked[row - 1][col] = 1
                if time == r_time:
                    return 0
                else:
                    l = [0, 1, 2]
                    for d in l:
                        move(map, row - 1, col, d, time + 1)
    else:
        if row + 1 < len(map):
            if map[row + 1][col] != 0 and connected(map[row][col], map[row + 1][col], dir):
                is_checked[row + 1][col] = 1
                if time == r_time:
                    return 0
                else:
                    l = [0, 1, 3]
                    for d in l:
                        move(map, row + 1, col, d, time + 1)


def solution(test_case, info, map):
    global is_checked
    global r_time
    is_checked = [[0 for j in range(len(map[0]))] for i in range(len(map))]
    answer = 0
    r_time = info[4]
    time = 1
    hole = info[2:4]
    is_checked[hole[0]][hole[1]] = 1
    if time == r_time:
        print('#' + str(test_case) + ' 1')
        return 0
    for j in range(4):
        move(map, hole[0], hole[1], j, time + 1)
    for i in range(len(is_checked)):
        answer += sum(is_checked[i])
    print(is_checked)
    print('#' + str(test_case) + ' ' + str(answer))


if __name__ == '__main__':
    sys.stdin = open("sample_input.txt", "r")
    T = int(input())
    # 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    for test_case in range(1, T + 1):
        info = []
        h = input()
        info = h.split(' ')

        for i in range(len(info)):
            info[i] = int(info[i])
        map = []
        for i in range(info[0]):
            row = []
            r = input()
            for j in range(len(r)):
                if r[j] != ' ':
                    row.append(int(r[j]))
            map.append(row)
        solution(test_case, info, map)
