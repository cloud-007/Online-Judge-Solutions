#include<bits/stdc++.h>
using namespace std;

struct R{
    int l, r;
    bool operator< (R a)const
    {
        if(a.l==l)
            return r>a.r;
        else if(a.r==r)
            return l>a.l;
        return l>a.l;
    }
};
priority_queue < R > pq;
int main()
{
    int n,l,r;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&l,&r);
        pq.push({l,r});
    }
    int mx=0,last=0;
    while(!pq.empty())
    {
        int l=pq.top().l,r=pq.top().r;
        pq.pop();
        if(r<last)
        {
            mx=max(mx,l);
            last=l;
        }
        else last=r,mx=max(mx,r);
    }
    printf("%d\n",mx);
}
