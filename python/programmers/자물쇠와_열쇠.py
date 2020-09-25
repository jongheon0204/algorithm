# 2020 카카오 블라인드 : 자물쇠와 열쇠 Level 3
# https://programmers.co.kr/learn/courses/30/lessons/60059

# 키를 90도 회전하는 함수
def RotateKey(key):
    ret = []
    for i in range(len(key)):
        ret.append([])
        for j in range(len(key) - 1, -1, -1):
            ret[i].append(key[j][i])
    return ret

# 키의 돌기 부분의 좌표 리스트를 반환하는 함수
def getKeyIdx(key):
    ret = []
    for i in range(len(key)):
        for j in range(len(key)):
            if key[i][j]:
                ret.append((i, j))
    return ret

# 키를 통해 자물쇠를 풀 수 있는지 검사하는 함수
def isUnlock(keys, lock, cnt):
    for i in range(len(lock)):
        for j in range(len(lock)):
            # 자물쇠에 돌기가 있는 부분은 검사할 필요가 없다
            if lock[i][j]:
                continue

            # 자물쇠 홈에 키의 k번째 돌기 위치를 동일하게 하여 검사한다
            for k in range(len(keys)):
                t = 0
                difY = keys[k][0] - i
                difX = keys[k][1] - j
                for key in keys:
                    # 키의 돌기가 자물쇠 범위를 벗어나게 되는 경우 무시한다
                    if not (0 <= key[0] - difY < len(lock)) or not (0 <= key[1] - difX < len(lock)):
                        continue
                    # 키의 돌기가 자물쇠 돌기와 만난다면 해당 부분 검사를 종료한다
                    if lock[key[0] - difY][key[1] - difX]:
                        t = -1
                        break
                    # 키의 돌기가 자물쇠 홈과 만난다면 t 값을 1 증가 시킨다
                    if not lock[key[0] - difY][key[1] - difX]:
                        t += 1
                # t값과 cnt 값이 동일한 경우 자물쇠가 풀린다
                if t == cnt:
                    return True
    return False

def solution(key, lock):
    cnt = 0
    # 자물쇠에 홈이 몇 개 있는지 검사
    for i in range(len(lock)):
        for j in range(len(lock)):
            if not lock[i][j]:
                cnt += 1

    # 홈이 없는 경우 열쇠를 사용하지 않아도 자물쇠를 풀 수 있다
    if not cnt:
        return True

    keys = getKeyIdx(key)

    # 열쇠의 돌기 개수가 자물쇠의 홈 개수보다 작다면 자물쇠는 풀 수 없다
    if len(keys) < cnt:
        return False

    # 검사 후 키를 90도 회전 하며 검사를 진행한다
    for i in range(4):
        if isUnlock(keys, lock, cnt):
            return True
        key = RotateKey(key)
        keys = getKeyIdx(key)
    return False