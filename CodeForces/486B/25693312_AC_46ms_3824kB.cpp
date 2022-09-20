#include<bits/stdc++.h>
using namespace std;
int main()
{
    int row,col;
    scanf("%d%d",&row,&col);
    int a[row+5][col+5];
    bool fl=true;
    for(int i=1; i<=row; i++)
        for(int j=1; j<=col; j++)
            scanf("%d",&a[i][j]);
    map < int , int > r,c,br,bc;
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            if(a[i][j]==0)
            {
                r[i]=1;
                c[j]=1;
            }
        }
    }
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            if(!r[i] && !c[j])
            {
                br[i]++;
                bc[j]++;
            }
        }
    }
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            if(a[i][j]==1)
            {
                if(bc[j] || br[i])
                    int x;
                else
                {
                    puts("NO");
                    return 0;
                }
            }
        }
    }
    puts("YES");
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            if(!r[i] && !c[j])
                printf("1 ");
            else
                printf("0 ");
        }
        printf("\n");
    }
}
