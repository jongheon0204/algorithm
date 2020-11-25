// https://codeforces.com/contest/1451/problem/B
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin>>tc;
    while(tc--){
        string s; int n, q;
        cin>>n>>q>>s;
        while(q--){
            int l, r; cin>>l>>r;
            l--; r--;

            int l_idx = 0, r_idx = n-1;
            while(l_idx < n && s[l_idx] != s[l]) l_idx++;
            while(r_idx >= 0 && s[r_idx] != s[r]) r_idx--;

            cout<<(r_idx - l_idx + 1 <= r - l + 1 ? "NO\n" : "YES\n");
        }
    }
}