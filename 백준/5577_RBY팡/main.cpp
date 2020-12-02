#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
using namespace std;

int rby_pang(const vector<pii> & ball, int left, int right){
    int cnt = 0;
    if(!ball[left].second) left--;
    if(!ball[right].second) right++;

    while(left >= 0 and right < ball.size()){
        if(ball[right].first == ball[left].first){
            int sum = ball[right].second + ball[left].second;
            if(sum < 4) break;
            cnt += sum;
            right++;
            left--;
        }else if(ball[right].second >= 4){
            cnt += ball[right].second;
            right++;
        }else if(ball[left].second >= 4){
            cnt += ball[left].second;
            left--;
        }else break;
    }

    while(left >= 0 && ball[left].second >= 4){
        cnt += ball[left--].second;
    }

    while(right < ball.size() && ball[right].second >= 4){
        cnt += ball[right++].second;
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector<pii> ball;
    int n; cin>>n;
    for(int i=0, color; i<n; i++){
        cin>>color;
        if(ball.empty() or ball.back().first != color){
            ball.push_back({color, 1});
        }else{
            ball.back().second++;
        }
    }

    int ans = n;
    for(int i=0; i<ball.size(); i++){
        if(i){
            ball[i].second--;
            ball[i-1].second++;
            ans = min(ans, n - rby_pang(ball, i-1, i));
            ball[i].second++;
            ball[i-1].second--;
        }
        if(i != ball.size() - 1){
            ball[i].second--;
            ball[i+1].second++;
            ans = min(ans, n - rby_pang(ball, i, i+1));
            ball[i].second++;
            ball[i+1].second--;
        }
    }
    cout<<ans;
}