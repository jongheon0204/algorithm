def solution(lines):
    logs = []
    for line in lines:
        l = len(line)
        end = int(line[11:13]) * 3600 * 1000 + int(line[14:16]) * 60 * 1000 + int(line[17:19]) * 1000 + int(line[20:23])
        start = end - int(line[24]) * 1000 + 1
        if l > 27:
            start -= int(line[26]) * 100
        if l > 28:
            start -= int(line[27]) * 10
        if l > 29:
            start -= int(line[28])
        
        logs.append((start, end))
    
    ans = 0
    for i in range(len(logs)):
        start = 0
        end = 0
        for j in range(len(logs)):
            if logs[i][0] <= logs[j][0] < logs[i][0] + 1000:
                start += 1
            elif logs[i][0] <= logs[j][1] < logs[i][0] + 1000:
                start += 1
            elif logs[j][0] <= logs[i][0] <= logs[j][1]:
                start += 1
            
            if logs[i][1] <= logs[j][0] < logs[i][1] + 1000:
                end += 1
            elif logs[i][1] <= logs[j][1] < logs[i][1] + 1000:
                end += 1
            elif logs[j][0] <= logs[i][1] <= logs[j][1]:
                end += 1
        ans = max(ans, max(start, end))
        
    return ans