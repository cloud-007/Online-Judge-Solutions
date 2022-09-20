#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long

const int sz = 1005;
int tc, casee = 1, n, m, dp[sz][2], u, v;
vector < int > x[sz];
bool vis[sz];

void clr()
{
    for(int i = 0; i < sz; i++)x[i].clear();
    memset(dp, -1, sizeof dp);
    memset(vis, false, sizeof vis);
}

int rec(int id, int istaken, int par)
{
    vis[id] = true;
    int &ret = dp[id][istaken];
    if(~ret)return ret;
    ret = istaken;
    for(auto i : x[id])
    {
        if(i != par)
        {
            if(istaken)
                ret += rec(i, 0, id);
            else
            {
                ret += max(rec(i, 0, id), rec(i, 1, id));
            }
        }
    }
    return ret;
}

int main()
{
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--)
    {
        clr();
        cin >> n >> m;
        while(m--)
        {
            cin >> u >> v;
            x[u].push_back(v);
            x[v].push_back(u);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(!vis[i])
                ans += max(rec(i, 0, -1), rec(i, 1, -1));
        }
        cout << "Case " << casee++ << ": " << ans << endl;
    }
}
