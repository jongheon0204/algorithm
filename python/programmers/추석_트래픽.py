# 2018 카카오 블라인드 [1차] : 추석 트래픽 Level 3
# https://programmers.co.kr/learn/courses/30/lessons/17676

def solution(lines):
    logs = []
    for line in lines:
        l = len(line)
        # 문제 조건에 따라 응답완료 시간을 구한다
        end = int(line[11:13]) * 3600 * 1000 + int(line[14:16]) * 60 * 1000 + int(line[17:19]) * 1000 + int(line[20:23])
        start = end - int(line[24]) * 1000 + 1

        # 처리시간 정보는 다양하게 들어 올 수 있기 때문에 이 부분을 처리해 준다
        if l > 27:
            start -= int(line[26]) * 100
        if l > 28:
            start -= int(line[27]) * 10
        if l > 29:
            start -= int(line[28])

        # 로그 시작 시간과 종료 시간을 로그 리스트에 추가한다
        logs.append((start, end))

    ans = 0
    # 로그의 최대 개수는 2,000개 -> 한 개 로그 당 모든 로그와 비교를 하는 N^2 풀이방법이 통과한다
    for i in range(len(logs)):
        start = 0
        end = 0
        for j in range(len(logs)):
            # 로그 시작 시간 과 로그 시작 시간 + 1000 사이에 다른 로그가 존재하는지 검사
            if logs[i][0] <= logs[j][0] < logs[i][0] + 1000:
                start += 1
            elif logs[i][0] <= logs[j][1] < logs[i][0] + 1000:
                start += 1
            elif logs[j][0] <= logs[i][0] <= logs[j][1]:
                start += 1

            # 로그 종료 시간과 로그 종료 시간 + 1000 사이에 다른 로그가 존재하는지 검사
            if logs[i][1] <= logs[j][0] < logs[i][1] + 1000:
                end += 1
            elif logs[i][1] <= logs[j][1] < logs[i][1] + 1000:
                end += 1
            elif logs[j][0] <= logs[i][1] <= logs[j][1]:
                end += 1
        ans = max(ans, max(start, end))

    return ans