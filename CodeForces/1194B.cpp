#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int row,col,id;
        scanf("%d%d",&row,&col);
        int rcnt[col+5],ccnt[row+5],mxr=0,mxc=0;
        memset(rcnt,0,sizeof rcnt);
        memset(ccnt,0,sizeof ccnt);
        char c,a[row+5][col+5];
        for(int i=1; i<=row; i++)
        {
            for(int j=1; j<=col; j++)
            {
                while(true)
                {
                    scanf("%c",&c);
                    if(c=='*' || c=='.')
                        break;
                }
                a[i][j]=c;
                if(c=='*')
                {
                    rcnt[j]++,ccnt[i]++;
                    mxr=max(mxr,rcnt[j]);
                    mxc=max(mxc,ccnt[i]);
                }
            }
        }
        if(mxr==row && mxc==col)
        {
            puts("0");
            continue;
        }
        bool fl=true;
        for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=col;j++)
            {
                if(ccnt[i]==mxc && rcnt[j]==mxr && a[i][j]=='.')
                {
                    printf("%d\n",(row+col-1)-(mxr+mxc));
                    fl=false;
                    break;
                }
            }
            if(!fl)break;
        }
        if(fl)
            printf("%d\n",(row+col)-(mxr+mxc));
    }
}
