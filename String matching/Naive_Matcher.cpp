#include<iostream>
using namespace std;
#include<string>

bool check_pattern(string T, string P, int s){
    int m = P.length(),i;
    for(i=0;i<m;i++)
    {
        if(P[i]!=T[s+i+1])
            return false;
    }
    return true;

}

void naive_string_matcher(string T, string P){
    int n,m,s,i;
    n = T.length();
    m = P.length();
    s = -1;
    while(s < n-m)
    {
        if (check_pattern(T,P,s)){
            cout<<s+1<<endl;
            s += m;
        }
        else{
            s++;
        }
    }

}

int main(){
    string T, P;
    cin>>T>>P;
    naive_string_matcher(T,P);
}