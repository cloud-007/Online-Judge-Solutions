#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue < pair < int , int >> pq;
    int n;
    scanf("%d",&n);
    int a;
    priority_queue < int > p;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        pq.push({-a,i});
        p.push(-a);
    }
    int cnt=0;
    while(p.size())
    {
        int now=-p.top();
        p.pop();
        while(pq.size() && -pq.top().first<=now)
            pq.pop();
        if(pq.size())
        {
            cnt++;
            pq.pop();
        }
        else
            break;
    }
    printf("%d\n",cnt);
}
