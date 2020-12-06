### [13023. ABCDE](https://www.acmicpc.net/problem/13023)

N명의 사람과 친구 관계 수 M이 주어진다. 이때 친구 관계를 그래프로 나타냈을 때 그래프의 깊이가 5이상인 게 있는지 판별하는 문제이다.

사람의 수와 친구 관계의 수가 2000으로 제한되어 있기 때문에 모든 노드에 대해 DFS 방법을 통해 검사하여도 시간초과가 발생하지 않는다.

```cpp
#include <iostream>
#include <vector>
#define vi vector<int>
using namespace std;

vector<vi> edge;
vector<bool> is_visit;

bool dfs(int cur, int depth){
    if(depth == 4) return true;
    is_visit[cur] = true;
    bool ret = false;
    for(int i=0; i<edge[cur].size() and !ret; i++){
        int next = edge[cur][i];
        if(is_visit[next]) continue;
        ret = dfs(next, depth + 1);
    }
    is_visit[cur] = false;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin>>n>>m;

    edge = vector<vi>(n);
    is_visit = vector<bool>(n);
    while(m--){
        int s, e; cin>>s>>e;
        edge[s].push_back(e);
        edge[e].push_back(s);
    }

    bool is_friend = false;
    for(int i=0; i<n and !is_friend; i++){
        fill(is_visit.begin(), is_visit.end(), false);
        is_friend = dfs(i, 0);
    }
    cout<<is_friend;
}
```
