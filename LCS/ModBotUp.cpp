#include <iostream>
#include <vector>
using namespace std;

int ModBotUpLCS(string s1, string s2){
    int n = s1.length(), m = s2.length();
    vector<int> current(m+1, 0);
    vector<int> previous(m+1, 0);
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1]){
                current[j] = previous[j-1] + 1;
            }
            else{
                int q1 = previous[j], q2 = current[j-1];
                if(q1 > q2){
                    current[j] = q1;
                }
                else{
                    current[j] = q2;
                }
            }
        }
        previous = current;
    }
    return current[m];
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int op = ModBotUpLCS(s1, s2);
    cout << op << endl;
    return 0;
}