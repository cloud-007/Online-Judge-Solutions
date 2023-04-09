#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int n;
        scanf("%d",&n);
        int a[n+5],ans[n+5];
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        int c=1,cnt=0;
        memset(ans,0,sizeof ans);
        for(int i=2;; i++)
        {
            bool fl=true;
            for(int j=1; j<=n; j++)
            {
                if(!ans[j] && a[j]%i==0)
                {
                    cnt++;
                    fl=false;
                    ans[j]=c;
                }
            }
            if(cnt==n)
                break;
            if(fl==false)
                c++;
        }
        printf("%d\n",c);
        for(int i=1; i<=n; i++)
            printf("%d ",ans[i]);
        printf("\n");
    }
}