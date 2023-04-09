#include<bits/stdc++.h>
using namespace std;

const int sz=2*1e5+50;
vector < int > x[sz];
int vis[sz],ans[sz],cnt=0;

void dfs(int u)
{
    vis[u]=1;
    cnt++;
    for(auto i : x[u])
    {
        if(!vis[i])
            dfs(i);
    }
    ans[u]=cnt;
}

int main()
{
    cin.tie(0),cout.tie(0);
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=1;i<=n;i++)x[i].clear();
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            x[a[i]].push_back(i);
            x[i].push_back(a[i]);
        }
        memset(vis, 0 , sizeof vis);
        memset(ans, 0 , sizeof ans);
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                cnt=0;
                dfs(i);
            }
        }
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
}
