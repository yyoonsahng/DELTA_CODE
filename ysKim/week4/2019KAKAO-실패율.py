
def calculate(N, stages):
    succ = [0 for i in range(N)]
    ans = [0 for i in range(N)]
    result = []
    for i in range(len(stages)):
        if stages[i] == N + 1:
            for i in range(len(ans)):
                ans[i] += 1
                succ[i] += 1
            continue
        for j in range(stages[i]):  # chal
            ans[j] += 1
            if j != stages[i] - 1:
                succ[j] += 1
    for i in range(N):
        if ans[i] == 0:
            result.append(0)
            continue
        result.append(float(ans[i] - succ[i]) / ans[i])
    return result

def solution(N, stages):
    answer = []
    ans = calculate(N, stages)
    for i in range(len(ans)):
        answer.append(ans.index(max(ans)) + 1)
        ans[ans.index(max(ans))] = -1
    return answer
'''


def solution(N, stages):
    answer = []
    successCount = [0 for i in range(0, N)]
    tryCount = [0 for i in range(0, N)]
    failCount = [0 for i in range(0, N)]
    sumFailPeople = 0
    totalPeople = len(stages)
    for stage in range(1, N + 1):
        failCount[stage - 1] = stages.count(stage)
        successCount[stage - 1] = totalPeople - failCount[stage - 1] - sumFailPeople
        tryCount[stage - 1] = successCount[stage - 1] + failCount[stage - 1]
        sumFailPeople += failCount[stage - 1]
    result = [{'idx': idx, 'fail': f, 'try': tryCount[idx]} for idx, f in enumerate(failCount)]
    failRatio = []
    for i in result:
        value = 0
        if i['fail'] != 0:
            value = i['fail'] / i['try']
        failRatio.append({'idx': i['idx'], 'value': value})
    answer = [v['idx'] + 1 for v in sorted(failRatio, key=lambda x: x['value'], reverse=True)]
    return answer
'''
'''
    sumCount = [0 for i in range(N)]
    for i in range(N + 1):
        succ[i] = stages.count(i)
        if i > 0:
            succ[i] += succ[i - 1]
            sumCount[i] += sumCount[i - 1]
        sumCount[i] += succ[i]
        ans[i] = stages.count(i + 1) + sumCount[i]
    for i in range(stages.count(N + 1)):
        for i in range(len(ans)):
            ans[i] += 1
            succ[i] += 1
    return result
'''
if __name__ == '__main__':
    l = [2, 1, 2, 6, 2, 4, 3, 3]
    N = 5
    print(solution(N, l))
