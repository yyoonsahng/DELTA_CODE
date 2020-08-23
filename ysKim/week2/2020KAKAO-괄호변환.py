def check_br(p):
    if len(p) == 0:
        return True
    elif p[0] == ')':
        return False
    l = []
    a = 0
    c = False
    for i in p:
        if i == '(':
            l.append(i)
            a = len(l)
        else:
            if a == 0:
                return False
            if l[a - 1] == '(':
                del l[a - 1]
                a -= 1
    if len(l) == 0:
        c = True
    return c
def check_bal(p):
    if len(p) == 0:
        return True
    f = 0
    b = 0
    for i in p:
        if i == '(':
            f +=1
        else:
            b+=1
    if f == b:
        return True
    else:
        return False
def make_corr(p):
    if check_br(p) == True:
        return p
    point = 0
    ans = ''
    for i in range(1, len(p) + 1):
        if check_bal(p[:i]) == True and check_bal(p[i:]) == True:
            if p[:i] == '':
                continue
            point = i
            break
    u = p[:point]
    v = p[point:]
    if check_br(u) == True:
        return u + make_corr(v)
    else:
        ans += '('
        ans += make_corr(v)
        ans += ')'
        u = u[1:len(u) - 1]
        for i in range(len(u)):
            if u[i] == '(':
                u = u[:i] + ')' + u[i + 1:]
            else:
                u = u[:i] + '(' + u[i + 1:]
        ans += u
    return ans
def solution(p):
    answer = ''
    if len(p) == 0:
        return ''
    answer = make_corr(p)
    return answer

if __name__ == '__main__':
    print(solution(")("))