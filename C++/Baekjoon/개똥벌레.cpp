// https://www.acmicpc.net/problem/3020
// 3020.개똥벌레 - 2020.11.24

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, h; cin>>n>>h;
    n /= 2;

    vector<int> ceil(h + 1), floor(h + 1);

    for(int i=0, v1, v2; i<n; i++){
        cin>>v1>>v2;
        floor[v1]++;
        ceil[v2]++;
    }

    int ceil_sum = 0, floor_sum = 0;
    for(int i=1; i<h; i++){
        floor_sum += floor[i];
    }

    int num = n * 2 + 1, cnt = 1;

    for(int i=1; i<=h; i++){
        int val = floor_sum + ceil_sum;
        if(val < num){
            num = val;
            cnt = 1;
        }else if(val == num){
            cnt++;
        }

        floor_sum -= floor[i];
        ceil_sum += ceil[h-i];
    }

    cout<<num<<' '<<cnt;
}
