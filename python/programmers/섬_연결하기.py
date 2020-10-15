# 탐욕법 : 섬 연결하기 Level 3
# https://programmers.co.kr/learn/courses/30/lessons/42861?language=python3

# 해당 그래프에서 root를 찾는다
def find(u, parent):
    while u != parent[u]:
        parent[u] = parent[parent[u]]
        u = parent[u]
    return u

# u 정점과 v 정점을 하나의 그래프로 합친다
def merge(u, v, parent, level):
    u = find(u, parent)
    v = find(v, parent)
    if u == v:
        return False

    if level[u] > level[v]:
        (u, v) = (v, u)

    parent[u] = v
    if level[u] == level[v]:
        level[v] += 1
    return True

# Union-find 알고리즘 사용
def solution(n, costs):
    # 비용 기준으로 오름차순 정렬
    costs = sorted(costs, key=lambda cost: (cost[2]))
    parent = [i for i in range(n)]
    level = [0 for _ in range(n)]

    ans = 0
    for cost in costs:
        # cost[0], cost[1] 정점이 하나의 그래프에 속해있지 않다면 값을 더해준다
        if merge(cost[0], cost[1], parent, level):
            ans += cost[2]
    return ans