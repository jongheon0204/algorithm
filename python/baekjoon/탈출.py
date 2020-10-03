# https://www.acmicpc.net/problem/3055
# 탈출 - 2020.10.03

import sys

def isRange(r, c, y, x):
    return (0 <= y < r) and (0 <= x < c)

# map 크기 r, c
mapSize = sys.stdin.readline().split()
mapSize[0] = int(mapSize[0])
mapSize[1] = int(mapSize[1])

# 물, 고슴도치 이동 좌표를 저장할 리스트
water = []
hog = []
# 물, 고슴도치의 최단 이동 거리
waterMap = [[-1 for i in range(mapSize[1])] for j in range(mapSize[0])]
hogMap = [[-1 for i in range(mapSize[1])] for j in range(mapSize[0])]

map = []
for i in range(mapSize[0]):
    map.append(sys.stdin.readline())
    for j in range(mapSize[1]):
        if map[i][j] == 'D':
            beaver = (i, j)
        elif map[i][j] == 'S':
            hog.append((i, j))
            hogMap[i][j] = 0
        elif map[i][j] == '*':
            water.append((i, j))
            waterMap[i][j] = 0

# 이동 좌표 상, 우, 하, 좌
movePoints = ((-1, 0), (0, 1), (1, 0), (0, -1))

# 물의 이동을 BFS로 탐색
while water:
    point = water[0]
    del water[0]
    for movePoint in movePoints:
        # 물이 이동하는 새로운 좌표를 구한다
        newPoint = (point[0] + movePoint[0], point[1] + movePoint[1])
        # 새로운 좌표가 맵의 범위를 벗어나는 경우
        if not isRange(mapSize[0], mapSize[1], newPoint[0], newPoint[1]):
            continue
        # 새로운 좌표에 비버의 굴이 있거나 돌이 있는 경우
        if map[newPoint[0]][newPoint[1]] == 'D' or map[newPoint[0]][newPoint[1]] == 'X':
            continue
        # 물이 처음 이동하는 경우 혹은 더 짧은 시간에 이동하는 경우
        if waterMap[newPoint[0]][newPoint[1]] == -1 or waterMap[newPoint[0]][newPoint[1]] > waterMap[point[0]][point[1]] + 1:
            waterMap[newPoint[0]][newPoint[1]] = waterMap[point[0]][point[1]] + 1
            water.append(newPoint)

# 고슴도치 이동을 BFS로 탐색
while hog:
    point = hog[0]
    del hog[0]
    for movePoint in movePoints:
        # 고슴도치가 이동하는 새로운 좌표를 구한다
        newPoint = (point[0] + movePoint[0], point[1] + movePoint[1])
        # 새로운 좌표가 맵의 범위를 벗어나는 경우
        if not isRange(mapSize[0], mapSize[1], newPoint[0], newPoint[1]):
            continue
        # 새로운 좌표가 비버의 굴인 경우
        if map[newPoint[0]][newPoint[1]] == 'D':
            hogMap[newPoint[0]][newPoint[1]] = hogMap[point[0]][point[1]] + 1
            hog = []
            break
        # 새로운 좌표에 돌이 있거나 물이 차오른 경우
        if map[newPoint[0]][newPoint[1]] == 'X' or -1 < waterMap[newPoint[0]][newPoint[1]] <= hogMap[point[0]][point[1]] + 1:
            continue
        # 고슴도치가 새롭게 방문한 지역이거나 더 짧은 시간에 방문할 수 있는 경우
        if hogMap[newPoint[0]][newPoint[1]] == -1 or hogMap[newPoint[0]][newPoint[1]] > hogMap[point[0]][point[1]] + 1:
            hogMap[newPoint[0]][newPoint[1]] = hogMap[point[0]][point[1]] + 1
            hog.append(newPoint)

# 비버 굴 위치에 -1 값이면 도달하지 못한다
print(hogMap[beaver[0]][beaver[1]] if hogMap[beaver[0]][beaver[1]] != -1 else "KAKTUS")