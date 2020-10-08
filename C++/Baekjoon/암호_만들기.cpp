// https://www.acmicpc.net/problem/1759
// 1759.암호 만들기 : 2020.10.08

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 생성된 암호가 모음 1개 이상, 자음 2개 이상을 포함하는지 검사
bool isRightCipher(const vector<char> & cipher){
    // 모음 개수 세기
    int cnt = 0;
    vector<char> vowel = {'a', 'e', 'i', 'o', 'u'};
    for(int i=0, idx = 0; i<vowel.size(); i++){
        for(int j=idx; j<cipher.size(); j++){
            if(cipher[j] == vowel[i]){
                cnt++;
                idx = j + 1;
            }
        }
    }
    return (cnt >= 1 && cipher.size() - cnt >= 2);
}

// BackTracking 기법을 사용하여 암호를 만든다
void Cipher(const vector<char> & alpha, vector<char> & cipher, const int & l, int s){
    if(cipher.size() == l) {
        if(isRightCipher(cipher)){
            for(int i=0; i<cipher.size(); i++){
                cout<<cipher[i];
            }cout<<'\n';
        }
    }
    // 추가해야 하는 문자열의 수와 남은 문자열의 수를 비교하여 암호를 만들지 못할 것 같으면 그만둔다
    if(l - cipher.size() > alpha.size() - s) return;

    for(int i=s; i<alpha.size(); i++){
        cipher.push_back(alpha[i]);
        Cipher(alpha, cipher, l, i+1);
        cipher.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int l, c; cin>>l>>c;
    vector<char> alpha(c), cipher;
    for(int i=0; i<c; i++){
        cin>>alpha[i];
    }
    sort(alpha.begin(), alpha.end());

    Cipher(alpha, cipher, l, 0);
}