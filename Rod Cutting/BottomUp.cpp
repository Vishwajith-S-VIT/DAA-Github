#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void BottomUpRodCut(int n, vector<int>& v) {
    vector<int> r(n + 1, 0);
    vector<int> cuts(n + 1, 0);

    for (int j = 1; j <= n; j++) {
        int maxRevenue = INT_MIN;
        for (int i = 1; i <= j; i++) {
            int revenue = v[i] + r[j - i];
            if (revenue > maxRevenue) {
                maxRevenue = revenue;
                cuts[j] = i;
            }
        }
        r[j] = maxRevenue;
    }

    cout << "Maximum revenue: " << r[n] << endl;
    cout << "Optimal cuts: ";
    while (n > 0) {
        cout << cuts[n] << " ";
        n -= cuts[n];
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n + 1);

    v[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    BottomUpRodCut(n, v);
    return 0;
}