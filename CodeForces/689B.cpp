#include<bits/stdc++.h>
using namespace std;

const int sz=2e5+50;
vector < int > x[sz];
int vis[sz],dis[sz],a[sz];

void bfs(int u)
{
    vis[u]=1;
    dis[u]=0;
    queue < int > q;
    q.push(u);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(auto i : x[u])
        {
            if(!vis[i])
            {
                vis[i]=1;
                dis[i]=dis[u]+1;
                q.push(i);
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        x[i].push_back(a[i]);
        if(i+1<=n)
            x[i].push_back(i+1),x[i+1].push_back(i);
    }
    memset(vis , 0 , sizeof vis);
    memset(dis , 0 , sizeof dis);
    bfs(1);
    for(int i=1;i<=n;i++)printf("%d ",dis[i]);
}
