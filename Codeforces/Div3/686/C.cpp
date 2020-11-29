#include <iostream>
#include <vector>
#include <algorithm>
#define vi vector<int>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin>>tc;
    while(tc--){
        int n, idx = 0; cin>>n;
        vector<int> arr(n);
        vector<vi> cnt(n+1);
        for(int i=0; i<n; i++){
            cin>>arr[idx];
            if(!idx || arr[idx] != arr[idx-1]){
                cnt[arr[idx]].push_back(idx);
                idx++;
            }
        }
        int ans = idx;
        for(int i=1; i<cnt.size(); i++){
            if(cnt[i].empty()) continue;
            int val = cnt[i].size() + 1;
            if(cnt[i].back() == idx - 1) val--;
            if(!cnt[i][0]) val--;
            ans = min(ans, val);
        }
        cout<<ans<<'\n';
    }
}