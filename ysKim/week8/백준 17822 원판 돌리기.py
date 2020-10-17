import copy
from decimal import Decimal

def rotate(circle, T):
    target = []
    for i in range(1, len(circle) + 1):
        if i % T[0] == 0:
            target.append(i - 1)
    for i in range(len(target)):
        if T[1] == 0:
            for j in range(T[2]):
                circle[target[i]].insert(0, circle[target[i]][len(circle[target[i]]) - 1])
                del circle[target[i]][len(circle[target[i]]) - 1]
        else:
            for j in range(T[2]):
                circle[target[i]].append(circle[target[i]][0])
                del circle[target[i]][0]

def delete_num(circle, i):
    for j in range(len(circle)):
        for k in range(len(circle[j])):
            value = circle[j][k][0]
            del_time = circle[j][k][1]
            n = k + 1
            p = k - 1
            if k == 0:
                p = len(circle[j]) - 1
            if k == len(circle[j]) - 1:
                n = 0
            if value == circle[j][n][0] and k != len(circle[j]):
                is_c = False
                if del_time == -1 and circle[j][n][1] == -1:
                    is_c = True
                elif (del_time == i and circle[j][n][1] == -1) or (del_time == -1 and circle[j][n][1] == i):
                    is_c = True
                if is_c == True:
                    circle[j][k][1] = i
                    circle[j][n][1] = i
            elif value == circle[j][p][0] and k != 0:
                is_c = False
                if del_time == -1 and circle[j][p][1] == -1:
                    is_c = True
                elif (del_time == i and circle[j][p][1] == -1) or (del_time == -1 and circle[j][p][1] == i):
                    is_c = True
                if is_c == True:
                    circle[j][k][1] = i
                    circle[j][p][1] = i
            p = j - 1
            n = j + 1
            if j == 0:
                p = j
            if j == len(circle) - 1:
                n = j
            if value == circle[n][k][0] and j != len(circle) - 1:
                is_c = False
                if del_time == -1 and circle[n][k][1] == -1:
                    is_c = True
                elif (del_time == i and circle[n][k][1] == -1) or (del_time == -1 and circle[n][k][1] == i):
                    is_c = True
                if is_c == True:
                    circle[j][k][1] = i
                    circle[n][k][1] = i
            elif value == circle[p][k][0] and j != 0:
                is_c = False
                if del_time == -1 and circle[p][k][1] == -1:
                    is_c = True
                elif (del_time == i and circle[p][k][1] == -1) or (del_time == -1 and circle[p][k][1] == i):
                    is_c = True
                if is_c == True:
                    circle[j][k][1] = i
                    circle[p][k][1] = i


def solution(info, circle, T):
    answer = 0
    for i in range(len(T)):
        rotate(circle, T[i])
        circle2 = copy.deepcopy(circle)
        delete_num(circle, i)
        if circle == circle2:
            count = 0
            sum = 0
            for j in range(len(circle)):
                for k in range(len(circle[j])):
                    if circle[j][k][1] == -1:
                        count += 1
                        sum += circle[j][k][0]
            if count == 0:
                return 0
            avg = Decimal(sum / count)
            for j in range(len(circle)):
                for k in range(len(circle[j])):
                    if circle[j][k][0] < avg:
                        circle[j][k][0] += 1
                    elif circle[j][k][0] > avg:
                        circle[j][k][0] -= 1
    for j in range(len(circle)):
        for k in range(len(circle[j])):
            if circle[j][k][1] == -1:
                answer += circle[j][k][0]
    return answer
if __name__ == '__main__':
    h = input()
    circle = []
    T = []
    info = h.split(' ')
    for i in range(len(info)):
        info[i] = int(info[i])

    for i in range(info[0]):
        b = []
        h = input()
        t = h.split(' ')
        for j in range(len(t)):
            a = []
            t[j] = int(t[j])
            a.append(t[j])
            a.append(-1)
            b.append(a)
        circle.append(b)
    for i in range(info[2]):
        h = input()
        t = h.split(' ')
        for j in range(len(t)):
            t[j] = int(t[j])
        T.append(t)
    print(solution(info, circle, T))
