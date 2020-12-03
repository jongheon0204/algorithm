#include <iostream>
#include <vector>
#define SIZE 1000001
using namespace std;

int pisano(int div){
    int f1 = 0, f2 = 1, ret = 0;
    bool is_pre_zero = false;
    while(++ret){
        int f3 = (f1 + f2) % div;
        if(is_pre_zero){
            if(f3 == 1) break;
            else is_pre_zero = false;
        }
        if(!f3) is_pre_zero = true;
        f1 = f2;
        f2 = f3;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector<int> ans(SIZE);
    int tc; cin>>tc;
    while(tc--){
        int n, m; cin>>n>>m;
        if(!ans[m]) ans[m] = pisano(m);
        cout<<n<<' '<<ans[m]<<'\n';
    }
}