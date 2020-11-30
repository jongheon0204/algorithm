### [1700. 멀티탭 스케줄링](https://www.acmicpc.net/problem/1700)

구멍이 n개인 멀티 탭과 k개의 전기 용품이 있다. 전기 용품의 사용 순서가 정해진다고 할 때 전기 용품을 사용하기 위해 최소 몇 번 플러그를 빼는지 구하는 문제이다.

OS에 페이지 교체 전략 중 최적(Optimal) 페이지 교체 방법이 있다. 바로 앞으로 가장 오랫동안 사용 되지 않을 페이지를 교체하는 전략이다. 가장 페이지 교체 수가 적은 전략이지만 프로세스가 앞으로 사용할 페이지를 알지 못하기에 구현이 불가능하다.

하지만 현재 문제는 사용 순서가 정해져 있기 때문에 이 알고리즘을 사용하여 문제를 해결할 수 있다.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k, ans = 0; cin>>n>>k;

		// 전기 용품 개수보다 멀티탭 구멍이 많다면 플러그를 뽑을 필요가 없다.
    if(n < k){
				// 전기 용품이 사용중인지 아닌지 저장
        vector<bool> is_used_plug(k + 1);
				// 어떤 전기 용품이 사용중인지와 전기 용품 순서 저장
        vector<int> multitap, plug(k);
        for(int i=0; i<k; i++){
            cin>>plug[i];
        }

        for(int i=0; i<k; i++){
						// 사용중인 전기 용품이라면 넘어가도 된다.
            if(is_used_plug[plug[i]]) continue;
						// 아직 멀티탭에 연결할 수 있는 경우
            if(multitap.size() < n){
                multitap.push_back(plug[i]);
                is_used_plug[plug[i]] = true;
            }else{
								// 현재 사용 중인 전기 용품 중 가장 나중에 사용하는 전기 용품 플러그를 제거한다.
                int dif = 0, c_idx = 0;
                for(int j=0; j<multitap.size(); j++){
                    int p = i + 1;
                    while(p < k and plug[p] != multitap[j]){
                        p++;
                    }
                    if(dif < (p - i)){
                        dif = p - i;
                        c_idx = j;
                    }
                }
                is_used_plug[multitap[c_idx]] = false;
                is_used_plug[plug[i]] = true;
                multitap[c_idx] = plug[i];
                ans++;
            }
        }
    }
    cout<<ans;
}
```