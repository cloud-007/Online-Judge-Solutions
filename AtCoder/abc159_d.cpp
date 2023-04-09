#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    scanf("%d",&n);
    ll a[n+5];
    map < ll , ll > mp,fin;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        mp[a[i]]++;
    }
    long long tot=0;
    for(auto i : mp)
    {
        if(i.second>=2)
            tot+=(i.second*(i.second-1))/2;
    }
    for(int i=1;i<=n;i++)
    {
        long long x=mp[a[i]];
        long long temp=tot;
        temp-=(x*(x-1))/2;
        x--;
        temp+=(x*(x-1))/2;
        printf("%lld\n",temp);
    }
}
