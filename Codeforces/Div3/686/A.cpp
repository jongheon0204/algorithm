#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        for(int i=2; i<=n; i++){
            cout<<i<<' ';
        }cout<<1<<'\n';
    }
}