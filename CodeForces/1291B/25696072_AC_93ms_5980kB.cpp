#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc,n;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        int a[n+5],dp[n+5];
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        if(n==1)
        {
            puts("YES");
            continue;
        }
        if(n==2)
        {
            if(a[1]==a[2] && a[1]==0)
                puts("NO");
            else
                puts("YES");
            continue;
        }
        int i=1,j=n;
        memset(dp,0,sizeof dp);
        for(i=2;i<=n;i++)
        {
            if(a[i]>dp[i-1])
            {
                dp[i]=min(dp[i-1]+1,a[i]);
            }
            else
            {
                i--;
                break;
            }
        }
        for(j=n-1;j>=i;j--)
        {
            if(a[j]>dp[j+1])
            {
                dp[j]=min(dp[j+1]+1,a[j]);
            }
            else
            {
                j++;
                break;
            }
        }

        puts(j<=i?"YES":"NO");
    }
}
