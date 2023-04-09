#include<bits/stdc++.h>
using namespace std;

const int sz=1020;
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
char a[sz][sz];
int vis[sz][sz],dis[sz][sz],row,col;

bool valid(int tx,int ty)
{
    if(tx>=1 && ty>=1 && tx<=row && ty<=col &&  a[tx][ty]!='*')
        return true;
    return false;
}

void bfs(int sx,int sy)
{
    vis[sx][sy]=1;
    dis[sx][sy]=-1;
    int cnt=0;
    queue < pair < int , int >> q;
    q.push({sx,sy});
    while(!q.empty())
    {
        sx=q.front().first,sy=q.front().second;
        cnt=dis[sx][sy];
        q.pop();
        bool fl=false;
        for(int i=0;i<4;i++)
        {
            int tx=sx+fx[i],ty=sy+fy[i];
            while(valid(tx,ty) && cnt+1<=dis[tx][ty])
            {
                fl=true;
                q.push({tx,ty});
                vis[tx][ty]=1;
                dis[tx][ty]=cnt+1;
                tx+=fx[i],ty+=fy[i];
            }
        }
    }
}

int main()
{
    int x,y,cc,d;
    scanf("%d%d",&row,&col);
    char c;
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            dis[i][j]=INT_MAX;
            while(true)
            {
                scanf("%c",&c);
                if(c=='S' || c=='T' || c=='.' || c=='*')
                    break;
            }
            a[i][j]=c;
            if(c=='S')
                x=i,y=j;
            else if(c=='T')
                cc=i,d=j;
        }
    }
    memset(vis,0,sizeof vis);
    bfs(x,y);
    //printf("%d\n",dis[cc][d]);
    puts(dis[cc][d]<=2 && vis[cc][d]?"YES":"NO");
}
/*
4 4
S**T
..*.
*.*.
....
*/
