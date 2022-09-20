#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,sum=0,a;
    scanf("%d",&n);
    priority_queue < pair < int , int >> pq;
    vector < int > ans;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        pq.push({a,i});
    }
    if(n==1)
    {
        puts("-1");
        return 0;
    }
    while(pq.size()>1)
    {
        sum+=pq.top().first;
        ans.push_back(pq.top().second);
        pq.pop();
    }
    if(pq.top().first==sum)
        puts("-1");
    else
    {
        printf("%d\n",n-1);
        for(auto i : ans)printf("%d ",i);
        printf("\n");
    }
}
