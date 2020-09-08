def solution():
    ans = 0
    a = int(input())
    b = input()
    build = b.split()
    for i in range(len(build)):
        build[i] = int(build[i])
    print(build)
    for i in range(2, len(build) - 2):
        left = max(build[i - 2: i])
        right = max(build[i + 1: i + 3])
        maximum = max(right, left)
        if build[i] > maximum:
            ans += build[i] - maximum
    print("#{} {}".format(i+1, ans))


if __name__ == '__main__':
    #build = [0, 0, 3, 5, 2, 4, 9, 0, 6, 4, 0, 6, 0, 0]
    for i in range(10):
        solution()