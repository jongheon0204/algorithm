# https://www.acmicpc.net/problem/1759
# 1759.암호 만들기 : 2020.10.08

import sys

l, c = map(int, sys.stdin.readline().split())
alpha = sys.stdin.readline().split()
alpha = sorted(alpha)

# 생성된 암호가 모음 1개 이상, 자음 2개 이상 포함하는지 검사
def isRightCipher(cipher):
    cnt = 0
    vowels = ['a','e','i','o','u']
    for vowel in vowels:
        if vowel in cipher:
            cnt += 1

    return cnt >= 1 and len(cipher) - cnt >= 2

# BackTracking 기법을 사용하여 암호를 생성한다
def createCipher(alpha, cipher, s):
    if len(cipher) == l:
        if isRightCipher(cipher):
            for ci in cipher:
                print(ci, end='')
            print()
            return

    # 추가해야 하는 문자 개수가 사용할 수 있는 문자 개수보다 많다면 함수를 끝낸다
    if len(alpha) - s < l - len(cipher):
        return

    for i in range(s, c):
        cipher.append(alpha[i])
        createCipher(alpha, cipher, i+1)
        cipher.pop()

createCipher(alpha, [], 0)