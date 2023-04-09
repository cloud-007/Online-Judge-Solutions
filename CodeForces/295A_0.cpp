#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll sz=1e5+100;
ll temp[sz],a[sz],ex[sz];

struct R{ll l ,r,val;};
map < ll , R> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    memset(a,0,sizeof a);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    memset(temp,0,sizeof temp);
    memset(ex,0,sizeof ex);
    for(int i=1;i<=m;i++)
    {
        ll l,r,val;
        cin>>l>>r>>val;
        mp[i]={l,r,val};
    }
    for(int i=1;i<=q;i++)
    {
        ll l,r;
        cin>>l>>r;
        ex[l]++;
        ex[r+1]--;
    }
    for(int i=1;i<=m;i++)
    {
        ex[i]+=ex[i-1];
    }
    for(int i=1;i<=m;i++)
    {
        temp[mp[i].l]+=mp[i].val*ex[i];
        temp[mp[i].r+1]-=mp[i].val*ex[i];
    }
    for(int i=1;i<=n;i++)
{
temp[i]+=temp[i-1];
        a[i]+=temp[i];
        cout<<a[i]<<" ";
}
    cout<<endl;
}