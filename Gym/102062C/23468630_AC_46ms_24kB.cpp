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
#define pi acos(-1.0)
int main()
{
    fst;
    int casee=1;
    tc()
    {
        float r;
        cin>>r;
        float square=r*r;
        float temp=r/2;
        float e=sqrt((r*r)+(r*r));
        e/=2;
        float circle=pi*e*e;
        float rem=abs(circle-square);
        rem/=4;
        float snd=pi*temp*temp;
        snd/=2;
        printf("Case %d: %.4f\n",casee++,abs(snd-rem));

    }

    return 0;
}

