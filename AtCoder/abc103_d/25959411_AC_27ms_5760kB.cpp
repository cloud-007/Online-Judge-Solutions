#include<bits/stdc++.h>
using namespace std;

const int sz=1e5+50;
vector < int > x[sz];

int main()
{
    int n,m,u,v;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        scanf("%d%d",&u,&v);
        x[u].push_back(v);
    }
    int mn=INT_MAX,ans=0;
    for(int i=1; i<=n; i++)
    {
        if(i==mn)
        {
            ans++;
            mn=INT_MAX;
        }
        if(x[i].size())
        {
            for(auto j : x[i])
            {
                mn=min(mn,j);
            }
        }
    }
    printf("%d\n",ans);
}
