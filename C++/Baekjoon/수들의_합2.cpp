// https://www.acmicpc.net/problem/2003
// 2003.수들의 합2 : 2020.10.12

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, ans = 0; cin>>n>>m;

    // 투포인터 방법을 사용 (l, r) 범위의 합을 v에 저장하여 m과 비교
    vector<int> num(n);
    for(int l=0,r=0,v=0; r<n; r++){
        cin>>num[r];
        v += num[r];
        while(l <= r && v > m){
            v -= num[l++];
        }
        if(v == m)ans++;
    }
    cout<<ans;
}