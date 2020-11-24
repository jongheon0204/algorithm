// https://www.acmicpc.net/problem/2014
// 2014.소수의 곱 - 2020.11.24

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> pq;

    int k, n; cin>>k>>n;
    vector<int> prime(k);
    for(int i=0; i<k; i++){
        cin>>prime[i];
        pq.push(prime[i]);
    }

    ll top = 0;
    while(--n){
        top = pq.top();
        while(!pq.empty() && top == pq.top()) pq.pop();

        for(int i=0; i<k; i++){
            ll val = top * prime[i];
            if(val > INT_MAX) break;
            pq.push(top * prime[i]);
        }
    }

    cout<<pq.top();
}