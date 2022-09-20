#include<bits/stdc++.h>
using namespace std;
#define ll long long

map < int , deque < int >> x;
deque < int > v;

int main()
{
    int n;
    scanf("%d",&n);
    int a;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        x[a].push_back(i);
        v.push_back(a);
        sum+=a;
    }
    if(n==2)
    {
        puts("0");
        return 0;
    }
    sort(v.begin(),v.end());
    vector < int > ans;
    for(int i=0;i<n;i++)
    {
        int y=v[i];
        ll rem=sum-y;
        if(i==n-1)
        {
            rem-=v[n-2];
            if(rem==v[n-2])
            {
                ans.push_back(x[v[i]].front());
                x[v[i]].pop_front();
            }
        }
        else
        {
            rem-=v[n-1];
            if(rem==v[n-1])
            {
                ans.push_back(x[v[i]].front());
                x[v[i]].pop_front();
            }
        }
    }
    printf("%d\n",ans.size());
    for(auto i : ans)printf("%d ",i+1);
    printf("\n");
}
