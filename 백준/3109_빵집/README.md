### [3109. 빵집](https://www.acmicpc.net/problem/3109)

첫번째 열에서 마지막 열까지 파이프라인을 여러개 연결하려고 한다. 이때 파이프라인 경로는 겹칠 수 없고 건물에 파이프를 놓을 수 없다고 할 때 최대 몇 개의 파이프라인이 설치가 가능한지 푸는 문제이다.

이 문제는 DFS로 해결할 수 있으며 첫번재 열의 위의 행에서 탐색을 시작할 때 마지막 열의 최대한 위의 행과 연결이 되도록 문제를 해결하면 된다. 또한 한번 탐색에 실패한 구역은 다른 파이프라인 연결에서도 실패하기 때문에 다시 탐색 하지 않도록 표시해 둬야 한다.

```cpp
#include <iostream>
#include <vector>
#define vc vector<char>
using namespace std;

bool isRange(int y, int r){
    return 0 <= y and y < r;
}

bool find_route(vector<vc> & board, int y, int x){
    if(!isRange(y, board.size()) or board[y][x] == 'x') return false;
    if(x == board[0].size() - 1){
        board[y][x] = 'x';
        return true;
    }

    board[y][x] = 'x';
    for(int j=-1; j<=1; j++){
        if(find_route(board, y+j, x+1))
            return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int r, c; cin>>r>>c;
    vector<vc> board(r, vc(c));

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>board[i][j];
        }
    }

    int ans = 0;
    for(int i=0; i<r; i++){
        ans += find_route(board, i, 0);
    }

    cout<<ans;
}
```