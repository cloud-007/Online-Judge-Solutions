/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 1e5 + 5;
int u, v, cost, n, ok = 0, p, mn, ok1 = 0;
vector < pair < int, int >> x[sz];
ll ans = 0, temp, del;

void dfs(int u, int par)
{
    if(x[u].size() > 1 && ok == 0)ok = u, p = par;
    for(auto i : x[u])
    {
        if(i.F != par)
        {
            ans += i.S;
            if(ok)ans += i.S;
            dfs(i.F, u);
        }
    }
}

void dfs1(int u, int par)
{
    if(x[u].size() == 1)
    {
        del = max(del, temp);
        return;
    }
    for(auto i : x[u])
    {
        if(i.F != par)
        {
            temp += i.S;
            dfs1(i.F, u);
            temp -= i.S;
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
    dfs(1, 1);
    if(ok == 0)
        cout << ans << endl;
    else
    {
        ll fin = ans;
        dfs1(ok, p);
        cout << fin - del << endl;
    }
    return 0;
}
