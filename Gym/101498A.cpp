#include<bits/stdc++.h>
using namespace std;
typedef pair < int, int > pi;
typedef long long ll;
typedef pair< ll,ll > pll;
#define start() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sf(a) scanf("%d",&a)
#define sf2(x,y) scanf("%d%d",&x,&y)
#define sfl(b) scanf("%I64d",&b)
#define sfl2(g,h) scanf("%I64d%I64d",&g,&h)
#define pf(c) printf("%d ",c)
#define pfn(m) printf("%d\n",m)
#define pfl(d) printf("%I64d ",d)
#define pfln(o) printf("%I64d\n",o)
#define pb push_back
#define bug() puts("Debug here")
#define f(n) for(int i=0;i<n;i++)
#define tc() int t;sf(t);while(t--)
int main()
{
    tc()
    {
        map < int , int > mp;
        tc()
        {
           // mp.clear();
            string s;
            int a;
            cin>>s;sf(a);
            mp[a]++;
        }
        int mx=0;
        int ans;
        for(auto i : mp)
        {
            //cout<<i.first<<' '<<i.second<<endl;
            if(i.second>mx)
            {
                mx=i.second;
                ans=i.first;
            }
        }
        mp.clear();
        pfn(ans);
    }

    return 0;
}

