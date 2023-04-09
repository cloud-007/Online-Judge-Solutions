#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll sum=0,req=0;
const int sz=1e6+50;
struct R{
    int l,r;
    bool operator<(R a)const
    {
        if(a.r==r)
        {
            return l>a.l;
        }
        return r>a.r;
    }
};

priority_queue < R > pq;

int main()
{
    int n,r,avg,a,b;
    scanf("%d%d%d",&n,&r,&avg);
    req=(ll)n*(ll)avg;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        sum+=a;
        pq.push({a,b});
    }
    if(sum>=req)
    {
        puts("0");
        return 0;
    }
    req=abs(sum-req);
    sum=0;
    while(!pq.empty())
    {
        if(req<=0)
            break;
        int l=pq.top().l,rr=pq.top().r;
        pq.pop();
        int can=abs(r-l);
        if(req<can)
        {
            can=req;
        }
        sum+=((ll)can*(ll)rr);
        req-=can;
    }
    printf("%lld\n",sum);
}
