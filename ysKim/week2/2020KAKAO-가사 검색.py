def ques_num(queries):
    q = []
    for i in queries:
        start = 0
        flag = False
        count = 0
        for j in range(len(i)):
            if i[j] == '?' and flag == False:
                flag = True
                start = j
            elif i[j] == '?' and flag == True:
                count += 1
        q.append([start, start + count])
    return q

def solution(words, queries):
    answer = []
    ques = ques_num(queries)
    available = av(words, queries)
    answer = av2(words, queries, available, ques)
    return answer

def av(words, queries):
    available = []
    for i in range(len(queries)):
        av1 = []
        for j in range(len(words)):
            if len(words[j]) == len(queries[i]):
                av1.append(j)
        available.append(av1)
    return available

def av2(words, queries, available, q):
    ans = []
    for i in range(len(queries)):
        ans.append(0)
    for i in range(len(queries)):
        for j in range(len(available[i])):
            if q[i][0] == 0:
                a = queries[i][q[i][1] + 1:]
                if words[available[i][j]][q[i][1] + 1:] == a:
                    ans[i] += 1
            else:
                a = queries[i][:q[i][0]]
                if words[available[i][j]][:q[i][0]] == a:
                    ans[i] += 1
    return ans

if __name__ == '__main__':
    words = ["frodo", "front", "frost", "frozen", "frame", "kakao"]
    queries = ["fro??", "????o", "fr???", "fro???", "pro?"]
    print(solution(words, queries))


