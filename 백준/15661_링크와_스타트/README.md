### [15661. 링크와 스타트](https://www.acmicpc.net/problem/15661)

축구를 위해 서로 팀을 공정하게 나눌려고 한다. i번 사람과 j번 사람이 팀을 이루면 해당 팀의 능력치는 a[i][j] + a[j][i]만큼 증가한다고 한다. 이때 양 팀의 능력치 차이의 최소 값을 구하는 문제이다.

사람은 최대 20명으로 제한되어 있기 때문에 DFS 방식을 통해 문제를 해결할 수 있다. 먼저 모든 사람이 한쪽 팀에 속한 상태에서 시작해서 한 사람씩 다른 팀으로 옮긴 후 능력치를 비교해 보는 방식을 사용하면 된다. 이때 사람이 옮겨진 팀의 능력치 합이 기존 팀의 능력치 합보다 크다면 DFS를 멈출 수 있다.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#define vi vector<int>
using namespace std;

vector<vi> stat;
vector<bool> left_team;
int ans = 0;
int left_stat = 0;
int right_stat = 0;

void find_min_dif(int depth){
    if(depth == stat.size()) return;
    int sum_left = 0, sum_right = 0;
    for(int i=0; i<left_team.size(); i++){
        if(left_team[i]) sum_left += (stat[depth][i] + stat[i][depth]);
        else sum_right += (stat[depth][i] + stat[i][depth]);
    }
    left_stat += sum_left;
    right_stat -= sum_right;
    left_team[depth] = true;
    ans = min(ans, abs(right_stat - left_stat));
    if(right_stat > left_stat) {
        find_min_dif(depth + 1);
    }
    left_team[depth] = true;
    right_stat += sum_right;
    left_stat -= sum_left;
    find_min_dif(depth + 1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin>>n;
    left_team = vector<bool>(n);
    stat = vector<vi>(n, vi(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>stat[i][j];
            right_stat += stat[i][j];
        }
    }

    ans = right_stat;
    find_min_dif(0);
    cout<<ans;
}
```
