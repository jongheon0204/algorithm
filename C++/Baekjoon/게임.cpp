// https://www.acmicpc.net/problem/1103
// 1103.게임 - 2020.10.04

#include <iostream>
#include <vector>
#include <string>
#include <set>
#define pii pair<int, int>
#define vi vector<int>

using namespace std;

// (n, m) : 보드의 (세로, 가로) 크기
int n, m;
int moveX[] = {0, 1, 0, -1}, moveY[] = {-1, 0, 1, 0};

// DFS 탐색 동안 방문한 좌표를 저장
set<pii> point;

// 보드의 범위를 벗어나는지 검사
bool isRange(int y, int x){
    return (0<= y && y < n) && (0 <= x && x < m);
}

// DFS 방식을 통해 문제 해결
// dis : 좌표를 그래프로 표시한 경우 dis(y, x)의 값은 단말 노드 깊이 - (y, x) 노드 깊이 + 1
int Move(const vector<string> & board, vector<vi> & dis, int y, int x){
    // 단말 노드와 길이, 보드에 적힌 숫자
    int ret = 0, v = board[y][x] - '0';
    for(int i=0; i<4; i++){
        // 다음번 좌표
        int nextY = (v * moveY[i]) + y;
        int nextX = (v * moveX[i]) + x;
        // 다음번 좌표가 범위를 벗어나거나 구멍인 경우 넘어간다
        if(!isRange(nextY, nextX) || board[nextY][nextX] == 'H') continue;
        // 이전에 나온 좌표일 경우 무한번 움직일 수 있다.
        if(point.find({nextY, nextX}) != point.end()) return -1;

        if(dis[nextY][nextX] != -1){
            ret = max(ret, dis[nextY][nextX]);
            continue;
        }

        // 다음번 좌표를 point에 삽입
        point.insert({nextY, nextX});
        // 이동 후 결과 값을 반환받는다 (결과 값이 -1인 경우 무한번 움직일 수 있다)
        int r = Move(board, dis, nextY, nextX);
        if(r == -1) return -1;
        // -1이 아닌 경우 더 큰 값을 구해야 한다.
        ret = max(ret, r);
        // 되돌아 오는 경우 이전에 저장한 좌표 제거
        point.erase(point.find({nextY, nextX}));
    }
    // dis 데이터 업데이트를 통해 중복 검사를 하지 않아도 된다
    dis[y][x] = ret + 1;
    return ret + 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m;
    // 보드 값 입력
    vector<string> board(n);
    for(int i=0; i<n; i++){
        cin>>board[i];
    }

    point.insert({0, 0});

    vector<vi> dis(n, vi(m, -1));
    dis[0][0] = 0;

    cout<<Move(board, dis, 0, 0);
}