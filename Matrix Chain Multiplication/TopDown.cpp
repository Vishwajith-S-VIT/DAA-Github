#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int MatrixChainOrder(vector<int>& p, int i, int j, vector<vector<int>>& c, vector<vector<int>>& s) {
    if (i == j) return 0;
    if (c[i][j] != -1) return c[i][j];

    int minCost = INT_MAX;
    for (int k = i; k < j; k++) {
        int left = MatrixChainOrder(p, i, k, c, s);
        int right = MatrixChainOrder(p, k + 1, j, c, s);
        int cost = left + right + p[i - 1] * p[k] * p[j];

        if (cost < minCost) {
            minCost = cost;
            s[i][j] = k;
        }
    }
    c[i][j] = minCost;
    return minCost;
}

void PrintOptimalParens(int i, int j, vector<vector<int>>& s) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        PrintOptimalParens(i, s[i][j], s);
        PrintOptimalParens(s[i][j] + 1, j, s);
        cout << ")";
    }
}

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;
    vector<int> p(n + 1);
    
    cout << "Enter dimensions array: ";
    for (int i = 0; i <= n; i++) cin >> p[i];
    vector<vector<int>> c(n + 1, vector<int>(n + 1, -1));
    vector<vector<int>> s(n + 1, vector<int>(n + 1, -1));
    
    cout << "Minimum number of multiplications: " << MatrixChainOrder(p, 1, n, c, s) << endl;
    
    cout << "Optimal Parenthesization: ";
    PrintOptimalParens(1, n, s);
    cout << endl;
    return 0;
}
