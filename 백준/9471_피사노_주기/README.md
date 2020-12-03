### [9471. 피사노 주기](https://www.acmicpc.net/problem/9471)

피보나치 수열을 m으로 나눈 나머지는 주기를 이룬다. m이 주어질 때 주기의 길이를 구하는 문제이다.

피보나치 수열의 나머지가 0, 1로 연속되는 경우 그 이전까지의 값이 하나의 주기를 이루는 특징을 이용하여 문제를 해결할 수 있다.

```cpp
#include <iostream>
#include <vector>
#define SIZE 1000001
using namespace std;

int pisano(int div){
    int f1 = 0, f2 = 1, ret = 0;
    bool is_pre_zero = false;
    while(++ret){
        int f3 = (f1 + f2) % div;
        if(is_pre_zero){
            if(f3 == 1) break;
            else is_pre_zero = false;
        }
        if(!f3) is_pre_zero = true;
        f1 = f2;
        f2 = f3;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector<int> ans(SIZE);
    int tc; cin>>tc;
    while(tc--){
        int n, m; cin>>n>>m;
        if(!ans[m]) ans[m] = pisano(m);
        cout<<n<<' '<<ans[m]<<'\n';
    }
}
```