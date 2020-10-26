// 이분 매칭
#include <iostream>
#include <vector>
#define TASK_SIZE 100
#define vi vector<int>
using namespace std;

vi task;
vector<vi> edge;
vector<bool> isVisit;

bool DFS(int n){
    if(isVisit[n]) return false;
    isVisit[n] = true;
    for(int i=0; i<edge[n].size(); i++){
        int next = edge[n][i];
        if(task[next] == -1 || DFS(task[next])){
            task[next] = n;
            return true;
        }
    }
    return false;
}

int main(){
    int n, m; cin>>n>>m;
    edge = vector<vi>(m);
    task = vi(n);

    for(int i=0; i<m; i++){
        int s, e; cin>>s>>e;
        for(int j=s-1; j<e; j++){
            edge[i].push_back(j);
        }
    }

    int ans = 0;
    for(int i=0; i<m; i++){
        fill(isVisit.begin(), isVisit.end(), false);
        if(DFS(i)){
            ans++;
        }
    }
}
