#include<bits/stdc++.h>
using namespace std;

int vis[10][10];
long long dis[10][10];
int fx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int fy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
long long res=0;

void dfs(int sx,int sy,int x,int y)
{
    vis[sx][sy]=1;
    for(int i=0; i<8; i++)
    {
        int tx=sx+fx[i];
        int ty=sy+fy[i];
        if(tx>=0 && ty>=0 && tx<8 && ty<8)
        {
            int now=dis[sx][sy]+(sx*tx)+(sy*ty);
            if(now<dis[tx][ty])
            {
                dis[tx][ty]=now;
                if(tx==x && ty==y)
                {
                    res=min(res,dis[tx][ty]);
                }
                else
                    dfs(tx,ty,x,y);
            }
        }
    }
}

int main()
{
    int a,b,c,d;
    while(cin>>a>>b>>c>>d)
    {
        res=9999999999999999;
        memset(vis,0,sizeof vis);
        for(int i=0; i<8; i++)
            for(int j=0; j<8; j++)
                dis[i][j]=9999999999999999;
        dis[a][b]=0;
        if(a==c && b==d)
            res=0;
        else
            dfs(a,b,c,d);
        if(res==9999999999999999)
            res=-1;
        cout<<res<<endl;
    }
}
