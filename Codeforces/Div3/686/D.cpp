#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define ll long long
#define pli pair<ll, int>
using namespace std;

bool cmp(const pli & a, const pli & b){
    return a.second > b.second;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin>>tc;
    while(tc--){
        ll n; cin>>n;
        ll sqrtn = (ll)sqrt(n);
        int cnt = 0, div = 0;
        for(ll i=2, v = n; v && i<=sqrtn; i++){
            int c = 0;
            while(!(v % i)){
                c++;
                v /= i;
            }
            if(c > cnt){
                cnt = c;
                div = i;
            }
        }
        if(cnt < 2){
            cout<<1<<'\n'<<n<<'\n';
        }else{
            cout<<cnt<<'\n';
            while(--cnt){
                cout<<div<<' ';
                n /= div;
            }cout<<n<<'\n';
        }
    }
}