# https://www.acmicpc.net/problem/1713
# 1713.후보 추천하기 - 2020.10.04

import sys

# n : 사진틀 개수, m : 추천수
n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

# 추천 데이터 list
recommends = sys.stdin.readline().split()

# 사진틀 데이터 list
photoFrames = []
# 학생 사진이 사진틀에 게시되어 있는지 여부 list
isPhoto = [False for i in range(101)]

for i, recommend in enumerate(recommends):
    s = int(recommend)
    # 현재 사진틀에 게시되어 있으면
    if isPhoto[s]:
        # 추천수 정보 업데이트
        for photoFrame in photoFrames:
            if photoFrame[2] == s:
                photoFrame[0] += 1
    else:
        # 사진틀에 게시된 사진의 개수가 n개라면
        if len(photoFrames) == n:
            # 추천 수, 등록 순서 데이터로 정렬 후 데이터를 하나 제거
            photoFrames = sorted(photoFrames, key=lambda photoFrame : (photoFrame[0], photoFrame[1]), reverse=True)
            isPhoto[photoFrames[-1][2]] = False
            photoFrames.pop()
        # 사진틀 list에 데이터 업데이트
        photoFrames.append([1, i, s])
        isPhoto[s] = True

# 사진틀에 게시된 학생 정보 업데이트
for i in range(len(isPhoto)):
    if isPhoto[i]:
        print(i, end=' ')