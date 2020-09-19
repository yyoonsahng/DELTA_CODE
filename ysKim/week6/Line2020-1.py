

def solution(boxes):
    box = []
    for i in boxes:
        box.extend(i)
    box.sort()
    count = 0
    i = 0
    while len(box) != 0:
        if len(box) == 1:
            count += 1
            del box[0]
        elif box[0] == box[1]:
            del box[0]
            del box[0]
        else:
            count += 1
            del box[0]
    answer = count // 2
    return answer


if __name__ == '__main__':
    boxes = [[1, 2], [2, 1], [3, 3], [4, 5], [5, 6], [7, 8]]
    print(solution(boxes))
