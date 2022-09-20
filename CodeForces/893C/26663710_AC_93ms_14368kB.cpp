#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long

const int sz = 1e5 + 5;
int n, m, a[sz], vis[sz], mn, u, v;
vector < int > x[sz];

void dfs(int u)
{
    mn = min(mn, a[u]);
    vis[u] = 1;
    for(auto i : x[u])
    {
        if(!vis[i])
            dfs(i);
    }
}

int main()
{
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        x[u].push_back(v);
        x[v].push_back(u);
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            mn = INT_MAX;
            dfs(i);
            ans += mn;
        }
    }
    cout << ans << endl;
}
