#include<bits/stdc++.h>
using namespace std;
const int sz=1e6+50;
int a[sz],vis[sz],par[sz];
vector < int > x[sz];
priority_queue < int > pq,pos;

void dfs(int u)
{
    pos.push(-par[a[u]]);
    pq.push(a[u]);
    vis[u]=1;
    for(auto i : x[u])
    {
        if(!vis[i])
            dfs(i);
    }
}

int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    memset(par , 0 , sizeof par);
    memset( a, 0 , sizeof a);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        par[a[i]]=i;
    }
    memset(vis,0 , sizeof vis);
    while(q--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        x[u].push_back(v);
        x[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
            while(!pq.empty())
            {
                int p=-pos.top();
                int val=pq.top();
                pos.pop(),pq.pop();
                a[p]=val;
            }
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    puts("");
}
