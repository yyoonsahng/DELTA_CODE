from itertools import combinations
from itertools import permutations

def Binary():
    #이진법 사용
    a = bin(10)
    b = []
    b.extend(a)
    print(b)
    a = [0, 1, 2, 3]
    b = combinations(a, 3)
    c = []
    for i in b:
        c.append(i)

def List():
    #list 선언
    list1 = [1, 2, 3, 4]

    #list에 항목 추가
    list1.append(1)
    #list1.extend(1)
    list1.insert(2, 0)
    print(list1)
    #append와 extend의 차이
    list2 = []
    list.clear(list1)
    y = [1, 2, 3, 4]
    list1.append(y)#[[1, 2, 3, 4]]
    list2.extend(y)#[1, 2, 3, 4]
    y = 'string'
    list1.append(y)#[[1, 2, 3, 4], 'string']
    list2.extend(y)#[1, 2, 3, 4, 's', 't', 'r', 'i', 'n', 'g']

    #append는 통째로 집어넣고 extend 가장 바깥쪽 iterable의 모든 항목을 집어넣는다.


    list1.clear()
    list1.extend([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19])

    #sorting
    list1.sort() # 기본
    #d = sorted(list1, key=lambda x: (x[0], x[1]))#0번 인덱스를 기준으로 먼저 sorting후 1번 인덱스를 기준으로 다시 sorting한다.
    a = [1, 2, 3, 4]
    b = [7, 5, 4, 9]
    line = [x for _, x in sorted(zip(b, a))]#b의 정렬 순서대로 a를 정렬한다.
    print(line)
    print(a)
    line = [x for _, x in sorted(zip(b, a))]
    #reverse
    list1.reverse()

    #split join
    t = 'hello world'
    list2 = t.split()#['hello', 'world']
    t = '#'.join(list2)#hello#world

    #slice step
    l1 = list1[:2]#0, 1번째 칸
    l2 = list1[5:15:3]# 5번째부터 14번까지 3칸씩 건너 뛰며 가져온

    #remove delete
    list1.remove(15) #list1에서 첫 15 지우기
    del list1[0] #list1에서 0번 인덱스 지우기

    #find, count, in
    a = list1.index(3) #3이 있는 위치 반환
    #만약 못찾으면 오류 반환, exception으로 처리 해줘야 할듯

    list1 = [1, 1, 2, 2]
    list1.count(1)#1의 개수 반환

    print(1 in list1) #list1에 1이 존재하는지 확


def Set():
    s1 = set([1, 2, 3])
    s2 = set('string')#집합엔 순서가 없음

    #교집합 구하기
    s3 = set([1, 4, 5])
    inter = s1 & s3
    #합집합 구하기
    s4 = set([4, 5, 6])
    un = s1 | s4
    #차집합(교집합을 빼는거랑 같음)
    diff = s1 - s3

    #add - 값 1개 추가
    s1.add(4)

    #update - 값 여러개 추가
    s1.update([5, 6, 7])
    print(s1)

    #remove - 값 제거
    s1.remove(7)

    #부분집합 확인
    s5 = set([2, 3])
    print(s5.issubset(s1))

    #부분집합의 반대 즉 포함하는지
    print(s1.issuperset(s5))

    #교집합이 없으면 True 있으면 False
    print(s1.isdisjoint(s3)) #False 반환
    print(s1.isdisjoint(s2)) #True 반

def Dict():
    d = {}

    #add
    d['a'] = 1
    print(d)

    #여러개 값 수정
    d = {'alice': [1, 2, 3], 'bob': 20, 'tony': 15, 'suzy': 30}
    d.update({'bob': 99, 'tony': 99, 'kim': 30})

    #조회
    print(d['alice'])
    print(d.get('bvbv'))#None 반

    #for문
    for key in d:
        print(key)
    print(d.keys())

    for val in d.values():
        print(val)
    print(list(d.values()))
    print(list(d.values()).index(30))

    print(d.items()) # key랑 value 다 가져옴 (list 형태로 저장 가능)
    #삭제
    del d['alice']

    d.__contains__('bob')
    #키값 확인
    print(d.__contains__('bob'))

    #list를 key로 하는 dictionary 생성
    l1 = [1, 2, 3, 4]
    l2 = 10
    d2 = dict.fromkeys(l1, l2) #key는 l1 value는 모두 10으로 초기화
    print(d2)

if __name__ == '__main__':
    Binary()
    List()
    print()
    Set()
    Dict()