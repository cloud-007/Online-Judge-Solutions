#include<bits/stdc++.h>
using namespace std;

const int sz=1e5+50;
int a[sz],b[sz],n;
long long dp[sz],dP[sz],ans=0;

void solve(int i)
{
    if(i>n)
        return;
    dp[i]=dP[i-1]+a[i];
    dP[i]=dp[i-1]+b[i];
    dp[i]=max(dp[i],dp[i-1]);
    dP[i]=max(dP[i-1],dP[i]);
    long long x=max(dp[i],dP[i]);
    ans=max(ans,x);
    solve(++i);
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(int i=1; i<=n; i++)
        scanf("%d",&b[i]);
    solve(1);
    printf("%lld\n",ans);
}
