#include<bits/stdc++.h>
using namespace std;

struct R{
    int r,l,idx;
    bool operator < (R a )const{
        if(r==a.r)
            return idx>a.idx;
        return r<a.r;
    }
};

int main()
{
    int n,l,r;
    cin>>n;
    priority_queue < R > pq;
    for(int i=0;i<n;i++)
    {
        cin>>l>>r;
        pq.push({r,l,i});
    }
    while(!pq.empty())
        cout<<pq.top().l<<" "<<pq.top().r<<endl,pq.pop();

}
