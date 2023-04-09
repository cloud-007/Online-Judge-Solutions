#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,tot,sum=0,a;
    scanf("%d%d",&n,&tot);
    int ans[n+5];
    memset(ans, 0 , sizeof ans);
    vector < int > v;
    priority_queue < pair < int , int >> pq,p;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        v.push_back(a);
        a/=2;
        if(v[i]%2)a++;
        sum+=a;
        pq.push({a,i});
        p.push({v[i],i});
    }
    if(sum>tot)
    {
        puts("-1");
    }
    else
    {
        sum=tot;
        while(!pq.empty())
        {
            int idx=pq.top().second;
            int val=pq.top().first;
            pq.pop();
            ans[idx]=val;
            sum-=val;
        }
        while(sum && p.size())
        {
            int idx=p.top().second;
            int val=p.top().first;
            int rem=abs(val-ans[idx]);
            p.pop();
            if(rem<=sum)
            {
                ans[idx]=val;
                sum-=rem;
            }
            else
            {
                ans[idx]+=sum;
                sum=0;
            }
            if(sum<=0)
                break;
        }
        for(int i=0;i<n;i++)
            printf("%d ",ans[i]);
    }
}
