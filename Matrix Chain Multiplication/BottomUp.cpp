#include <iostream>
#include <vector>
#include <climits>
using namespace std;

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

void MatrixChainOrder(vector<int>& p, int n) {
    vector<vector<int>> c(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            c[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = c[i][k] + c[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < c[i][j]) {
                    c[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum number of multiplications: " << c[1][n] << endl;

    cout << "Optimal Parenthesization: ";
    PrintOptimalParens(1, n, s);
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;
    vector<int> p(n + 1);

    cout << "Enter dimensions array: ";
    for (int i = 0; i <= n; i++) cin >> p[i];

    if (n == 1){
        cout << "Minimum number of multiplications: 0" << endl;
        cout << "Optimal Parenthesization: A1" << endl;
        return 0;
    }

    MatrixChainOrder(p, n);
    return 0;
}
