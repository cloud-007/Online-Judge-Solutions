/*
Quick_Round_64______________
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
map < ll, int > mp;
void init()
{
    ll sum=1,i;
    for(i=1;; i++)
    {
        if(sum<INT_MAX)
        {
            mp[sum]=1;
            sum+=i;
        }
        else
            break;
    }
}

int main()
{
    init();
    int n;
    scanf("%d",&n);
    int ans[n+5];
    memset(ans,0,sizeof ans);
    for(int i=0;i<n;i++)
    {
        ll k;
        scanf("%lld",&k);
        ans[i]=mp[k];
    }
    for(int i=0;i<n;i++)
        printf("%d ",ans[i]);
    return 0;
}
