from datetime import datetime, time, timedelta
def create_date(timetable):
    timestamp = []
    for i in range(len(timetable)):
        a = timetable[i].split(":")
        timestamp.append(datetime(2020, 8, 8, int(a[0]), int(a[1])))
    return timestamp

def solution(n, t, m, timetable):
    answer = ''
    timestamp = create_date(timetable)
    print(timestamp)
    timestamp.sort()
    print(timestamp)
    start = datetime(2020, 8, 8, 9, 0)
    if n * m > len(timestamp):
        if timestamp[len(timestamp) - 1] < start:
            return '09:00'
        elif m >= len(timestamp):
            ans = str((start + timedelta(minutes=(n - 1) * t)).time()).split(':')
            return ans[0] + ':' + ans[1]
        else:
            ans = timestamp[len(timestamp) - 1] - timedelta(minutes=1)
            an = str(ans.time()).split(':')
            return an[0] + ':' + an[1]
    elif n * m <= len(timestamp):
        if timestamp[len(timestamp) - 1] > start + timedelta(minutes= (n - 1) * t):
            ans = str((start + timedelta(minutes= (n - 1) * t)).time()).split(':')
            return ans[0] + ':' + ans[1]
        ans = timestamp[len(timestamp) - 1] - timedelta(minutes=1)
        an = str(ans.time()).split(":")
        return an[0] + ':' + an[1]
    return answer

if __name__ == '__main__':
    timetable = ['23:59']
    print(solution(1,1,1,timetable))