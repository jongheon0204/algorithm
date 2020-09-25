# 탐욕법 : 단속카메라 Level 3
# https://programmers.co.kr/learn/courses/30/lessons/42884

def solution(routes):
    # 차량의 시작 지점을 기준으로 오름차순 정렬
    routes = sorted(routes, key = lambda route: route[0])
    right = routes[0][1]
    ans = 1
    for route in routes:
        # 차량의 경로를 벗어난 차량이 있을 경우 카메라를 설치해야 하며 right 값도 변경해야 한다
        if route[0] > right:
            ans += 1
            right = route[1]
        # 차량의 종료 지점이 현재 right 값보다 작으면 right 값을 줄여준다
        elif route[1] < right:
            right = route[1]
    return ans