#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int RodCut(int n, vector<int>& v, vector<int>& cuts) {
    if (n == 0) return 0;

    int maxRevenue = INT_MIN;
    int cutPosition = 0;
    for (int i = 1; i <= n; i++) {
        int revenue = v[i] + RodCut(n - i, v, cuts);
        if (revenue > maxRevenue) {
            maxRevenue = revenue;
            cutPosition = i;
        }
    }

    cuts[n] = cutPosition;
    return maxRevenue;
}

void PrintCuts(int n, vector<int>& cuts) {
    while (n > 0) {
        cout << cuts[n] << " ";
        n -= cuts[n];
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n + 1), cuts(n + 1);

    v[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    cout << "Maximum revenue: " << RodCut(n, v, cuts) << endl;
    cout << "Optimal cuts: ";
    PrintCuts(n, cuts);
    cout << endl;
    return 0;
}
