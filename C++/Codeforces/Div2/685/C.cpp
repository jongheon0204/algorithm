// https://codeforces.com/contest/1451/problem/C
#include <iostream>
#include <algorithm>
#include <vector>
#define SIZE 26
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin>>tc;
    while(tc--){
        int n, k; cin>>n>>k;
        string a, b; cin>>a>>b;

        vector<int> a_alph(SIZE), b_alph(SIZE);

        for(int i=0; i<n; i++){
            a_alph[a[i] - 'a']++;
            b_alph[b[i] - 'a']++;
        }

        bool isConvertable = true;

        for(int i=0; i<SIZE - 1; i++){
            while(a_alph[i] > b_alph[i]){
                a_alph[i] -= k;
                a_alph[i+1] += k;
            }
            if(a_alph[i] < b_alph[i]){
                isConvertable = false;
                break;
            }
        }

        if(a_alph[SIZE - 1] != b_alph[SIZE - 1]){
            isConvertable = false;
        }

        cout<<(isConvertable ? "Yes\n" : "No\n");
    }
}