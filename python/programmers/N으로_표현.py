# 동적계획법 : N으로 표현 Level 3
# https://programmers.co.kr/learn/courses/30/lessons/42895

def solution(N, number):
    # 검사를 위해 Queue에 데이터를 넣는다
    que = [(1, 2), (N, 1)]
    useNum = [(1, 2), (N, 1)]
    # N이 1이라면 (1, 1)만 저장되어 있어야 한다
    if N == 1:
        del que[0]
        del useNum[0]
    # Dictionary를 이용해 최소 값을 찾아준다
    cnt = {1: 1, N: 1}
    while que[-1][0] <= number:
        que.append((que[-1][0] * 10 + N, que[-1][1] + 1))
        useNum.append((useNum[-1][0] * 10 + N, useNum[-1][1] + 1))
        cnt[useNum[-1][0]] = useNum[-1][1]

    while que:
        if que[0][1] > 8:
            del que[0]
            continue
        for num in useNum:
            (h, l, v) = (max(num[0], que[0][0]), min(num[0], que[0][0]), que[0][1] + num[1])

            # 더하기 연산을 통해 값 갱신
            if h + l not in cnt or cnt[h + l] > v:
                cnt[h + l] = v
                que.append((h + l, v))

            # 빼기 연산을 통해 값 갱신
            if h - l != 0 and (h - l not in cnt or cnt[h - l] > v):
                cnt[h - l] = v
                que.append((h - l, v))

            # 곱하기 연산을 통해 값 갱신
            if h * l not in cnt or cnt[h * l] > v:
                cnt[h * l] = v
                que.append((h * l, v))

            # 나눗셈 연산을 통해 값 갱신
            if not h % l and (h // l not in cnt or cnt[h // l] > v):
                cnt[h // l] = v
                que.append((h // l, v))

        # 사용한 데이터는 큐에서 제거
        del que[0]

    return cnt[number] if number in cnt else -1