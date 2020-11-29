#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        vector<int> cnt(n+1), idx(n+1);
        for(int i=0, v; i<n; i++){
            cin>>v;
            cnt[v]++;
            idx[v] = i+1;
        }
        int ans = -1;
        for(int i=1; i<=n; i++){
            if(cnt[i] == 1){
                ans = idx[i];
                break;
            }
        }
        cout<<ans<<'\n';
    }
}