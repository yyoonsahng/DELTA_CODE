def solution(dartResult):
    answer = 0
    result = []
    ind = 0
    for i in range(len(dartResult)):
        if dartResult[i].isdigit():
            if len(result) > 0 and int(result[len(result) - 1]) == 10 and dartResult[i] == '0':
                continue
            if dartResult[i + 1].isdigit():
                result.append(10)
                ind = len(result) - 1
                continue
            result.append(dartResult[i])
            ind = len(result) - 1
        elif dartResult[i].isalpha():
            print(dartResult[i])
            if dartResult[i] == 'D':
                result[ind] = int(result[ind]) ** 2
            elif dartResult[i] == 'T':
                result[ind] = int(result[ind]) ** 3
        else:
            if dartResult[i] == '*':
                if ind == 0:
                    result[ind] = int(result[ind]) * 2
                else:
                    result[ind - 1] = int(result[ind - 1]) * 2
                    result[ind] = int(result[ind]) * 2
            else:
                result[ind] = int(result[ind]) * (-1)
    print(result)
    for j in range(len(result)):
        answer = answer + int(result[j])
    return answer
if __name__ == '__main__':
    print(solution('10T10S1T*'))