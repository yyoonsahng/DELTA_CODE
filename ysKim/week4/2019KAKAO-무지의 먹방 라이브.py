def solution(food_times, k):
    ans = 0
    l_sort = [x for x in range(len(food_times))]
    l_sort = [x for _, x in sorted(zip(food_times, l_sort))] # food_times를 기준으로 l_sort 정렬
    food_times.sort()
    #print(l_sort)
    while k != 0:
        if k - len(food_times) > 0:
            k -= len(food_times)
            for j in range(len(food_times)):
                food_times[j] -= 1
                if food_times[j] == 0:
                    del food_times[j]
                    del l_sort[j]
        elif k - len(food_times) == 0:
            for j in range(len(food_times)):
                food_times[j] -= 1
                if food_times[j] == 0:
                    del food_times[j]
                    del l_sort[j]
            ans = min(l_sort) + 1
            break
        else:
            i = 0
            f = 0
            while i != k:
                try:
                    if l_sort.index(f):
                        i += 1
                        f += 1
                except:
                    f += 1
            ans = f + 1
            break
    return ans
if __name__ == '__main__':
    print(solution([1, 1, 1, 1], 4))


'''
import heapq
def solution(food_times, k):
    # (음식 크기, 원판에서의 위치) 로 food_times 재정의
    food_times = [(food, idx) for idx, food in enumerate(food_times, 1)]
    # heapify. 음식 크기가 작은 순으로 뽑아낸다.
    heapq.heapify(food_times)
    
    # 가장 크기 작은 음식
    small_food = food_times[0][0]
    prev_food = 0
    # 작은 음식을 완전히 소비하기 위해 원판을 완주할 수 있는 경우
    while k - ((small_food - prev_food) * len(food_times)) >= 0:
        # 해당 음식을 완전히 소비하는 데 걸린 시간만큼 뺀다
        k -= (small_food - prev_food) * len(food_times)
        prev_food, index = heapq.heappop(food_times)
        if not food_times:
            return -1
        small_food = food_times[0][0]
    food_times = sorted(food_times, key = lambda x: x[1])
    # print(food_times)
    return food_times[k % len(food_times)][1]

'''