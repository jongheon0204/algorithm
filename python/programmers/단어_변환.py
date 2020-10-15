# DFS/BFS : 단어 변환 Level 3
# https://programmers.co.kr/learn/courses/30/lessons/43163?language=python3

# DFS 방법을 통해 검사
def convertStr(begin, target, words, depth, isUse):
    # 변경한 글자와 target이 동일한 경우 depth를 반환
    if begin == target:
        return depth
    # ans의 최대 값이 50보다 큰 값
    ans = 100
    for i in range(len(begin)):
        # begin의 i번째 문자와 target의 i번째 문자가 동일하다면 변경할 필요가 없다
        if begin[i] == target[i]:
            continue
        # i번째만 변경하기 위해 추출
        find_word = begin[0:i] + begin[i + 1:]
        for j, word in enumerate(words):
            # 이전에 사용하지 않았고 i번째 문자만 다른 경우 단어를 변환
            if not isUse[j] and find_word == word[0:i] + word[i + 1:]:
                isUse[j] = True
                ans = min(ans, convertStr(word, target, words, depth + 1, isUse))
                isUse[j] = False
    return ans


def solution(begin, target, words):
    # DFS 방법 사용 시 해당 단어로 변경을 했는지 검사
    isUse = [False for _ in range(len(words))]
    ans = convertStr(begin, target, words, 0, isUse)
    return (ans if ans != 100 else 0)
