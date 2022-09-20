#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n;
    scanf("%lld",&n);
    if(n==1)
    {
        puts("1 1");
        return 0;
    }
    set < ll > st;
    for(ll i=1;i*i<=n;i++)
        if(n%i==0)st.insert(i),st.insert(n/i);
    ll l=1e18,r=1e18;
    for(auto i : st)
    {
        ll now=i;
        ll req=n/i;
        if(n%i==0 &&  ((i*req)/__gcd(i,req))==n && st.count(req) && max(now,req)<=r)
        {
            l=i,r=req;
        }
    }
    printf("%lld %lld\n",l,r);
}
