#include <iostream>
#include <cmath>
#define SIZE 400000
#define uc unsigned char
#define ll long long

uc seive[(SIZE + 7) >> 3];

bool isPrime(int n){
    return seive[n>>3] & (1 << (n&7));
}

void setComposite(int n){
    seive[n>>3] &= ~(1 << (n & 7));
}

void init(){
    memset(seive, 255, sizeof(seive));
    setComposite(0);
    setComposite(1);
    for(int i=2, sqrtn = (int)sqrt(SIZE); i<=sqrtn; i++){
        if(isPrime(i)){
            for(int j=i*i; j<=SIZE; j += i){
                setComposite(j);
            }
        }
    }
}

