# https://www.acmicpc.net/problem/2580
# 2580.스도쿠 : 2020.10.11

import sys

SIZE = 9

# 입력을 받아 리스트에 정수로 저장
sudoku = [list(map(int, sys.stdin.readline().split())) for i in range(SIZE)]
point = []

# 비어있는 곳의 좌표를 저장
for i in range(SIZE):
    for j in range(SIZE):
        if not sudoku[i][j]:
            point.append((i, j))

def fillSudoku(depth):
    # 스도쿠가 풀린 경우 출력
    if depth == len(point):
        for i in range(SIZE):
            print(' '.join(map(str, sudoku[i])))
        return True

    # 현재 자리에 넣을 수 있는 숫자를 찾기 위한 리스트
    isUsedNum = [False for i in range(SIZE + 1)]

    dy = point[depth][0]
    dx = point[depth][1]

    # 가로, 세로 검사
    for i in range(SIZE):
        isUsedNum[sudoku[dy][i]] = True
        isUsedNum[sudoku[i][dx]] = True

    y = (dy // 3) * 3;
    x = (dx // 3) * 3;

    # 3 x 3 검사
    for i in range(3):
        for j in range(3):
            isUsedNum[sudoku[y+i][x+j]] = True

    # BackTracking 방법으로 다음번 비어있는 곳 채우기
    for i in range(1, SIZE + 1):
        if not isUsedNum[i]:
            sudoku[dy][dx] = i
            if fillSudoku(depth + 1):
                return True
            sudoku[dy][dx] = 0

    return False

fillSudoku(0)