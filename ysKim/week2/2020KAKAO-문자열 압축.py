def count_t(s, sc):

    co = 0
    st = s[:sc]
    co_1 = 1
    rest = len(s) % sc
    for i in range(int(len(s) / sc)):
        if s[sc * (i + 1) :sc * (i + 2)] == st:
            co_1 += 1
        else:
            st = s[sc * (i + 1) :sc * (i + 2)]
            if co_1 != 1:
                co += int(len(str(co_1)))
            co += sc
            co_1 = 1
    return co + rest
def count(s):
    ans = 1000
    for i in range(1, int(len(s) / 2) + 2):
        ans = min(ans, count_t(s, i))
    return ans
def solution(s):
    answer = 0
    answer = count(s)
    return answer
if __name__ == '__main__':
    stt = ""
    for i in range(250):
        stt += "abcd"
    print(stt)
    print(solution(stt))