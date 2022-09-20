#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        long long n,g,b,req,ans,c;
        scanf("%lld%lld%lld",&n,&g,&b);
        req=n/2;
        req+=n%2==1;
        if(req<=g)
        {
            printf("%lld\n",n);
            continue;
        }
        c=req/g;
        ans=(c*g);
        ans+=(req%g);
        c+=req%g!=0;
        ans+=b*(c-1);
        printf("%lld\n",max(ans,n));
    }
}
