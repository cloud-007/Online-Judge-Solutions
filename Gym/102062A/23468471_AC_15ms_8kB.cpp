#include<bits/stdc++.h>
using namespace std;
typedef pair < int, int > pi;
typedef long long ll;
typedef pair< ll,ll > pll;
#define fst ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pb push_back
#define bug() puts("Debug here")
#define f(n) for(int i=0;i<n;i++)
#define tc() int t;cin>>t;while(t--)
int main()
{
    fst;
    tc()
    {
        int n,a,b,c,d,sum=0;
        cin>>n>>a>>b>>c>>d;
        sum+=a,sum+=b,sum+=c,sum+=d;
        n++;
        if(n%2)
        {
            n/=2;
            n++;
        }
        else
            n/=2;
        puts(sum>=n?"Yes":"No");
    }

    return 0;
}
