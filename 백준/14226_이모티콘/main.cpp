#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define vi vector<int>
using namespace std;

struct emotion
{
    int num;
    int time;
    int clip;
};

struct cmp
{
    bool operator()(const emotion &a, const emotion &b)
    {
        return a.time > b.time;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s;
    cin >> s;
    // 이모티콘, 클립 수
    vector<vi> cnt(1001, vi(1001, s * s));

    // 개수, 시간
    priority_queue<emotion, vector<emotion>, cmp> que;
    que.push({1, 0, 0});
    cnt[1][0] = 0;
    while (!que.empty())
    {
        emotion cur = que.top();
        que.pop();
        if (cur.num == s)
            break;

        int next = cur.num - 1;
        if (next and cnt[next][cur.clip] > cur.time + 1)
        {
            cnt[next][cur.clip] = cur.time + 1;
            que.push({next, cur.time + 1, cur.clip});
        }

        next = cur.num + cur.clip;
        if (next < cnt.size() and cnt[next][cur.clip] > cur.time + 1)
        {
            cnt[next][cur.clip] = cur.time + 1;
            que.push({next, cur.time + 1, cur.clip});
        }

        next = cur.num * 2;
        if (next < cnt.size() and cnt[next][cur.num] >= cur.time + 2)
        {
            cnt[next][cur.num] = cur.time + 2;
            que.push({next, cur.time + 2, cur.num});
        }
    }

    int ans = cnt[s][0];
    for (int i = 1; i < cnt[s].size(); i++)
    {
        ans = min(ans, cnt[s][i]);
    }
    cout << ans;
}