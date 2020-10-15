# https://www.acmicpc.net/problem/2003
# 2003.수들의 합2 : 2020.10.12

import sys

ans = 0
n, m = map(int, sys.stdin.readline().split())
num = list(map(int, sys.stdin.readline().split()))

# 투포인터 방식 사용 (l, r) 까지의 합을 v에 저장하여 m과 비교
l, v = (0, 0)
for r in range(n):
    v += num[r]
    while l <= r and v > m:
        v -= num[l]
        l += 1
    if v == m:
        ans += 1

print(ans)