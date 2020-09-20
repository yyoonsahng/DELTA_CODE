
def solution(ball, order):
    answer = []
    edge = [ball[0], ball[len(ball) - 1]]
    q = []
    for i in range(len(order)):
        j = 0
        while len(q) != 0:
            if edge.count(q[j]) == 0:
                j += 1
                if j == len(q):
                    break
            else:
                ind = edge.index(q[j])
                if ind == 0:
                    answer.append(ball[0])
                    del q[j]
                    del ball[0]
                    edge[0] = ball[0]
                else:
                    answer.append(ball[len(ball) - 1])
                    del q[j]
                    del ball[len(ball) - 1]
                    edge[1] = ball[len(ball) - 1]
                j = 0
        if edge.count(order[i]) == 0:
            q.append(order[i])
        else:
            ind = edge.index(order[i])
            if ind == 0:
                answer.append(ball[0])
                del ball[0]
                if len(ball) != 0:
                    edge[0] = ball[0]
            else:
                answer.append(ball[len(ball) - 1])
                del ball[len(ball) - 1]
                if len(ball) != 0:
                    edge[1] = ball[len(ball) - 1]
    return answer

if __name__ == '__main__':
    ball = [11, 2, 9, 13, 24]
    order = [9, 2, 13, 24, 11]
    print(solution(ball, order))