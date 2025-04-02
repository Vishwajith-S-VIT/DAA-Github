#include <bits/stdc++.h>
using namespace std;

int isSafe(vector<vector<int>>& mat, int row, int col){
    int n = mat.size();
    int i, j;

    for (i = 0; i < row; i++)
        if (mat[i][col])
            return 0;

    for (i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if (mat[i][j])
            return 0;

    for (i = row-1, j = col+1; j < n && i >= 0; i--, j++)
        if (mat[i][j])
            return 0;

    return 1;
}

int placeQueens(int row, vector<vector<int>>& mat){
    int n = mat.size();

    if(row == n) return 1;

    for(int i = 0; i < n; i++){

        if(isSafe(mat, row, i)){
            mat[row][i] = 1;
            if(placeQueens(row + 1, mat)) 
                return 1;
            mat[row][i] = 0;
        }
    }
    return 0;
}

vector<int> nQueen(int n){
    vector<vector<int>> mat(n, vector<int>(n, 0));

    if(placeQueens(0, mat)){
        vector<int> ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j]){
                    ans.push_back(j + 1);
                }
            }
        }
        return ans;
    }
    else return {-1};
}

int main(){
    int n = 4;
    vector<int> ans = nQueen(n);
    for(auto i: ans){
        cout << i << " ";
    }
    return 0;
}
