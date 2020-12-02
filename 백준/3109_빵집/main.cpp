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