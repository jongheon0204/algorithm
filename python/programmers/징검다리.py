# 이분탐색 : 징검다리 Level 4
# https://programmers.co.kr/learn/courses/30/lessons/43236

# 바위를 최대 n개 제거한 후 거리의 최솟값이 mid라 가정했을 경우 올바르게 나오는지 검사
def binarySearch(rocks, left, right, n):
    # 범위 값이 잘못 되는 경우 0을 리턴
    if left > right:
        return 0
    mid = (left + right) // 2

    # 제거할 바위의 개수를 세준다
    cnt = 0
    isUse = [False for i in range(len(rocks))]
    for i in range(len(rocks) - 1):
        if isUse[i]:
            continue
        for j in range(i+1, len(rocks) - 1):
            # 바위 사이의 거리가 mid 보다 작다면 j번째 바위를 제거해 주어야 한다
            if rocks[j] - rocks[i] < mid:
                cnt += 1
                isUse[j] = True
            else:
                break

    if cnt > n:
        return binarySearch(rocks, left, mid - 1, n)
    else:
        return max(mid, binarySearch(rocks, mid + 1, right, n))

def solution(distance, rocks, n):
    # 징검다리에 시작 지점과 도착 지점의 정보를 추가한다
    rocks.append(distance)
    rocks.append(0)
    # 징검다리에 있는 바위의 좌표를 기준으로 정렬
    rocks.sort()
    # [정답, 제거할 수 있는 바위의 개수]
    # 이분 탐색을 통해 문제를 해결할 수 있다
    return binarySearch(rocks, 0, distance, n)