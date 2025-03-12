#include <iostream>
#include <vector>
using namespace std;

int TopDownLCS(string s1, string s2, int n1, int n2, vector<vector<int>>& c){
    if(n1 == 0 || n2 == 0){
        return 0;
    }
    if(c[n1][n2] != -1){
        return c[n1][n2];
    }
    if(s1[n1 - 1] == s2[n2 - 1]) {
        c[n1][n2] = 1 + TopDownLCS(s1, s2, n1 - 1, n2 - 1, c);
    } 
    else{
        int x1 = TopDownLCS(s1, s2, n1, n2 - 1, c);
        int x2 = TopDownLCS(s1, s2, n1 - 1, n2, c);
        c[n1][n2] = (x1 > x2) ? x1 : x2;
    }
    return c[n1][n2];
}

string StringLCS(string s1, string s2, vector<vector<int>>& c){
    int i = s1.length(), j = s2.length();
    string lcs;
    while(i > 0 && j > 0){
        if (s1[i - 1] == s2[j - 1]){
            lcs = s1[i - 1] + lcs;
            i--;
            j--;
        }
        else if (c[i - 1][j] >= c[i][j - 1]){
            i--;
        }
        else{
            j--;
        }
    }
    return lcs;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length(), m = s2.length();
    vector<vector<int>> c(n + 1, vector<int>(m + 1, -1));

    for (int i = 0; i <= n; i++){
        c[i][0] = 0;
    }
    for (int j = 0; j <= m; j++){
        c[0][j] = 0;
    }

    int op = TopDownLCS(s1, s2, n, m, c);
    string s = StringLCS(s1, s2, c);
    cout << op << endl << s << endl;
    return 0;
}