#include <iostream>
#include <vector>
#include <algorithm>
#define vi vector<int>
#define pii pair<int, int>
using namespace std;

vector<int> parent;
vector<int> level;
vector<int> idx;
vector<vi> edge;
vector<pii> conference;

int find(int u){
    while(u != parent[u]){
        parent[u] = parent[parent[u]];
        u = parent[u];
    }
    return u;
}

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
    idx = vector<int>(n + 1, -1);
    parent = level = vector<int>(n + 1);
    edge = vector<vi>(n + 1, vi(n + 1, 101));
    for(int i=1; i<=n; i++){
        parent[i] = i;
        edge[i][i] = 0;
    }

    while(m--){
        int s, e; cin>>s>>e;
        merge(s, e);
        edge[s][e] = edge[e][s] = 1;
    }

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
