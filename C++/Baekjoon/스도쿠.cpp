// https://www.acmicpc.net/problem/2580
// 2580.스도쿠 : 2020.10.11

#include <iostream>
#include <vector>
#define pii pair<int,int>
#define vi vector<int>
#define SIZE 9

using namespace std;

// 스도쿠 판
vector<vi> sudoku(SIZE, vi(SIZE));
// 아직 채워지지 않은 좌표
vector<pii> point;

// depth 번째 채워지지 않은 좌표를 채운다
bool fillSudoku(int depth){
    // 모든 비어있는 좌표를 채운 경우 출력
    if(depth == point.size()){
        for(int i=0; i<SIZE; i++){
            for(int j=0; j<SIZE; j++){
                cout<<sudoku[i][j]<<' ';
            }cout<<'\n';
        }
        return true;
    }

    // 현재 검사하는 곳의 좌표
    int dy = point[depth].first, dx = point[depth].second;
    // i번째 숫자를 사용하고 있는지 저장
    vector<bool> isUsedNum(SIZE + 1);

    // 스도쿠 가로, 세로 검사
    for(int i=0; i<SIZE; i++){
        isUsedNum[sudoku[dy][i]] = true;
        isUsedNum[sudoku[i][dx]] = true;
    }

    int y = (dy / 3) * 3;
    int x = (dx / 3) * 3;

    // 3 x 3 칸 검사
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            isUsedNum[sudoku[y+i][j+x]] = true;
        }
    }

    // 넣을 수 있는 수를 가지고 검사
    for(int i=1; i<=SIZE; i++){
        if(!isUsedNum[i]){
            sudoku[dy][dx] = i;
            if(fillSudoku(depth + 1)) return true;
            sudoku[dy][dx] = 0;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            cin>>sudoku[i][j];
            if(!sudoku[i][j]){
                point.push_back({i, j});
            }
        }
    }

    fillSudoku(0);
}