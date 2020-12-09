### [1453B. Suffix Operations](https://codeforces.com/problemset/problem/1453/B)

다음과 같은 두 종류의 연산이 가능한 n개의 정수가 존재한다.

1. a[i] ~ a[n]의 모든 값에 1을 더한다.
2. a[i] ~ a[n]의 모든 값에 1을 뺀다.

연산전 특정 값 a[i]를 원하는 값으로 변경할 수 있다 할 때 n개의 정수 값이 모두 같도록 할 때 필요한 최소 연산 횟수를 구하는 문제이다.

값을 변경하지 않는 경우 필요한 연산 횟수는 `abs(a[i] - a[i-1])의 합`이다. 이때 특정 값을 변경한다면 위의 값에 `-abs(a[i] - a[i-1]) - abs(a[i+1] - a[i]) + abs(a[i+1] - a[i-1])`을 해주면 된다.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        vector<int> data(n);
        ll sum = 0;
        for(int i=0; i<n; i++){
            cin>>data[i];
            if(i) sum += abs(data[i] - data[i-1]);
        }
        ll ans = sum;
        ans = min(ans, sum - abs(data[0] - data[1]));
        ans = min(ans, sum - abs(data[n-1] - data[n-2]));
        for(int i=1; i<n-1; i++){
            ans = min(ans, sum - abs(data[i] - data[i-1]) - abs(data[i+1] - data[i]) + abs(data[i+1] - data[i-1]));
        }
        cout<<ans<<'\n';
    }
}
```
