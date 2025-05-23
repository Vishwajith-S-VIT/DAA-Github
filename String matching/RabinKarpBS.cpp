#include<iostream>
using namespace std;
#include<string>
#include<math.h>
#include <cctype>
#include <vector>

int valueOf(char ch){
    if(isupper(ch)){
        return ch - 'A' + 10;
    }
    if(islower(ch)){
        return ch - 'a' + 36;
    }
    if(isdigit(ch)){
        return ch - '0';
    }
    return -1;
}

bool check_characters(string T, string P, int s){
    int n,m,i;
    n = T.length();
    m = P.length();
    for(i=0;i<m;i++)
    {
        if(P[i]!=T[s+i+1])
            return false;
    }
    return true;
}

void rabin_karp_matcher(string T, string P, int d, int q){
    int n, m, h, p, t0, i,s, sp = 0;
    vector<int> arr;
    n = T.length();
    m = P.length();
    h = (int)pow(d,m-1)%q;
    //cout<<"h value is "<<h<<endl;
    p = 0;
    t0 = 0;
    for(i=0;i<m;i++)
    {
        p = (d*p + valueOf(P[i]))%q;
        t0 = (d*t0 + valueOf(T[i]))%q;
    }
    //cout << p << endl;
    for(s=-1;s<n-m;s++)
    {
        //cout<<p<<" "<<t0<<endl;
        if(p==t0)
        {
           if(check_characters(T,P,s)){
               arr.push_back(s+1);
           }
           else{
               sp++;
               //cout << "Spurious hit: " << s+1 << endl;
           }
        }
        if(s<=n-m){
            t0 = (d*(t0-valueOf(T[s+1])*h)+valueOf(T[s+m+1]))%q;
            if(t0 < 0){
                t0 += q;
            }
        }
    }
    cout << sp << endl;
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << endl;
    }
}

int main(){
    string T, P;
    int d,q;
    cin>>T>>P;
    cin>>d>>q;
    rabin_karp_matcher(T,P,d,q);
}