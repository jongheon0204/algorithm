#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define ll long long
#define pli pair<ll, int>

using namespace std;

vector<ll> endTime, process;

void divide(string line)
{
    ll start = ((line[11] - '0') * 10 + (line[12] - '0')) * 1000 * 60 * 60;
    start += ((line[14] - '0') * 10 + (line[15] - '0')) * 1000 * 60;
    start += ((line[17] - '0') * 10 + (line[18] - '0')) * 1000;
    start += ((line[20] - '0') * 100 + (line[21] - '0') * 10 + (line[22] - '0'));

    endTime.push_back(start);

    process.push_back(0);
    process.back() += (line[24] - '0') * 1000;
    for (int i = 26, val = 100; line[i] != 's' && line[i] != '\0'; i++, val /= 10)
    {
        process.back() += (line[i] - '0') * val;
    }
}

int isRange(const ll &sTime, const ll &csTime, const ll &ceTime)
{
    if (sTime <= csTime && csTime <= sTime + 999)
        return 1;
    if (sTime <= ceTime && ceTime <= sTime + 999)
        return 1;
    if (csTime <= sTime && sTime + 999 <= ceTime)
        return 1;
    return 0;
}

int solution(vector<string> lines)
{
    for (int i = 0; i < lines.size(); i++)
    {
        divide(lines[i]);
    }

    int ans = 0;

    for (int i = 0, sCnt = 0, eCnt = 0; i < lines.size(); i++, sCnt = 0, eCnt = 0)
    {
        ll sTime = endTime[i] - process[i] + 1;
        for (int j = 0; j < lines.size(); j++)
        {
            ll csTime = endTime[j] - process[j] + 1;
            sCnt += isRange(sTime, csTime, endTime[j]);
            eCnt += isRange(endTime[i], csTime, endTime[j]);
        }
        ans = max(ans, max(sCnt, eCnt));
    }

    return ans;
}