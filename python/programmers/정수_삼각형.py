# 동적 계획법 : 정수 삼각형 Level 3
# https://programmers.co.kr/learn/courses/30/lessons/43105?language=python3

def solution(triangle):
    for i in range(len(triangle) - 2, -1, -1):
        for j in range(len(triangle[i])):
            # 두 자식 중 큰 값을 더해준다
            triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1])
    return triangle[0][0]