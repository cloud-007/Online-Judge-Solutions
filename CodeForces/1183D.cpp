#include<bits/stdc++.h>
using namespace std;
#define l first
#define r second

int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        map < int  , int > mp;
        int n,a;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a);
            mp[a]++;
        }
        priority_queue < pair < int , int >> pq;
        for(auto i : mp)
        pq.push({i.r,i.l});
        int last=INT_MAX,tot=0;
        while(!pq.empty())
        {
            int add=min(last-1,pq.top().l);
            pq.pop();
            if(add<=0)add=0;
            tot+=add;
            last=add;
        }
        printf("%d\n",tot);
    }
}
