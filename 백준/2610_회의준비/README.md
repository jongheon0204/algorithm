### [2610. 회의준비](https://www.acmicpc.net/problem/2610)

1. 회의에 참석하는 사람들 사이의 관계에 따라 하나 이상의 위원회를 구성한다. 이때 서로 알고 있는 사람은 반드시 같은 위원회에 속해야 한다는 조건이 있다.
2. 위원회 구성이 완료되면 대표를 한 명씩 뽑아야 한다. 이때 참석자가 대표에세 의견을 전달하는 경우 알고 있는 사람을 거쳐야 하는데 이때 거치는 사람의 수를 의사전달시간이라 하며 이 값의 최대값이 최소가 되도록 해야 한다.

위의 조건에서 1번은 Union-Find 알고리즘을 통해 그룹화가 가능하다. 2번은 Floyd Warshall 알고리즘을 통해 최단 길이를 찾아 해결할 수 있다.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#define vi vector<int>
#define pii pair<int, int>
using namespace std;

// union-find 알고리즘을 사용하기 위한 parent, level
vector<int> parent;
vector<int> level;
// 해당 그룹이 conference의 어떤 인덱스에 위치하는지 저장하는 배열
vector<int> idx;
// floyd warshall 알고리즘을 사용하기 위해 간선의 정보를 저장한다.
vector<vi> edge;
// 위원회의 대표 번호와 최대 의사전달시간을 저장한다.
vector<pii> conference;

// 해당 그룹의 root 노드를 찾는 함수
int find(int u){
    while(u != parent[u]){
        parent[u] = parent[parent[u]];
        u = parent[u];
    }
    return u;
}

// 정점 u와 v를 하나의 그룹으로 만든다.
void merge(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return;
    if(level[u] > level[v]) swap(u, v);
    parent[u] = v;
    if(level[u] == level[v]) level[v]++;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin>>n>>m;
		// 값 초기화
    idx = vector<int>(n + 1, -1);
    parent = level = vector<int>(n + 1);
    edge = vector<vi>(n + 1, vi(n + 1, 101));
    for(int i=1; i<=n; i++){
        parent[i] = i;
        edge[i][i] = 0;
    }

		// m개의 관계를 입력받는다.
    while(m--){
        int s, e; cin>>s>>e;
        merge(s, e);
        edge[s][e] = edge[e][s] = 1;
    }

		// floyd warshall 알고리즘을 통해 최단 길이를 찾는다
    // mid, start, end
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(edge[j][k] > edge[j][i] + edge[i][k]){
                    edge[j][k] = edge[j][i] + edge[i][k];
                }
            }
        }
    }

		// conference 배열에 저장된 위원회 대표 정보를 통해 갱신
    for(int i=1; i<=n; i++){
        int sum = 0, f = find(i);
        for(int j=1; j<=n; j++){
            sum = max(sum, (edge[i][j] == 101 ? 0 : edge[i][j]));
        }
        if(idx[f] != -1){
            if(conference[idx[f]].second > sum){
                conference[idx[f]] = {i, sum};
            }
        }else{
            idx[f] = conference.size();
            conference.push_back({i, sum});
        }
    }

    sort(conference.begin(), conference.end());
    cout<<conference.size()<<'\n';
    for(int i=0; i<conference.size(); i++){
        cout<<conference[i].first<<'\n';
    }

}
```
