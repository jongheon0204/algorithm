// https://www.acmicpc.net/problem/2805
// 2805.나무자르기 : 2020.10.16

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

ll n, m;
// 나무의 높이를 저장할 tree 배열과 해당 나무까지 높이의 합을 저장할 sum 배열
vector<ll> tree, sum;

// 이분 탐색 기법을 통해 정답의 범위를 줄여 나간다
ll findHeight(ll l, ll r){
    if(l > r) return 0;
    ll mid = (l + r) / 2;
    int idx = lower_bound(tree.begin(), tree.end(), mid) - tree.begin();

    // sum 배열을 이용해 절단한 나무 길이 총합을 쉽게 구할 수 있다
    ll val = sum.back() - (idx ? sum[idx - 1] : 0) - (sum.size() - idx) * mid;

    // 현재 자른 나무 길이의 총합이 m보다 같거나 크다면 더 짧게 자를 수 있는지 검사한다
    if(val >= m){
        return max(mid, findHeight(mid+1, r));
    }else{
        return findHeight(l, mid-1);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin>>n>>m;
    tree = sum = vector<ll>(n);
    for(int i=0; i<n; i++){
        cin>>tree[i];
    }

    sort(tree.begin(), tree.end());
    for(int i=0; i<n; i++){
        sum[i] = (i ? sum[i-1] : 0) + tree[i];
    }

    cout<<findHeight(0, tree.back());
}