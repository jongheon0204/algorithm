#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define SIZE 100100
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    if (n >= k)
    {
        cout << (n - k);
        return 0;
    }
    vector<int> dis(SIZE, abs(n - k));

    queue<pii> que;
    que.push({n, 0});
    dis[n] = 0;
    while (!que.empty())
    {
        pii cur = que.front();
        que.pop();
        if (dis[cur.first] < cur.second)
            continue;

        if (cur.first * 2 < SIZE and dis[cur.first * 2] > cur.second)
        {
            dis[cur.first * 2] = cur.second;
            que.push({cur.first * 2, cur.second});
        }

        if (cur.first > 1 and dis[cur.first - 1] > cur.second + 1)
        {
            dis[cur.first - 1] = cur.second + 1;
            que.push({cur.first - 1, cur.second + 1});
        }

        if (cur.first < SIZE and dis[cur.first + 1] > cur.second + 1)
        {
            dis[cur.first + 1] = cur.second + 1;
            que.push({cur.first + 1, cur.second + 1});
        }
    }

    cout << dis[k];
}