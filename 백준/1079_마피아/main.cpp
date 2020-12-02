#include <iostream>
#include <vector>
#include <algorithm>
#define vi vector<int>
using namespace std;

vector<int> guilty;
vector<bool> die;
vector<vi> react;

int mafia_game(const int & mafia, int target, int depth){
    int ans = depth;
    for(int i=0; i<guilty.size(); i++){
        guilty[i] += react[target][i];
    }
    die[target] = true;

    int idx = -1;
    for(int i=0; i<guilty.size(); i++){
        if(!die[i] and (idx == -1 or guilty[idx] < guilty[i])){
            idx = i;
        }
    }
    if(idx == mafia or idx == -1){
        die[target] = false;
        for(int i=0; i<guilty.size(); i++){
            guilty[i] -= react[target][i];
        }
        return ans;
    }
    die[idx] = true;

    if(depth <= (guilty.size() - 1) / 2) {
        for (int i = 0; i < die.size(); i++) {
            if (!die[i] and mafia != i) {
                ans = max(ans, mafia_game(mafia, i, depth + 1));
            }
        }
    }

    die[target] = false;
    die[idx] = false;
    for(int i=0; i<guilty.size(); i++){
        guilty[i] -= react[target][i];
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, ans = 0; cin>>n;
    guilty = vi(n);
    die = vector<bool>(n);
    react = vector<vi>(n, vi(n));
    for(int i=0; i<n; i++) cin>>guilty[i];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>react[i][j];
        }
    }
    int mafia, idx = -1; cin>>mafia;

    if(n & 1){
        for(int i=0; i<n; i++){
            if(idx == -1 or guilty[idx] < guilty[i]){
                idx =  i;
            }
        }
        die[idx] = true;
    }

    if(idx != mafia) {
        for(int i = 0; i < n; i++) {
            if (die[i] or i == mafia) continue;
            ans = max(ans, mafia_game(mafia, i, 1));
        }
    }

    cout<<ans;
}