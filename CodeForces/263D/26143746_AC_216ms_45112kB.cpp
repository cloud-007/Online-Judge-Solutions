#include<bits/stdc++.h>
using namespace std;

const int sz=1e5+50;
vector < int > x[sz];
int par[sz],n,m,k,u,v,done=0,vis[sz];

void cyc(int u,int v)
{
    vector < int > ans;
    while(true)
    {
        ans.push_back(u);
        if(u==v)
            break;
        u=par[u];
    }
    if(ans.back()==0)
        ans.pop_back();
    if(ans.size()>k)
    {
        printf("%d\n",ans.size());
        for(auto i : ans)
            printf("%d ",i);
        printf("\n");
        done=1;
        return;
    }
}

void dfs(int u)
{
    queue < int > q;
    vis[u]=1;
    q.push(u);
    while(!q.empty())
    {
        if(done)return;
        u=q.front();
        q.pop();
        for(auto i : x[u])
        {
            if(vis[i] && par[u]!=i && !done)
            {
                cyc(u,i);
            }
            else if(!vis[i])
            {
                vis[i]=1;
                par[i]=u;
                dfs(i);
            }
        }
    }
}

int main()
{
    memset(vis, 0, sizeof vis);
    scanf("%d%d%d",&n,&m,&k);
    while(m--)
    {
        scanf("%d%d",&u,&v);
        x[u].push_back(v);
        x[v].push_back(u);
    }
    dfs(1);
}
