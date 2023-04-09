#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a;
    scanf("%d",&n);
    queue < int > q;
    vector < int > v;
    deque < int > dq;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(auto i : v)
    {
        if(a) dq.push_back(i),a=0;
        else dq.push_front(i),a=1;
    }
    for(auto i : dq) cout<<i<<" ";
    cout<<endl;
}
