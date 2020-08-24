import copy
def solution(record):
    user = {}
    c = {}
    result = copy.deepcopy(record)
    for i in range(len(record)):
        st = str.split(record[i])
        el = st[0]
        if el == 'Leave':
            uid = st[1]
        else:
            uid = st[1]
            name = st[2]
            c[uid] = name
        result[i] = el
        if uid in user:
            user[uid].extend([i])
        else:
            user[uid] = list()
            user[uid].extend([i])
    for key, value in user.items():
        for i in range(len(value)):
            if result[value[i]] == 'Enter':
                result[value[i]] = c[key] + '님이 들어왔습니다.'
            elif result[value[i]] == 'Leave':
                result[value[i]] = c[key] + '님이 나갔습니다.'
            else:
                del result[value[i]]
    return result

if __name__ == '__main__':
    l = ["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]
    print(solution(l))