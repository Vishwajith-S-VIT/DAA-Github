#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void BULCS(string s1, string s2, vector<vector<int>>& c){
    int n = s1.length(), m = s2.length();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1]){
                c[i][j] = c[i-1][j-1] + 1;
            }
            else{
                int q1 = c[i-1][j], q2 = c[i][j-1];
                if(q1 >= q2){
                    c[i][j] = q1;
                }
                else{
                    c[i][j] = q2;
                }
            }
        }
    }
}

void AllLCS(string s1, string s2, int i, int j, string s, set<string>& All, vector<vector<int>> c){
    if(i == 0 || j == 0){
        reverse(s.begin(), s.end());
        All.insert(s);
        return;
    }
    if(s1[i-1] == s2[j-1]){
        AllLCS(s1, s2, i-1, j-1, s+s1[i-1], All, c);
    }
    else{
        if(c[i-1][j] == c[i][j]){
            AllLCS(s1, s2, i-1, j, s, All, c);
        }
        if(c[i][j-1] == c[i][j]){
            AllLCS(s1, s2, i, j-1, s, All, c);
        }
    }
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length(), m = s2.length();
    vector<vector<int>> c(n+1, vector<int>(m+1, -1));
    for(int i = 0; i <= n; i++){
        c[i][0] = 0;
    }
    for(int j = 0; j <= m; j++){
        c[0][j] = 0;
    }
    set<string> All;
    BULCS(s1, s2, c);
    AllLCS(s1, s2, n, m, "", All, c);
    for(string s: All){
        cout << s << endl;
    }
    return 0;
}