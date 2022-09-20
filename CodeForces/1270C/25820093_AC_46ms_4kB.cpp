#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        ll  n,sum=0,x=0,a;
        scanf("%lld",&n);
        while(n--)
        {
            scanf("%lld",&a);
            sum+=a;
            x=(x^a);
        }
        puts("2");
        printf("%lld %lld\n",x,x+sum);
    }
}
