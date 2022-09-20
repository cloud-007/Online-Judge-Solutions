#include<bits/stdc++.h>
using namespace std;

struct R{
    int id,l,r;
    bool operator<(R a)const{
        return id<a.id;
    }
};

int main()
{
    int n,f;
    scanf("%d%d",&n,&f);
    long long sum=0;
    priority_queue < R > pq;
    while(n--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        if(l>=r)
        {
            sum+=r;
        }
        else
        {
            int x=l*2;
            int y=min(l,r);
            int z=min(r,x);
            pq.push({abs(y-z),l,r});
        }
    }
    while(pq.size())
    {
        //printf("%d %d\n",pq.top().l,pq.top().r);
        if(f>0)
        {
            sum+=pq.top().l+pq.top().id;
        }
        else
            sum+=pq.top().l;
        f--;
        pq.pop();
    }
    printf("%lld\n",sum);
}
