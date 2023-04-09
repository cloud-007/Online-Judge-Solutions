/*
Quick_Round_64______________
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int sz=40;
char a[sz][sz];
int vis[sz][sz];
int row,col,cnt=0;
int fx[]= {1,-1,0,0};
int fy[]= {0,0,1,-1};

void dfs(int sx, int sy)
{
    vis[sx][sy]=1;
    for(int i=0;i<4;i++)
    {
        int tx=sx+fx[i];
        int ty=sy+fy[i];
        if(tx>=0 && ty<row && ty>=0 && ty<row && !vis[tx][ty])
        {
            if(a[tx][ty]=='.')
            {
                dfs(tx,ty);
            }
            else
            {
                cnt++;
            }
        }
        else if(tx<0 || ty<0 || tx==row || ty==row)
        {
            cnt++;
        }
    }
}



int main()
{
    scanf("%d",&row);
    col=row;
    char c;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            while(scanf("%c",&c))
            {
                if(c=='.' || c=='#')
                    break;
            }
            a[i][j]=c;
        }
    }
    memset( vis,0,sizeof vis);
    cnt=0;
    dfs(0,0);
    if(!vis[row-1][row-1])
    dfs(row-1,row-1);
    printf("%d\n",(cnt-4)*9);
    return 0;
}
