# https://www.acmicpc.net/problem/1062
# 가르침 - 2020.10.03

import sys
from itertools import combinations

# (n, k) = (단어 개수, 가르칠 글자 수)
(n, k) = sys.stdin.readline().split()
n = int(n)
k = int(k)

# a, c, n, t, i는 꼭 배워야 하는 단어기 때문에 k는 5이상이어야 한다
if k < 5:
    print(0)
    exit(0)

# 단어에 포함된 문자를 저장할 리스트
words = []
# letter를 이용하여 필요한 단어 순열을 만든다
letter = set()
# 공통적으로 들어가는 문자 5개
comLetter = ['a','c','n','t','i']

for i in range(n):
    words.append(set(sys.stdin.readline()[:-1]))
    # 서로 다른 문자열이 k+1개 이상이면 어떤 문자를 선택해도 배울 수 없다
    if len(words[-1]) > k:
        words.pop()
    else:
        for w in comLetter:
            words[-1].remove(w)
        letter = letter | words[-1]

# letter에 포함된 문자를 통해 순열을 만든다
combs = list(map(''.join, combinations(letter, min(k - 5, len(letter)))))

# 정답을 저장할 변수
maxWord = 0
# 모든 순열로 검사
for comb in combs:
    comb = set(comb)
    cnt = 0
    for word in words:
        if comb == (word | comb):
            cnt += 1
    maxWord = max(maxWord, cnt)

print(maxWord)