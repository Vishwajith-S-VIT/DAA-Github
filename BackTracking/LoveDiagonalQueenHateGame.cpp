#include <iostream>
#include <vector>
using namespace std;

int m, n, q, solutions = 0;

bool isSafe(vector<vector<int>>& board, int row, int col){
    if((row + 1 + col + 1) % 3 == 0){
        return false;
    }
    
    for(int i = 0; i < row; ++i){
        if(board[i][col] == 1){
            return false;
        }
    }
    
    for(int j = 0; j < col; ++j){
        if (board[row][j] == 1){
            return false;
        }
    }
    
    return true;
}

void solve(vector<vector<int>>& board, int row, int placed){
    if(placed == q){
        solutions++;
        return;
    }

    if(row >= m){
        return;
    }

    for(int col = 0; col < n; ++col){
        if(isSafe(board, row, col)){
            board[row][col] = 1;
            solve(board, row + 1, placed + 1);
            board[row][col] = 0;
        }
    }
    solve(board, row + 1, placed);
}

int main(){
    cin >> m >> n;
    q = min(m, n);

    vector<vector<int>> board(m, vector<int>(n, 0));
    solve(board, 0, 0);
    cout << solutions << endl;
    return 0;
}