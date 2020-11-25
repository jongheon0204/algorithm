// https://codeforces.com/contest/1451/problem/A
#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        if(n == 1){
            cout<<"0\n";
        }else if(n == 2){
            cout<<"1\n";
        }else if(n == 3 || !(n & 1)){
            cout<<"2\n";
        }else{
            cout<<"3\n";
        }
    }
}