// https://www.acmicpc.net/problem/15686
// 15686.치킨 배달 : 2020.10.12

#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
#define vpi vector<pii>
#define MAX 987654321

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m; cin>>n>>m;
    vector<pii> chicken, home;

    // 1 : 집, 2 : 치킨집
    for(int i=0, v; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>v;
            if(v == 1) home.push_back({i, j});
            else if(v == 2) chicken.push_back({i, j});
        }
    }

    // 집에서 치킨과의 거리를 하나씩 이차배열에 추가
    vector<vpi> dis(home.size(), vpi(chicken.size()));
    for(int i=0; i<home.size(); i++){
        for(int j=0; j<chicken.size(); j++){
            dis[i][j] = {abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second), j};
        }
        // 집에서 가까운 치킨집과의 거리만 알면 된다
        sort(dis[i].begin(), dis[i].end());
    }

    // 조합을 사용
    vector<int> permu(chicken.size());
    for(int i=0; i<m; i++) permu[i] = 1;

    int ans = MAX;
    do{
        int val = 0;
        // i번째 집에서 가장 가까운 치킨집을 찾는다
        for(int i=0; i<dis.size(); i++){
            for(int j=0; j<dis[i].size(); j++){
                if(permu[dis[i][j].second]){
                    val += dis[i][j].first;
                    break;
                }
            }
            if(val > ans) break;
        }
        ans = min(ans, val);
    }while(prev_permutation(permu.begin(), permu.end()));

    cout<<ans;
}