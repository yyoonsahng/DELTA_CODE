from itertools import permutations
def solution(n, weak, dist):
    weak_length = len(weak)
    for i in range(weak_length):
        weak.append(weak[i] + n)

    # 투입할 수 있는 친구의 최댓값.
    # 점검 불가능한 경우를 상정해서 len(dist) + 1
    answer = len(dist) + 1
    for i in range(weak_length):
        # 2. 어디서부터 벽 점검을 시작할 것인지 결정
        start_point = [weak[j] for j in range(i, i + weak_length)]

        # 3. 벽 점검에 투입할 친구의 순서 정하기
        candidates = permutations(dist, len(dist))#순열 dist에서 dist길이만큼 뽑는 경우의

        # 4. 탐색
        for order in candidates:
            # 순서대로 출발.
            friend_idx, friend_count = 0, 1
            # 친구가 확인할 수 있는 최대 거리
            possible_check_length = start_point[0] + order[friend_idx]

            for idx in range(weak_length):
                # 확인할 수 있는 최대 거리를 넘어설 경우
                if start_point[idx] > possible_check_length:
                    # 다음 친구 투입
                    friend_count += 1
                    # 더 이상 투입할 친구가 없는 경우 break
                    if friend_count > len(order):
                        break
                    # 다음 친구 투입, 친구가 확인할 수 있는 최대 거리 업데이트
                    friend_idx += 1
                    possible_check_length = order[friend_idx] + start_point[idx]
            # 투입할 친구 최솟값 업데이트
            answer = min(answer, friend_count)
    if answer > len(dist):
        return -1
    return answer