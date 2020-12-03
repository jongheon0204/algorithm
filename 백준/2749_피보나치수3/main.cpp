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