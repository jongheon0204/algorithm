// https://www.acmicpc.net/problem/1339
// 1339.단어 수학 : 2020.10.11

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// 알파벳 개수
#define SIZE 26

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, ans = 0; cin>>n;

    // ABC -> 100A + 10B + C, BCA -> 100B + 10C + A
    // 모든 문자를 위와 같은 식으로 변환한 후 값이 큰 문자열부터 차례대로 값을 대입
    vector<int> alpha(SIZE);
    for(int i=0; i<n; i++){
        string word; cin>>word;
        for(int j=word.length()-1, d=1; j>=0; j--, d*=10){
            alpha[word[j] - 'A'] += d;
        }
    }

    sort(alpha.begin(), alpha.end());
    for(int i=alpha.size() - 1, j=9; i>=0 && alpha[i]; i--, j--){
        ans += (alpha[i] * j);
    }
    cout<<ans;
}