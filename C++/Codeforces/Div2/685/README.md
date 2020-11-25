### [A. Subtract or Divide](https://codeforces.com/contest/1451/problem/A)

한 번의 연산으로 n을 n의 제수로 나누거나 1을 뺄 수 있다. 이때 정수 n은 최소 몇 번의 연산으로 1을 만들 수 있는지를 푸는 문제이다.

이 문제는 n이 짝수인 경우 n을 2로 만든 후 1을 빼는 방식으로 2번의 연산으로 해결할 수 있으며 n이 홀수인 경우 n을 짝수로 만든 후 앞의 과정을 진행하여 최대 3번의 연산으로 원하는 값을 도출해 낼 수 있다.

```cpp
#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin>>tc;
    while(tc--){
        int n; cin>>n;
        if(n == 1){
            cout<<"0\n";
        }else if(n == 2){
            cout<<"1\n";
        }else if(n == 3 || !(n & 1)){
            cout<<"2\n";
        }else{
            cout<<"3\n";
        }
    }
}
```

### [B. Non-Substring Subsequence](https://codeforces.com/contest/1451/problem/B)

0과 1로 이루어진 문자열 a와 부분 문자열 b가 주어질 때 a 문자열에서 b 문자열을 추출할 수 있는지 판단하는 문제이다(추출하는 경우 연속된 인덱스 값을 가지면 안된다)

b 문자열은 a 문자열 이기 때문에 b의 첫번째 문자와 마지막 문자를 a 문자열 에서 찾고 이때 길이가 b 문자열 보다 긴 경우 무조건 추출할 수 있다.

```cpp
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin>>tc;
    while(tc--){
        string s; int n, q;
        cin>>n>>q>>s;
        while(q--){
            int l, r; cin>>l>>r;
            l--; r--;

            int l_idx = 0, r_idx = n-1;
            while(l_idx < n && s[l_idx] != s[l]) l_idx++;
            while(r_idx >= 0 && s[r_idx] != s[r]) r_idx--;

            cout<<(r_idx - l_idx + 1 <= r - l + 1 ? "NO\n" : "YES\n");
        }
    }
}
```

### [C. String Equality](https://codeforces.com/contest/1451/problem/C)

문자열 a와 b가 주어질 때 다음의 연산을 통해 a를 b로 치환할 수 있는지 여부를 묻는 문제이다. 

1. 인덱스 i에 대해 $a_{i}와 a_{i+1}$의 값을 바꾼다. 

2. 인덱스 i와 정수 k에 대해 $a_{i}, a_{i+1}, ... , a_{i+k-1}$값이 모두 같은 경우 알파벳을 1 증가시킨다.

이 문제는 알파벳 순서와 상관 없이 개수를 비교하며 문제를 해결할 수 있다.

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#define SIZE 26
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin>>tc;
    while(tc--){
        int n, k; cin>>n>>k;
        string a, b; cin>>a>>b;

        vector<int> a_alph(SIZE), b_alph(SIZE);

        for(int i=0; i<n; i++){
            a_alph[a[i] - 'a']++;
            b_alph[b[i] - 'a']++;
        }

        bool isConvertable = true;

        for(int i=0; i<SIZE - 1; i++){
            while(a_alph[i] > b_alph[i]){
                a_alph[i] -= k;
                a_alph[i+1] += k;
            }
            if(a_alph[i] < b_alph[i]){
                isConvertable = false;
                break;
            }
        }

        if(a_alph[SIZE - 1] != b_alph[SIZE - 1]){
            isConvertable = false;
        }

        cout<<(isConvertable ? "Yes\n" : "No\n");
    }
}
```

### [D. Circle Game](https://codeforces.com/contest/1451/problem/D)

(0, 0)에서 출발하여 한 번에 x의 양의 방향 혹은 y의 양의 방향으로 k 만큼 움직이는 게임을 한다. 두 사람이 번갈아 가며 게임을 하며 (x, y)와 원점의 거리가 d보다 큰 경우 게임에 진다고 할 때 두 사람 중 누가 이기는 지 구하는 게임이다.

두 사람 모두 최적의 방법으로 게임을 진행한다고 할 때 y 값이 크면 x의 값을 증가시키고 x의 값이 큰 경우 y의 값을 증가시키는 방향으로 게임을 진행할 수 있다.

```cpp
#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin>>tc;
    while(tc--){
        ll d, k, cnt = 0, x = 0, y = 0; cin>>d>>k;
        d *= d;

        while(++cnt){
            if(x >= y) {
                if (pow(y + k, 2) + pow(x, 2) <= d) {
                    y += k;
                }else break;
            }else{
                if(pow(y, 2) + pow(x + k, 2) <= d){
                    x += k;
                }
                else break;
            }
        }

        cout<<(cnt & 1 ? "Utkarsh\n" : "Ashish\n");
    }
}
```