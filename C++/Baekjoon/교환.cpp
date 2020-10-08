// https://www.acmicpc.net/problem/1039
// 1039.교환 - 2020.10.05

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#define pii pair<int, int>

using namespace std;

// n : 정수, len : 정수의 자릿수, k : 연산 수행 횟수, ans = 정답
string n;
int len, k, ans = 0;
vector<set<string>> isVisit;

// 정렬 기준
bool cmp(const pii & a, const pii & b){
    if(a.first == b.first) return a.second > b.second;
    else return a.first > b.first;
}

// 문자열 n을 정수로 변환
int convert(){
    int ret = 0;
    for(int i=len - 1, d = 1; i>=0; i--, d *= 10){
        ret += (d * (n[i] - '0'));
    }
    return ret;
}

// Backtracking을 통해 문제를 해결
void dfs(int d){
    // 현재 깊이와 정수를 저장
    isVisit[d].insert(n);
    if(d == k){
        ans = max(ans, convert());
        return;
    }

    // (first, second) : (정수 값, 자릿 위치)
    vector<pii> num;
    for(int i=0; i<len; i++){
        num.push_back({n[i] - '0', i});
    }

    sort(num.begin(), num.end(), cmp);

    // 변화 여부 저장
    bool isChange = false;
    for(int i=0; i<num.size(); i++){
        for(int j=0; j<len; j++){
            // num[i].first 값보다 n[j]의 값이 크다면 교환 후 검사를 진행
            if(num[i].first >= n[j] - '0' && num[i].second > j){
                isChange = true;
                swap(n[num[i].second], n[j]);
                // 교환을 통해 얻은 정수가 이전에 조사한 정수라면 중복으로 조사를 할 필요가 없다
                if(isVisit[d+1].find(n) == isVisit[d+1].end()) {
                    dfs(d + 1);
                }
                swap(n[num[i].second], n[j]);
            }
        }
    }
    // 변화가 없을 시 일의 자리 정수와 십의 자리 정수 교환 후 검사
    if(!isChange){
        if((k - d) & 1) swap(n[len-2], n[len-1]);
        dfs(k);
        if((k - d) & 1) swap(n[len-2], n[len-1]);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>k;
    len = n.length();
    isVisit = vector<set<string>>(k+1);

    // 정수 자릿수 = 1 또는 정수 자릿수 = 2 이면서 일의 자리수가 0이면 연산을 할 수 없다.
    if(len == 1 || (len == 2 && n[1] == '0')){
        cout<<-1; return 0;
    }

    dfs(0);
    cout<<ans;

}