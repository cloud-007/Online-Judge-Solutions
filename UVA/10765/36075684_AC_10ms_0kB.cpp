/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, m, casee = 1, tin[N], low[N], ap[N];
bool vis[N]; int timer = 0;
vector < int > x[N];

void dfs(int u, int p = -1) {
    vis[u] = true;
    tin[u] = low[u] = ++timer;
    int children = 0;
    for(auto i : x[u]) {
        if(i == p)continue;
        if(vis[i]) {
            low[u] = min(low[u], tin[i]);
        } else {
            dfs(i, u);
            low[u] = min(low[u], low[i]);
            if(low[i] >= tin[u] && p != -1) {
                ap[u]++;
            }
            ++children;
        }
    }
    if(p == -1 && children > 1)ap[u] = children;
}

bool cmp(pair < int, int > a, pair < int, int > b) {
    if(a.F == b.F)return a.S < b.S;
    return a.F > b.F;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    while(cin >> n >> m && (n || m)) {
        int u, v;
        while(cin >> u >> v && u != -1 && v != -1) {
            ++u, ++v;
            x[u].push_back(v);
            x[v].push_back(u);
        }
        memset(vis, false, sizeof vis);
        memset(tin, false, sizeof tin);
        memset(low, false, sizeof low);

        for(int i = 1; i <= n; i++)if(!vis[i])dfs(i);

        map < int, int > mp;
        vector < pair < int, int >> vp;

        for(int i = 1; i <= n; i++) {
            vp.push_back({ap[i], i});
        }

        sort(vp.begin(), vp.end(), cmp);

        for(int i = 0; i < m; i++)cout << vp[i].S - 1 << " " << vp[i].F + 1 << Endl;

        for(int i = 1; i <= n; i++) {
            x[i].clear();
            ap[i] = 0;
        }
        cout << endl;

    }


    return 0;
}
