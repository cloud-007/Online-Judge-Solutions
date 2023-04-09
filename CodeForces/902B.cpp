#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define endl "\n"

const int sz = 1e4 + 5;
vector < int > x[sz];
int vis[sz], clr[sz], n, a, ans = 1;

void dfs(int u, int color)
{
    vis[u] = 1;
    for(auto i : x[u])
    {
        if(!vis[i])
        {
            if(clr[i] != color)
            {
                ans++;
                dfs(i, clr[i]);
            }
            else dfs(i, color);
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
    for(int i = 2; i <= n; i++)
    {
        cin >> a;
        x[a].push_back(i);
        x[i].push_back(a);
    }
    for(int i = 1; i <= n; i++)cin >> clr[i];
    dfs(1, clr[1]);
    cout << ans << endl;
}
