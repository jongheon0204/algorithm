# https://www.acmicpc.net/problem/15686
# 15686.치킨 배달 : 2020.10.12

import sys
from itertools import combinations

n, m = map(int, sys.stdin.readline().split())

# 치킨집과 집의 좌표를 저장할 리스트
chicken = []
home = []

for i in range(n):
    for j, v in enumerate(list(map(int, sys.stdin.readline().split()))):
        if v == 1:
            home.append((i, j))
        elif v == 2:
            chicken.append((i, j))

# 치킨집과 집의 치킨 거리를 저장할 리스트
dis = [[0 for j in range(len(chicken))] for i in range(len(home))]

for i, h in enumerate(home):
    for j, c in enumerate(chicken):
        dis[i][j] = (abs(c[0] - h[0]) + abs(c[1] - h[1]), j)
    # 치킨 거리를 기준으로 오름차순 정렬하면 이후 모든 원소를 검사하지 않아도 된다
    dis[i] = sorted(dis[i], key=lambda d: d[0])

# 순열을 사용해 치킨집들중 m개의 치킨집을 뽑아낸다
permu = []
for i in range(len(chicken)):
    permu.append(i)

ans = 987654321
for comb in list(combinations(permu, m)):
    val = 0
    for i in range(len(dis)):
        for j in range(len(dis[i])):
            if dis[i][j][1] in comb:
                val += dis[i][j][0]
                break
        # 값이 이전에 나온 최소 치킨 거리보다 크다면 더 진행할 필요가 없다
        if val > ans:
            break
    ans = min(val, ans)

print(ans)