# 깊이/너비 우선 탐색 : 네트워크 Level 3
# https://programmers.co.kr/learn/courses/30/lessons/43162

# 깊이 우선 탐색(dfs)를 통해 현재 검사하는 정점과 연결 되어 있으며 아직 방문하지 않은 정점을 찾아 방문한다
def dfs(computers, isVisit, v):
    isVisit[v] = True
    for i in range(len(computers)):
        if computers[v][i] and not isVisit[i]:
            dfs(computers, isVisit, i)

def solution(n, computers):
    # 길이가 n인 리스트 초기화
    isVisit = [False for i in range(n)]
    ans = 0
    for i in range(n):
        # 한번 검사할 때 연결 되어 있는 모든 정점을 찾아내기 때문에 네트워크 개수가 추가된다
        if not isVisit[i]:
            ans += 1
            dfs(computers, isVisit, i)
    return ans
