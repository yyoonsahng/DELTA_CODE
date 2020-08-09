def solution(n, arr1, arr2):
    answer = []
    for i in range(n):
        a = bin(arr1[i] | arr2[i])
        a1 = a.split("b")
        a1 = a1[1]
        if len(a1) < n:
            for j in range(n - len(a1)):
                a1 = '0' + a1
        answer.append(a1)
    for i in range(n):
        ans = ''
        for j in range(len(str(answer[i]))):
            if answer[i][j] == '1':
                ans = ans + '#'
            else:
                ans = ans + ' '
        answer[i] = ans
    return answer
if __name__ == '__main__':
    arr1 = [9, 20, 28, 18, 11]
    arr2 = [30, 1, 21, 17, 28]
    print(solution(5, arr1, arr2))