// https://www.acmicpc.net/problem/19939
// 19939 : 박 터트리기
#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin>>n>>k;

    int sum = (k * (k + 1)) / 2;
    if(n < sum){
        cout<<"-1";
    }else{
        n -= sum;
        cout<<(n % k ? k : k - 1);
    }
}
