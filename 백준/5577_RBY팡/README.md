### [5577. RBY 팡](https://www.acmicpc.net/problem/5577)

N개의 공이 붙어 있으며 동일한 색의 공이 4개 이상 연속적으로 위치하면 사라지는 게임이 있다. N개의 공들 중 단 한 개의 공 색을 변경한 후 남아있는 공의 최솟값을 구하는 문제이다.

이 문제는 초기 값에서 동일한 색을 가지고 있으며 연속적으로 위치한 공들을 하나의 그룹으로 묶는다. 이후 해당 그룹의 가장 위에 있는 공을 그 위에 있는 그룹의 색으로 변경한 후 최종적으로 남는 공의 개수를 센 후 해당 그룹의 가장 아래에 있는 공을 그 아래 있는 그룹의 색으로 변경한 후 최종적으로 남는 공의 개수를 세는 방법으로 문제를 해결할 수 있다.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
using namespace std;

int rby_pang(const vector<pii> & ball, int left, int right){
    int cnt = 0;
    if(!ball[left].second) left--;
    if(!ball[right].second) right++;

    while(left >= 0 and right < ball.size()){
        if(ball[right].first == ball[left].first){
            int sum = ball[right].second + ball[left].second;
            if(sum < 4) break;
            cnt += sum;
            right++;
            left--;
        }else if(ball[right].second >= 4){
            cnt += ball[right].second;
            right++;
        }else if(ball[left].second >= 4){
            cnt += ball[left].second;
            left--;
        }else break;
    }

    while(left >= 0 && ball[left].second >= 4){
        cnt += ball[left--].second;
    }

    while(right < ball.size() && ball[right].second >= 4){
        cnt += ball[right++].second;
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector<pii> ball;
    int n; cin>>n;
    for(int i=0, color; i<n; i++){
        cin>>color;
        if(ball.empty() or ball.back().first != color){
            ball.push_back({color, 1});
        }else{
            ball.back().second++;
        }
    }

    int ans = n;
    for(int i=0; i<ball.size(); i++){
        if(i){
            ball[i].second--;
            ball[i-1].second++;
            ans = min(ans, n - rby_pang(ball, i-1, i));
            ball[i].second++;
            ball[i-1].second--;
        }
        if(i != ball.size() - 1){
            ball[i].second--;
            ball[i+1].second++;
            ans = min(ans, n - rby_pang(ball, i, i+1));
            ball[i].second++;
            ball[i+1].second--;
        }
    }
    cout<<ans;
}
```