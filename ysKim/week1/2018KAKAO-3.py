def solution(cacheSize, cities):
    answer = 0
    if cacheSize == 0:
        return len(cities) * 5
    cache = [0 for i in range(cacheSize)]
    lru = [-1 for i in range(cacheSize)]
    for i in range(len(cities)):
        try:#hit
            ind = cache.index(cities[i].lower())
            if ind >= 0:
                answer = answer + 1
                lru[ind] = 0
                for j in range(len(lru)):
                    if j == ind:
                        continue
                    else:
                        lru[j] = lru[j] + 1
        except:
            answer = answer + 5
            try:
                if cache.index(0) >=0:
                    c_ind = cache.index(0)
                    cache[c_ind] = cities[i].lower()
                    if c_ind > 0:
                        for i in range(c_ind):
                                lru[i] = lru[i] + 1
                    lru[c_ind] = 0
            except:
                try:
                    l_ind = lru.index(cacheSize - 1)
                    cache[l_ind] = cities[i].lower()
                    lru[l_ind] = 0
                    for j in range(len(lru)):
                        if j == l_ind:
                            continue
                        else:
                            lru[j] = lru[j] + 1
                except:
                    pass
    return answer
if __name__ == '__main__':
    cities = ['Jeju', 'Pangyo', 'Seoul', 'NewYork', 'LA', 'SanFrancisco', 'Seoul', 'Rome', 'Paris', 'Jeju', 'NewYork', 'Rome']
    print(solution(5, cities))