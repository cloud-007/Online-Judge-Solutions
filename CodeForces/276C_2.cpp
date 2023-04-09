#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int sz=2e5+50;
int a,mp[sz];

int main()
{
    priority_queue < int > pq;
    int n,q,l,r;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        pq.push(a);
    }
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&l,&r);
        mp[l]++,mp[r+1]--;
    }
    vector < pair < int ,int >> vp;
    for(int i=1;i<=n;i++)
    {
        mp[i]+=mp[i-1];
        vp.push_back({mp[i],i});
    }
    sort(vp.rbegin(),vp.rend());
    ll sum=0;
    for(auto i : vp)
    {
        sum+=(ll)i.first*(ll)pq.top();
        pq.pop();
    }
    while(!pq.empty())
    {
        sum+=pq.top();
        pq.pop();
    }
    printf("%lld\n",sum);
}
