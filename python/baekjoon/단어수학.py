# https://www.acmicpc.net/problem/1339
# 1339.단어 수학 : 2020.10.11

import sys

n = int(sys.stdin.readline())
alpha = [0 for i in range(26)]

# ABC -> 100A + 10B + C, BCA -> 100B + 10C + A
# 모든 문자를 위와 같은 식으로 변환한 후 값이 큰 문자열부터 차례대로 값을 대입
for i in range(n):
    word = sys.stdin.readline()[:-1]
    l = len(word)
    for j in range(l):
        alpha[ord(word[j]) - ord('A')] += 10**(l-j-1)

alpha = sorted(alpha, key = lambda al: al, reverse = True)

ans = 0
v = 9
for i in range(26):
    if not alpha[i]:
        break
    ans += (v * alpha[i])
    v -= 1

print(ans)