#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int sz=2e5+100;
ll ans[sz],tree[sz*3];
int temp[sz],l[sz+5],r[sz+5];

int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    int a;
    memset(ans,0,sizeof ans);
    priority_queue< int > pq;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        pq.push(a);
    }
    memset(temp,0,sizeof temp);
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        temp[l[i]]+=1;
        temp[r[i]+1]-=1;
    }
    temp[0]=0;
    vector < pair < int , int >> vp;
    for(int i=1;i<=n;i++)
    {
        temp[i]+=temp[i-1];
        vp.push_back({temp[i],i});
    }
    sort(vp.rbegin(),vp.rend());
    ll sum=0;
    for(auto i : vp)
    {
        sum+=((ll)i.first*(ll)pq.top());
        pq.pop();
    }
    while(!pq.empty())
    {
        sum+=(ll)pq.top();
        pq.pop();
    }
    cout<<sum<<endl;
}
