#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        ll n;
        scanf("%lld",&n);
        char s[n+5];
        getchar();
        for(int i=1; i<=n; i++)
            scanf("%c",&s[i]);
        ll x=0, y= 0,mn = INT_MAX;
        pair < ll, ll > ans;
        bool fl=true;
        map < pair <ll, ll >, ll > mp;
        mp[ {x,y}]=1;
        for(ll i=1; i<=n; i++)
        {
            if(s[i]=='R')
                x++;
            else if(s[i]=='L')
                x--;
            else if(s[i]=='D')
                y--;
            else if(s[i]=='U')
                y++;
            if(mp[ {x,y}])
            {
                if(abs(i-mp[ {x,y}])<mn)
                {
                    fl=false;
                    mn=abs(i-mp[ {x,y}]);
                    ans= {mp[{x,y}],i};
                }
            }
            mp[ {x,y}]=i+1;
        }
        if(fl)
            puts("-1");
        else
            printf("%lld %lld\n",ans.first,ans.second);
    }
}
