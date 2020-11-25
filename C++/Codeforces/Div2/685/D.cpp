// https://codeforces.com/contest/1451/problem/D
#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin>>tc;
    while(tc--){
        ll d, k, cnt = 0, x = 0, y = 0; cin>>d>>k;
        d *= d;

        while(++cnt){
            if(x >= y) {
                if (pow(y + k, 2) + pow(x, 2) <= d) {
                    y += k;
                }else break;
            }else{
                if(pow(y, 2) + pow(x + k, 2) <= d){
                    x += k;
                }
                else break;
            }
        }

        cout<<(cnt & 1 ? "Utkarsh\n" : "Ashish\n");
    }
}