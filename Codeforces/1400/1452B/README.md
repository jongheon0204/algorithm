### [1452B. Toy Blocks](https://codeforces.com/problemset/problem/1452/B)

n개의 상자에 벽돌이 들어 있다. 벽돌을 상자에 추가한 후 임의의 상자를 선택하여 나머지 모든 상자에 적절하게 나누었을 때 모든 상자안에 들어 있는 벽돌의 개수를 동일하게 하기 위해서 필요한 벽돌의 최소 개수를 구하는 문제이다.

해당 문제는 각각의 상자에 몇 개의 벽돌을 추가해야 하는지 구하기 보다는 벽돌을 배분했을 때 최종적으로 각 상자에 들어 있는 벽돌의 최소 개수를 구하여 문제를 해결할 수 있다.

이때 벽돌의 최소 개수를 `상자에 들어있는 벽돌의 개수 중 가장 큰 값` 혹은 `현재 들어있는 벽돌의 총 합 / (상자의 개수 - 1)`이 될 수 있다.

```cpp
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        ll sum = 0, max_val = 0;
        for(int i=0; i<n; i++){
            ll val; cin>>val;
            sum += val;
            max_val = max(val, max_val);
        }
        ll k = max(max_val, sum / (n - 1) + (sum % (n - 1) ? 1 : 0));
        cout<<(k * (n-1) - sum)<<'\n';
    }
}
```
