#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[3050],ans[3050];
bool done[3050];
const int sz=1e18;
int main()
{
    int n;
    scanf("%d",&n);
    int a[n+5],c[n+5];
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]),dp[i]=sz;
    for(int i=1; i<=n; i++)
        scanf("%d",&c[i]);
    memset(done, false, sizeof done);
    for(int i=1; i<n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(a[j]>a[i])
            {
                dp[j]=min(dp[j],(ll)c[i]+(ll)c[j]);
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        if(dp[i]!=sz)
        {
            //printf("%d %lld\n",i,dp[i]);
            for(int j=i+1;j<=n;j++)
            {
                if(a[i]<a[j])
                {
                    if(done[j])
                    {
                        ans[j]=min(ans[j],dp[i]+c[j]);
                    }
                    else
                    {
                        done[j]=1;
                        ans[j]=dp[i]+c[j];
                    }
                }
            }
        }
    }
    ll mn=sz;
    for(int i=1;i<=n;i++)
    {
        if(done[i])
        {
            mn=min(mn,ans[i]);
        }
    }
    if(mn==sz)mn=-1;
    printf("%lld\n",mn);
}
