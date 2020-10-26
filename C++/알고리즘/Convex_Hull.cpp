#include <iostream>
#include <algorithm>
#include <vector>
#define x first
#define y second
#define ll long long
#define pll pair<ll, ll>
#define pow(a) ((a) * (a))

using namespace std;

pll leftmost;

// ccw를 이용해 삼각형의 방향이 시계 방향인지 반시계 방향인지 파악
// 0보다 작다 : 시계 방향, 0 : 일직선, 0보다 크다 : 반시계 방향
ll ccw(const pll & a, const pll & b, const pll & c){
    return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}

// 일직선인 경우 거리를 통해 파악
ll dis(const pll & a, const pll & b){
    return pow((a.x - b.x)) + pow((a.y - b.y));
}

// 비교 구문
bool cmp(const pll & a, const pll & b){
    ll ccwVal = ccw(leftmost, a, b);
    return ccwVal > 0 || (ccwVal == 0 && dis(leftmost, a) < dis(leftmost, b));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, l=0; cin>>n;
    vector<pll> point(n);

    for(int i=0; i<n; i++){
        cin>>point[i].x>>point[i].y;
        if(point[i].x < point[l].x) l = i;
        if(point[i].x == point[l].x && point[i].y < point[l].y) l = i;
    }

    leftmost = point[l];

    sort(point.begin(), point.end(), cmp);

    vector<pll> ans(1, point[0]);
    for(int i=1; i<n; i++){
        // 현재 검사하는 정점까지 해서 CCW 값이 0보다 작으면 시계 방향 즉 볼록 껍질에 들어갈 수 없다.
        while(ans.size() >= 2 && ccw(ans[ans.size() - 2], ans.back(), point[i]) <= 0) ans.pop_back();
        ans.push_back(point[i]);
    }
    cout<<ans.size();
}
