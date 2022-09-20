#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define endl "\n"

const int sz = 3005;
vector < int > x[sz];
int vis[sz], dis[sz], par[sz], u, v, n, ok = 0;
set < int > subway;

void work(int now, int des)
{
    while(now != des)
    {
        subway.insert(now);
        now = par[now];
    }
    subway.insert(now);
}

void find_circle(int u)
{
    if(ok)return;
    vis[u] = 1;
    for(auto i : x[u])
    {
        if(!ok && vis[i] && par[u] != i)
        {
            ok = 1;
            work(u,i);
            return;
        }
        else if(!vis[i])
        {
            par[i] = u;
            find_circle(i);
        }
    }
}

void dfs(int u)
{
    vis[u] = 1;
    for(auto i : x[u])
    {
        if(!vis[i])
        {
            if(subway.count(i))dis[i] = 0;
            else dis[i] = dis[u] + 1;
            dfs(i);
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
        x[v].push_back(u);
    }
    memset(vis, 0, sizeof vis);
    par[1]=1;
    find_circle(1);
    memset(vis, 0, sizeof vis);
    memset(dis, 0, sizeof dis);
    for(auto i : subway)
    {
        dfs(i);
        break;
    }
    for(int i = 1; i <= n; i++)cout << dis[i] << " ";
}
