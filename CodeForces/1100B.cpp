#include<bits/stdc++.h>
using namespace std;

const int sz=1e5+50;
deque < int > x[sz];
int ans[sz];

int main()
{
    memset(ans,0,sizeof ans);
    int n,m,a;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++)
    {
        scanf("%d",&a);
        x[a].push_back(i);
    }
    while(true)
    {
        int mx=0,cnt=0;
        for(int i=1; i<=n; i++)
        {
            if(x[i].size())
            {
                cnt++;
                mx=max(mx,x[i].front());
                x[i].pop_front();
            }
            else
            {
                break;
            }
        }
        if(!mx || cnt!=n)
            break;
        ans[mx]=1;
    }
    for(int i=1;i<=m;i++)
        printf("%d",ans[i]);
}
