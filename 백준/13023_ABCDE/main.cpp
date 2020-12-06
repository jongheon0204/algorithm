#include <iostream>
#include <vector>
#define vi vector<int>
using namespace std;

vector<vi> edge;
vector<bool> is_visit;

bool dfs(int cur, int depth)
{
    if (depth == 4)
        return true;
    is_visit[cur] = true;
    bool ret = false;
    for (int i = 0; i < edge[cur].size() and !ret; i++)
    {
        int next = edge[cur][i];
        if (is_visit[next])
            continue;
        ret = dfs(next, depth + 1);
    }
    is_visit[cur] = false;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    edge = vector<vi>(n);
    is_visit = vector<bool>(n);
    while (m--)
    {
        int s, e;
        cin >> s >> e;
        edge[s].push_back(e);
        edge[e].push_back(s);
    }

    bool is_friend = false;
    for (int i = 0; i < n and !is_friend; i++)
    {
        fill(is_visit.begin(), is_visit.end(), false);
        is_friend = dfs(i, 0);
    }
    cout << is_friend;
}