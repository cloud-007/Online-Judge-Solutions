/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, tin[N], vis[N], par[N];
int timer, low[N], dis[N], cnt;
vector < int > x[N];
set < int > g[N];

void ap(int u, int p = -1) {
    vis[u] = true;
    tin[u] = low[u] = timer++;
    for(int i : x[u]) {
        if(i == p) continue;
        if(vis[i]) {
            low[u] = min(low[u], tin[i]);
        } else {
            ap(i, u);
            low[u] = min(low[u], low[i]);
            if(low[i] > tin[u]) {
                g[i].erase(u);
                g[u].erase(i);
            }
        }
    }
}

bool cycleFound;

void dfs(int u, int dep) {
    vis[u] = true; dis[u] = dep;
    ++cnt;
    for(auto i : g[u]) {
        if(!vis[i]) {
            par[i] = u;
            dfs(i, dep + 1);
        } else if((dis[u] - dis[i]) % 2 == 0) {
            cycleFound = true;
        }
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        int m; cin >> n >> m;
        while(m--) {
            int u, v; cin >>  u >> v;
            ++u; ++v;
            x[u].push_back(v);
            x[v].push_back(u);
            g[u].insert(v);
            g[v].insert(u);
        }

        timer = 0;
        memset(vis, false, sizeof vis);
        memset(tin, false, sizeof tin);
        memset(low, false, sizeof low);
        memset(dis, false, sizeof dis);
        memset(par, -1, sizeof par);

        for(int i = 1; i <= n; i++)if(!vis[i])ap(i);

        memset(vis, false, sizeof vis);

        int Ans = 0;

        for(int i = 1; i <= n; i++) {
            if(vis[i])continue;
            cnt = cycleFound = 0;
            dfs(i, 0);
            if(cycleFound)Ans += cnt;
        }

        cout << "Case " << casee++ << ": " << Ans << endl;
        for(int i = 1; i <= n; i++) {
            x[i].clear(); g[i].clear();
        }
    }


    return 0;
}
