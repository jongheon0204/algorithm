// https://www.acmicpc.net/problem/9663
// 9663.N-Queen : 2020.10.08

#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>

using namespace std;

int n, ans = 0;
// Queen을 놓을 좌표를 저장
vector<pii> point;

void nQueen(){
    // N개의 퀸을 모두 놓은 경우
    if(point.size() == n){
        ans++;
        return;
    }
    // (r, c)에 퀸을 놓을 수 있는지 검사
    for(int r = point.size(), c = 0; c < n; c++){
        // (r, c)에 퀸을 놓으면 이전에 놓은 퀸과 서로 공격할 수 있는지 검사
        bool isQueen = true;
        for(int i=0; i<point.size(); i++){
            if(point[i].second == c || (abs(point[i].first - r) == abs(point[i].second - c))){
                isQueen = false;
            }
        }
        if(isQueen) {
            point.push_back({r, c});
            nQueen();
            point.pop_back();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n;
    nQueen();
    cout<<ans;
}