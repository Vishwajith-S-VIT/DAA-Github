#include<iostream>
using namespace std;
#include<queue>
#include<set>

class activity{
    public:
        string name;
        int start;
        int finish;
        friend istream& operator >>(istream&,activity&);
        friend ostream& operator <<(ostream&,const activity&);
        bool operator <(const activity&) const;
};

istream& operator >>(istream& in, activity& a){
    in>>a.name>>a.start>>a.finish;
    return in;
}

ostream& operator <<(ostream& out, const activity& a){
    out<<a.name<<" ";
    return out;
}
// overload less than operator so that priority queue can be 
// constructed as desired. We intend to create a min priority
// queue based on finish time of activity
bool activity::operator <(const activity& a) const{
    return a.finish<finish;
}
void recursive_activity_selector(priority_queue<activity> &pq,vector<activity> &v){
    activity a;
    // take activity with minimum finish time
    a = pq.top();
    pq.pop();
    // select it and put it in vector
    v.push_back(a);
    // while there are activities in the priority queue
    // and start time of top activity in pq is less than
    // finish time of last chosen activity
    while(!pq.empty()&&pq.top().start<a.finish){
        // remove top activity from priority queue
        pq.pop();
    }
    if(!pq.empty()){
        // if priority queue is not empty then
        // make recursive call to the function
        recursive_activity_selector(pq,v);
    }
    else
        // if priority queue is empty then return
        return;
}
int main()
{
    priority_queue<activity> pq;
    int n,i;
    activity a;
    vector<activity> v;
    cin>>n;
    // read input activities and create a priority queue based on
    // finish time 
    for(i=0;i<n;i++){
        cin>>a;
        pq.push(a);
    }
    /////////////// BLOCK 1 //////////////////
    /*while(!pq.empty())
    {
        a = pq.top();
        pq.pop();
        cout<<a<<" ";
    }*/
    ///////////////// BLOCK 1 //////////////////////

    //////////////// BLOCK 2 //////////////////////
    // call recursive function to select activities from
    // the constructed priority queue and pass the vector
    // to store selected vector
    recursive_activity_selector(pq,v);
    cout<<"Selected activities "<<endl;
    for(auto a:v)
        cout<<a;
    //////////////// BLOCK 2 //////////////////////
}












