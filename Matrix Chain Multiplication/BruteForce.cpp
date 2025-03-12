#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int MatrixChainOrder(vector<int>& p, int i, int j) {
    if (i == j) return 0;
    int minCost = INT_MAX;
    
    for (int k = i; k < j; k++) {
        int left = MatrixChainOrder(p, i, k);
        int right = MatrixChainOrder(p, k + 1, j);
        int cost = left + right + p[i - 1] * p[k] * p[j];
        minCost = min(minCost, cost);
    }
    return minCost;
}

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;
    vector<int> p(n + 1);

    cout << "Enter dimensions array: ";
    for (int i = 0; i <= n; i++) cin >> p[i];

    cout << "Minimum number of multiplications: " << MatrixChainOrder(p, 1, n) << endl;
    return 0;
}
