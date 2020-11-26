// https://www.acmicpc.net/problem/19941
// 19941 : 햄버거 분배

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k, ans = 0; cin>>n>>k;
    string table; cin>>table;

    vector<bool> isEat(n);
    for(int i=0; i<isEat.size(); i++){
        if(table[i] == 'P'){
            for(int j = max(i - k, 0); j<min(i+k+1, n); j++){
                if(table[j] == 'H' and !isEat[j]){
                    isEat[j] = true;
                    ans++;
                    break;
                }
            }
        }
    }

    cout<<ans;
}