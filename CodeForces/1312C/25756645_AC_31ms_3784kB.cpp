#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,k;
        ll a,mx=0;
        scanf("%d%d",&n,&k);
        map < ll ,int > mp;
        priority_queue < ll > pq;
        set < ll > st;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a);
            mx=max(mx,a);
            pq.push(a);
        }
        for(int i=0;;i++)
        {
            ll temp=pow(k,i);
            if(temp>mx)break;
            st.insert(-temp);
        }
        bool fl=true;
        while(!pq.empty())
        {
            ll now=pq.top();
            pq.pop();
            vector < ll > v;
            for(auto i : st)
            {
                if(-i<=now)
                {
                    now-=(-i);
                    v.push_back(-i);
                }
                if(now==0)
                    break;
            }
            if(now)
            {
                fl=false;
                break;
            }
            for(auto i : v)st.erase(-i);
        }
        puts(fl?"YES":"NO");
    }
}
