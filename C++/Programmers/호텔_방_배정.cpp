// 2019 카카오 개발자 겨울 인턴십 : 호텔 방 배정 Level4
// https://programmers.co.kr/learn/courses/30/lessons/64063?language=cpp

// i번 방부터 j번 방까지 연속적으로 사용중인 경우 map의 key 값은 i, value 값은 j가 되도록 하여 문제를 해결한다.
// 이후 j 값을 갱신해 주는 과정이 필요하다

#include <string>
#include <vector>
#include <map>
#define ll long long
#define mll map<ll, ll>

using namespace std;

mll match;

// value + 1번 방이 현재 비어 있는지 검사 후 비어 있다면 해당 방을 배정
// 비어있지 않다면 value + 1가 key인 노드의 value + 1을 다시 검사하는 방식
// 검사를 진행하면서 값을 계속 갱신해야 한다.
int get_root_num(mll::iterator iter){
    mll::iterator next = match.find(iter->second + 1);
    if(next == match.end()){
        match.insert({iter->second + 1, iter->second + 1});
        return iter->second + 1;
    }else{
        int num = get_root_num(next);
        next->second = num;
        iter->second = num;
        return num;
    }
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<ll> ans(room_number.size());
    for(int i=0; i<room_number.size(); i++){
        mll::iterator iter = match.find(room_number[i]);
        // 현재 방이 비어있는 경우 추가를 해준다
        if(iter == match.end()){
            match.insert({room_number[i], room_number[i]});
            ans[i] = room_number[i];
        }else{
            // 방을 사용중인 경우 num 값을 구해 새로운 방을 배정
            int num = get_root_num(iter);
            ans[i] = num;
        }
    }
    return ans;
}