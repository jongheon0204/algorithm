### [2749. 피보나치 수3](https://www.acmicpc.net/problem/2749)

피보나치 수의 n번째 값을 1,000,000으로 나눈 나머지를 출력하는 문제이다. n의 범위가 1,000,000,000,000,000,000 이므로 일반적인 방법으로는 해결할 수 없다.

하지만 피사노 주기를 이용하여 문제를 해결할 수 있는데 이는 피보나치 수열을 m으로 나눈 나머지가 주기를 이룬다는 특징이다.

실제로 계산시 m이 1,000,000인 경우 주기의 길이는 1,500,000 이며 이를 통해 문제를 해결할 수 있다.

```cpp
#include <iostream>
#include <vector>
#define SIZE 1500000
#define DIV 1000000
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n; cin>>n; n %= SIZE;
    int f1 = 0, f2 = 1, f3;
    while(--n){
        f3 = (f1 + f2) % DIV;
        f1 = f2;
        f2 = f3;
    }
    cout<<f2;
}
```