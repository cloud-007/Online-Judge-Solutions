#include<bits/stdc++.h>
using namespace std;

const int sz=3050;
vector  < int > x[sz];
map < int, int > cycle;
int vis[sz],comp[sz],par[sz],dis[sz],src,des;
bool ok=true;

void dfs(int u)
{
    vis[u]=1;
    for(auto i : x[u])
    {
        if(!vis[i] && ok)
        {
            par[i]=u;
            dfs(i);
        }
        else if(vis[i] && par[u]!=i)
        {
            src=u;
            des=i;
            ok=false;
            return;
        }
    }
}

void dfs1(int u)
{
    vis[u]=1;
    dis[u]=0;
    queue < int >q ;
    q.push(u);
    while(!q.empty())
    {
        u=q.front(),q.pop();
        for(auto i : x[u])
        {
            if(!vis[i])
            {
                q.push(i);
                dis[i]=dis[u]+1;
                vis[i]=1;
            }
        }
    }
}


int main()
{
    int n,u,v;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d",&u,&v);
        x[u].push_back(v);
        x[v].push_back(u);
    }
    memset(vis,0,sizeof vis);
    memset(dis,0,sizeof dis);
    dfs(1);
    memset(vis, 0, sizeof vis);
    vector < int > now;
    while(des !=src)
    {
        now.push_back(des);
        des=par[des];
        vis[des]=1;
    }
    vis[des]=1;
    now.push_back(des);
    for(auto i : now)
    {
        dfs1(i);
    }
    for(int i=1;i<=n;i++)
        printf("%d ",dis[i]);
}
