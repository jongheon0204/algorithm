### [14226. 이모티콘](https://www.acmicpc.net/problem/14226)

현재 이모티콘 1개가 있다. 3가지 연산이 있으며 각각 1초가 걸린다 할 때 S개의 이모티콘을 만든다고 할 때 최소 시간을 구하여라.

1. 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
2. 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
3. 화면에 있는 이모티콘 중 하나를 삭제한다.

이 문제는 화면과 클립보드에 있는 이모티콘의 개수를 저장하는 배열과 BFS 연산을 통해 문제를 해결할 수 있다.

```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define vi vector<int>
using namespace std;

struct emotion{
    int num;
    int time;
    int clip;
};

struct cmp{
    bool operator()(const emotion & a, const emotion & b){
        return a.time > b.time;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int s; cin>>s;
    // 이모티콘, 클립 수
    vector<vi> cnt(1001 , vi(1001 , s * s));

    // 개수, 시간
    priority_queue<emotion, vector<emotion>, cmp> que;
    que.push({1, 0, 0});
    cnt[1][0] = 0;
    while(!que.empty()){
        emotion cur = que.top();
        que.pop();
        if(cur.num == s) break;

        int next = cur.num - 1;
        if(next and cnt[next][cur.clip] > cur.time + 1 ){
            cnt[next][cur.clip] = cur.time + 1;
            que.push({next, cur.time + 1, cur.clip});
        }

        next = cur.num + cur.clip;
        if(next < cnt.size() and cnt[next][cur.clip] > cur.time + 1){
            cnt[next][cur.clip] = cur.time + 1;
            que.push({next, cur.time + 1, cur.clip});
        }

        next = cur.num * 2;
        if(next < cnt.size() and cnt[next][cur.num] >= cur.time + 2){
            cnt[next][cur.num] = cur.time + 2;
            que.push({next, cur.time + 2, cur.num});
        }
    }

    int ans = cnt[s][0];
    for(int i=1; i<cnt[s].size(); i++){
        ans = min(ans, cnt[s][i]);
    }
    cout<<ans;
}
```
