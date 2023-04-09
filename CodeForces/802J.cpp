#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define endl "\n"

const int sz = 1e4 + 50;
int n, u, v, cost;
ll dis[sz], ans;
struct R
{
    int  v, cost;
};
vector < R > x[sz];

void clr()
{
    for(int i = 0; i < sz; i++)x[i].clear();
    memset(dis, 0, sizeof dis);
}

void dfs(int u, int par)
{
    for(auto i : x[u])
    {
        if(i.v != par)
        {
            dis[i.v]=dis[u] + i.cost;
            dfs(i.v, u);
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
    for(int i = 1; i < n; i++)
    {
        cin >> u >> v >> cost;
        x[u].push_back({v, cost});
        x[v].push_back({u, cost});
    }
    ans = 0;
    dfs(0, -1);
    for(int i=0;i<n;i++)
        ans = max(ans, dis[i]);
    cout << ans << endl;
}
