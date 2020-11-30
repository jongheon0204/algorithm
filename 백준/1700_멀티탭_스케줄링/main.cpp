#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k, ans = 0; cin>>n>>k;

    if(n < k){
        vector<bool> is_used_plug(k + 1);
        vector<int> multitap, plug(k);
        for(int i=0; i<k; i++){
            cin>>plug[i];
        }

        for(int i=0; i<k; i++){
            if(is_used_plug[plug[i]]) continue;
            if(multitap.size() < n){
                multitap.push_back(plug[i]);
                is_used_plug[plug[i]] = true;
            }else{
                int dif = 0, c_idx = 0;
                for(int j=0; j<multitap.size(); j++){
                    int p = i + 1;
                    while(p < k and plug[p] != multitap[j]){
                        p++;
                    }
                    if(dif < (p - i)){
                        dif = p - i;
                        c_idx = j;
                    }
                }
                is_used_plug[multitap[c_idx]] = false;
                is_used_plug[plug[i]] = true;
                multitap[c_idx] = plug[i];
                ans++;
            }
        }
    }
    cout<<ans;
}