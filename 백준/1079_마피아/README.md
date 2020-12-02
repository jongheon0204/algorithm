### [1079. 마피아](https://www.acmicpc.net/problem/1079)

은진이는 홀로 마피아가 되어 남은 시민들을 죽이며 게임을 진행한다. 밤에는 마피아가 시민을 죽이며 낮에는 유죄 지수가 가장 큰 사람을 죽인다고 할 때 마피아는 최대 몇 번의 밤을 보낼 수 있는지 구하는 문제이다.

사람의 수 N은 16 이하의 자연수이다. 이것만 본다면 완전탐색으로 푸는데 16!의 시간이 걸려 해결하지 못하겠지만 마피아의 게임 특성상 밤에 죽을 시민을 선택한다면 낮에는 자동으로 시민이 죽기 때문에 완전탐색 방법으로 8!만에 문제를 해결할 수 있다.

```cpp
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
```