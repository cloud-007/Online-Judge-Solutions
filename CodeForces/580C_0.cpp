#include<bits/stdc++.h>
using namespace std;

const int sz=1e5+50;
vector < int > x[sz];
int vis[sz],dis[sz],a[sz];

void dfs(int u,int mx)
{
    vis[u]=1;
    for(auto i : x[u])
    {
        if(!vis[i])
        {
            if(a[i])
            {
                dis[i]=dis[u]+1;
                if(dis[i]<=mx)
                {
                    dfs(i,mx);
                }
                else
                {
                    dis[i]=-1;
                }
            }
            else
            {
                dis[i]=0;
                dfs(i,mx);
            }
        }
    }
}

int main()
{
    int n,m,u,v;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    memset(dis,-1,sizeof dis);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        x[u].push_back(v);
        x[v].push_back(u);
    }
    if(a[1])dis[1]=1;
    else dis[1]=0;
    dfs(1,m);
    int cnt=0;
    for(int i=2;i<=n;i++)
    {
        if(x[i].size()==1 && vis[i])
        {
            cnt++;
        }
    }
    printf("%d\n",cnt);
}
