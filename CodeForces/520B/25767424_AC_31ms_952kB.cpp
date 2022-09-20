#include<bits/stdc++.h>
using namespace std;

const int sz=1e5+50;
int vis[sz],dis[sz];
int bfs(int s,int d)
{
    vis[s]=1;
    dis[s]=0;
    queue < int > q;
    q.push(s);
    while(!q.empty())
    {
        s=q.front();
        if(s==d)return dis[s];
        q.pop();
        if(!vis[s*2] && s<d)
        {
            q.push(s*2);
            dis[s*2]=dis[s]+1;
            vis[s*2]=1;
        }
        if(!vis[s-1] && s>0)
        {
            vis[s-1]=1;
            dis[s-1]=dis[s]+1;
            q.push(s-1);
        }
    }
}

int main()
{
    memset(vis,0,sizeof vis);
    memset(dis,0,sizeof dis);
    int src,des;
    scanf("%d%d",&src,&des);
    printf("%d",bfs(src,des));
}
