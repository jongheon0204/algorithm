// https://www.acmicpc.net/problem/3425
// 고스택 - 2020.10.02

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#define psi pair<string, int>
#define ll long long
#define MAX 1000000000

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while(1){
        // 프로그램 실행 시 명령어를 저장할 배열
        vector<psi> cmd;
        while(1){
            string a; cin>>a;
            if(a == "QUIT") return 0; // "QUIT" : 프로그램 종료
            if(a == "END") break; // "END" : 명령어 종료
            else if(a == "NUM"){ // 명령어가 NUM 이면 숫자를 별도로 입력받아야 한다
                int v; cin>>v;
                cmd.push_back({a, v});
            }
            else cmd.push_back({a, 0});
        }

        // n개 숫자에 대해 검사
        int n; cin>>n;
        while(n--){
            int v; cin>>v;
            stack<ll> sta;
            sta.push(v);

            // 숫자가 부족한 경우, 0으로 나눈 경우, 연산의 절대값이 10^9을 넘는 에러가 발생했는지 검사
            bool isError = false;

            for(int i=0; i<cmd.size(); i++){
                if(cmd[i].first == "NUM") sta.push(cmd[i].second);
                else if(sta.empty()){isError = true; break;}
                else if(cmd[i].first == "POP") sta.pop();
                else if(cmd[i].first == "INV") sta.top() = -sta.top();
                else if(cmd[i].first == "DUP") sta.push(sta.top());
                else{
                    if(sta.size() < 2){isError = true; break;}
                    ll f = sta.top(); sta.pop();
                    ll s = sta.top(); sta.pop();
                    if(cmd[i].first == "SWP"){
                        sta.push(f); sta.push(s);
                    }else if(cmd[i].first == "ADD"){
                        sta.push(f+s);
                    }else if(cmd[i].first == "SUB"){
                        sta.push(s - f);
                    }else if(cmd[i].first == "MUL"){
                        sta.push(f * s);
                    }else if(cmd[i].first == "DIV"){
                        if(!f){isError = true; break;}
                        sta.push(abs(s) / abs(f));
                        if(f * s < 0) sta.top() = -sta.top();
                    }else{
                        if(!f){isError = true; break;}
                        sta.push(s % f);
                    }
                }
                // 절대 값이 10^9이 넘는 값이 나온 경우 에러 발생
                if(!sta.empty() && abs(sta.top()) > MAX){
                    isError = true;
                    break;
                }
            }
            // 에러가 발생 했거나 프로그램 종료 시 값이 1개가 아닌 경우 ERROR를 출력하며, 이외에는 고스택에 남아있는 값을 출력한다
            if(isError || sta.size() != 1){
                cout<<"ERROR\n";
            }else{
                cout<<sta.top()<<'\n';
            }
        }
        cout<<'\n';
    }
}