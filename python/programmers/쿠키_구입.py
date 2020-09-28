# 2018 Summer/Winter Coding : 쿠키 구입 Level 4
# https://programmers.co.kr/learn/courses/30/lessons/49995

# 이분 탐색을 통해 O(nlogn)에 원하는 값을 찾는다
def binarySearch(sum, val):
    left = 0
    right = len(sum) - 1

    while left <= right:
        mid = (left + right) // 2
        if sum[mid] == val:
            return mid
        if sum[mid] < val:
            left = mid + 1
        else:
            right = mid - 1
    return -1

def solution(cookie):
    # 쿠키의 (0 ~ i) 개의 합을 저장할 리스트
    sum = [cookie[0]]
    for i in range(1, len(cookie)):
        sum.append(sum[-1] + cookie[i])
    # 모든 쿠키의 합 / 2 부터 1까지 검사를 하면서 검사
    for v in range(sum[-1] // 2, 1, -1):
        for i in range(len(cookie)):
            # i번째 바구니 부터 마지막 바구니 까지 쿠키의 합이 v * 2보다 작으면 더 검사할 필요가 없다
            if (sum[i-1] if i else 0) + 2 * v > sum[-1]:
                break
            idx = binarySearch(sum, (sum[i-1] if i else 0) + v)
            if idx == -1:
                continue
            idx = binarySearch(sum, sum[idx] + v)
            if idx != -1:
                return v
    return 0