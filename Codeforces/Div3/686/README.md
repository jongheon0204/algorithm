### [A. Special Permutation](https://codeforces.com/contest/1454/problem/A)

1 ~ n을 한 번씩 사용하고 i번 위치에 i의 값이 들어가지 않도록 배열을 만드는 문제이다. 

2부터 n까지 차례대로 출력 후 맨 마지막에 1을 출력하면 문제를 해결할 수 있다.

```cpp
#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        for(int i=2; i<=n; i++){
            cout<<i<<' ';
        }cout<<1<<'\n';
    }
}
```

### [B. Unique Bid Auction](https://codeforces.com/contest/1454/problem/B)

n명의 사람이 각자 하나의 값을 가진다. 유일한 값을 가진 사람들 중 최소 값을 가진 사람이 게임에 이긴다고 할 때 게임을 이기는 사람을 찾는 문제이다.

사람들이 가지고 있는 숫자를 센 후 만약 유일한 값을 가진 사람이 존재한다면 인덱스를 출력하면 된다.

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        vector<int> cnt(n+1), idx(n+1);
        for(int i=0, v; i<n; i++){
            cin>>v;
            cnt[v]++;
            idx[v] = i+1;
        }
        int ans = -1;
        for(int i=1; i<=n; i++){
            if(cnt[i] == 1){
                ans = idx[i];
                break;
            }
        }
        cout<<ans<<'\n';
    }
}
```

### [C. Sequence Transformation](https://codeforces.com/contest/1454/problem/C)

길이가 n인 배열이 주어질 때 배열을 이루는 원소의 값 하나를 선택한 후 다른 나머지 값들을 모두 없앤다고 한다. 특정 값 x 사이의 있는 원소들은 한 번에 제거가 가능하다고 할 때 최소 제거 횟수를 구하는 문제이다.

(예를 들어 배열이 1, 2, 4, 1, 5 라 할 때 특정 값을 1이라 하면 1 사이에 있는 2, 4를 한 번에 제거 하고 5를 제거하여 총 2번 만에 1만 남길 수 있다)

이는 연속 값을 제거하고 남은 값의 개수를 센 후 최소 값을 구하면 된다.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#define vi vector<int>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin>>tc;
    while(tc--){
        int n, idx = 0; cin>>n;
        vector<int> arr(n);
        vector<vi> cnt(n+1);
        for(int i=0; i<n; i++){
            cin>>arr[idx];
            if(!idx || arr[idx] != arr[idx-1]){
                cnt[arr[idx]].push_back(idx);
                idx++;
            }
        }
        int ans = idx;
        for(int i=1; i<cnt.size(); i++){
            if(cnt[i].empty()) continue;
            int val = cnt[i].size() + 1;
            if(cnt[i].back() == idx - 1) val--;
            if(!cnt[i][0]) val--;
            ans = min(ans, val);
        }
        cout<<ans<<'\n';
    }
}
```

### [D. Number into Sequence](https://codeforces.com/contest/1454/problem/D)

정수 n을 1보다 큰 숫자들로 나누어 a(1) * a(2) * a(3) * ... * a(k) = n로 나타내려 한다 이때 a(i)는 a(i-1)로 나누어 떨어지는 조건이 있을 때 k의 최대 값을 구하는 문제이다.

정수 n을 소인수 분해 하여 나온 소수의 지승 값을 계산하여 문제를 해결할 수 있다. 만약 지승 값이 2보다 작은 경우 나눌 수 없으며 2보다 큰 경우는 해당 값으로 계속해서 나눈 후 나머지 값을 출력해 주면 된다.

```cpp
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define ll long long
#define pli pair<ll, int>
using namespace std;
 
bool cmp(const pli & a, const pli & b){
    return a.second > b.second;
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin>>tc;
    while(tc--){
        ll n; cin>>n;
        ll sqrtn = (ll)sqrt(n);
        int cnt = 0, div = 0;
        for(ll i=2, v = n; v && i<=sqrtn; i++){
            int c = 0;
            while(!(v % i)){
                c++;
                v /= i;
            }
            if(c > cnt){
                cnt = c;
                div = i;
            }
        }
        if(cnt < 2){
            cout<<1<<'\n'<<n<<'\n';
        }else{
            cout<<cnt<<'\n';
            while(--cnt){
                cout<<div<<' ';
                n /= div;
            }cout<<n<<'\n';
        }
    }
}
```

### [E. Number of Simple Paths](https://codeforces.com/contest/1454/problem/E)

### [F. Array Partition](https://codeforces.com/contest/1454/problem/F)