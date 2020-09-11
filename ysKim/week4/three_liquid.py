import copy
def solution(num, arr):
    arr = arr.split()
    m = 1000000000
    ans = []
    for i in range(num):
        arr[i] = int(arr[i])
    for i in range(len(arr)):
        for j in range(i + 1, len(arr)):
            if i == j:
                continue
            mix2 = arr[i] + arr[j]
            arr2 = copy.deepcopy(arr)
            arr2[i] = 1000000000
            arr2[j] = 1000000000
            k = min(arr2, key=lambda x: abs(x - -mix2))
            result = mix2 + k
            if result < 0:
                if -result < m:
                    m = -result
                    ans = [arr[i], arr[j], k]
            elif result == 0:
                return [arr[i], arr[j], k]
            else:
                if result < m:
                    m = -result
                    ans = [arr[i], arr[j], k]
    return ans
if __name__ == '__main__':
    a = int(input())
    b = input()
    print(solution(a, b))