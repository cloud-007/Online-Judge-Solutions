#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int sz=2e5+50;
int a[sz],n,last;
ll dp[sz],ans=0;

void solve()
{
    map < ll, ll > mp;
    for(int i=1;i<=n;i++)
    {
        ll val=a[i];
        ll upd=mp[i-val]+val;
        ans=max(ans,upd);
        mp[i-val]=upd;
    }
}

int main()
{
    memset(dp, 0, sizeof dp);
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    solve();
    printf("%lld\n",ans);
}
