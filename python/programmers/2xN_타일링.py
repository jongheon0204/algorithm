# 연습문제 : 2xN 타일링 Level 3
# https://programmers.co.kr/learn/courses/30/lessons/12900

# 가로 길이가 i라고 할 때 2xN 타일은
# 가로 길이가 i - 1 인 타일에 2x1 타일을 붙이는 방법과
# 가로 길이가 i - 2 인 타일에 1x2 타일 2개를 붙이는 방법이 있다
# 결국 dp[i] = dp[i-1] + dp[i-2] 점화식을 따르게 된다

def solution(n):
    DIV = 1000000007
    dp = [0, 1, 2]
    for i in range(2, n):
        dp.append((dp[-1] + dp[-2]) % DIV)
    return dp[-1]