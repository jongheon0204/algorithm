# https://www.acmicpc.net/problem/1759
# 9663.N-Queen : 2020.10.08

import sys

n = int(sys.stdin.readline())

def nQueen(points):
    if n == len(points):
        return 1

    ret = 0

    r = len(points)
    for c in range(n):
        isQueen = True;
        for point in points:
            if point[1] == c or (abs(point[0] - r) == abs(point[1] - c)):
                isQueen = False
                break

        if isQueen:
            points.append((r, c))
            ret += nQueen(points)
            points.pop()

    return ret

print(nQueen([]))
