#include<bits/stdc++.h>
using namespace std;

const int sz=1e5+50;
vector < int > x[sz];
int vis[sz],cnt,a[sz],mn;

void dfs(int u)
{
    vis[u]=1,cnt++;
    mn=min(mn,a[u]);
    for(auto i : x[u])
    {
        if(!vis[i])
            dfs(i);
    }
}

int main()
{
    memset(vis , 0 , sizeof vis);
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    while(q--)
    {
        int l , r;
        scanf("%d%d",&l,&r);
        x[l].push_back(r);
        x[r].push_back(l);
    }
    long long tot=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            cnt=0;
            mn=INT_MAX;
            dfs(i);
            tot+=mn;
        }
    }
    printf("%lld\n",tot);
}
