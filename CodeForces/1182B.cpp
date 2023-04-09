#include<bits/stdc++.h>
using namespace std;
int main()
{
    int row,col;
    scanf("%d%d",&row,&col);
    int cnt=0;
    char a[row+5][col+5],c;
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            while(true)
            {
                scanf("%c",&c);
                if(c=='.' || c=='*')
                    break;
            }
            a[i][j]=c;
            if(c=='*')cnt++;
        }
    }
    for(int i=2;i<row;i++)
    {
        for(int j=2;j<col;j++)
        {
            if(a[i][j]=='*' && a[i+1][j]=='*' && a[i-1][j]=='*' && a[i][j+1]=='*' && a[i][j-1]=='*')
            {
                cnt--;
                int k=i-1;
                while(k>=1 && a[k][j]=='*')cnt--,k--;
                k=i+1;
                while(k<=row && a[k][j]=='*')cnt--,k++;
                k=j+1;
                while(k<=col && a[i][k]=='*')cnt--,k++;
                k=j-1;
                while(k>=1 && a[i][k]=='*')cnt--,k--;
                puts(cnt>0?"NO":"YES");
                return 0;
            }
        }
    }
    puts("NO");
}
