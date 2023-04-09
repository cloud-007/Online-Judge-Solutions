#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long

const int sz = 1005;
vector < int> x[sz], y[sz];
int n, u, v, ans = -1;
vector < pair < int, int >> vp;
map < pair < int, int >, bool > vis;

void dfs(int sx, int sy)
{
    vis[ {sx, sy}] = true;
    for(auto i : x[sx])
    {
        if(!vis[ {sx, i}])
            dfs(sx, i);
    }
    for(auto i : y[sy])
    {
        if(!vis[ {i, sy}])
        {
            dfs(i, sy);
        }
    }
}

int main()
{
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> u >> v;
        x[u].push_back(v);
        y[v].push_back(u);
        vp.push_back({u, v});
    }
    for(auto i : vp)
    {
        if(!vis[ {i.first, i.second}])
        {
            ans ++;
            dfs(i.first,i.second);
        }
    }
    cout<<ans<<endl;
}
