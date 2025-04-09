#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    unordered_map<int,int> arr2;
    int a=-1,b=-1,maxl=-999;
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum=0;

    for(int i=0;i<n;i++){
        sum+=arr[i];

        if(sum==0){
            maxl = i+1;
            a=0;
            b=i;
            break;
        }
        if(arr2.find(sum) != arr2.end()){
            if(i-arr2[sum]>maxl){
                maxl = i-arr2[sum]; 
                a = arr2[sum]+1;
                b=i;
            }
        }
        else{
            arr2[sum] = i;
        }
    }

    if(maxl>0){
        cout<<a+1<<" "<<b+1;
    }
    else{
    cout<<"-1";
    }

    return 0;
}