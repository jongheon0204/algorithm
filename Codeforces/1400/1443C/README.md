### [1443C. The Delivery Dilemma](https://codeforces.com/problemset/problem/1443/C)

n개의 식당에 대해 각 식당에서 배달이 오는데 걸리는 시간 a[i]와 직접 가져오는 시간 b[i]가 주어진다. 이때 각 식당에서 오는 배달은 동시에 올 수 있으며 직접 가져오는 시간은 한 식당 씩 방문해야 할 때 모든 음식을 가져오는데 걸리는 최소 시간을 구하는 문제이다.

해당 문제는 특정 시간을 정해 놓고 해당 시간 안에 배달하지 못하는 식당에서 직접 가져오는 시간을 모두 더하여 문제를 해결할 수 있다. 이때 특정 시간을 정하는 방법은 이분 탐색을 통해 값을 제한할 수 있다.

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
        vector<int> delivery(n);
        vector<int> pick_up(n);
        vector<int> idx;

        ll left = 0;
        ll right = 0;

        for(int i=0; i<n; i++) cin>>delivery[i];
        for(int i=0; i<n; i++){
            cin>>pick_up[i];
            if(delivery[i] > pick_up[i]){
                idx.push_back(i);
            }else{
                left = max(left, (ll)delivery[i]);
            }
            right += pick_up[i];
        }

        ll ans = right;
        while(left <= right){
            ll mid = (left + right) / 2;
            ll sum = 0;
            for(int i=0; i<idx.size(); i++){
                if(delivery[idx[i]] > mid){
                    sum += pick_up[idx[i]];
                }
            }
            if(sum <= mid){
                ans = min(ans, mid);
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        cout<<ans<<'\n';
    }
}
```

```java
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int tc = Integer.parseInt(br.readLine());
        while(tc-- != 0){
            int n = Integer.parseInt(br.readLine());

            int [] delivery = new int[n];
            int [] pickUp = new int[n];

            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i=0; st.hasMoreTokens(); i++){
                delivery[i] = Integer.parseInt(st.nextToken());
            }

            st = new StringTokenizer(br.readLine());
            for(int i=0; st.hasMoreTokens(); i++){
                pickUp[i] = Integer.parseInt(st.nextToken());
            }

            long left = 0;
            long right = 0;
            List<Integer> idx = new ArrayList<>();
            for(int i=0; i<n; i++){
                if(delivery[i] > pickUp[i]){
                    idx.add(i);
                }else{
                    left = Math.max(left, delivery[i]);
                }
                right += pickUp[i];
            }

            long ans = right;
            while(left <= right){
                long mid = (left + right) / 2;
                long sum = 0;
                for (Integer i : idx) {
                    if (delivery[i] > mid) {
                        sum += pickUp[i];
                    }
                }
                if(sum > mid){
                    left = mid + 1;
                }else{
                    ans = Math.min(ans, mid);
                    right = mid - 1;
                }
            }

            bw.write("" + ans +"\n");
        }
        bw.flush();
        bw.close();
        br.close();
    }
}
```
