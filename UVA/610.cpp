/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1e3 + 5;
int tc, n, m, casee = 1, tin[N], low[N], timer;
int totalBridge = 0;
vector < int > x[N], vec;
int vis[N];
vector < pair < int, int >> edges;

void dfs(int u, int p = -1) {
    vis[u] = true;
    tin[u] = low[u] = timer++;
    for(auto i : x[u]) {
        if(i == p)continue;
        if(vis[i]) {
            low[u] = min(low[u], tin[i]);
            if(tin[i] < tin[u])edges.push_back({u, i});
        } else {
            dfs(i, u);
            low[u] = min(low[u], low[i]);
            if(low[i] > tin[u]) {
                edges.push_back({u, i});
                edges.push_back({i, u});
            } else edges.push_back({u, i});
        }
    }
}

//void dfs1(int u, int p = -1) {
//    vis[u] = 1;
//    for(auto i : x[u]) {
//        if(i == p)continue;
//        if(vis[i] == 0) {
//            cout << u << " " << i << endl;
//            dfs1(i, u);
//        } else if(!edge[ {i, u}] && !edge[ {u, i}]) {
//            cout << u << " " << i << endl;
//            edge[ {i, u}] = edge[ {u, i}] = true;
//        }
//    }
//}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    while(cin >> n >> m && n && m) {
        while(m--) {
            int u, v; cin >> u >> v;
            x[u].push_back(v);
            x[v].push_back(u);
        }

        timer = 0;
        memset(vis, false, sizeof vis);
        cout << casee++ << endl;
        cout << endl;

        for(int i = 1; i <= n; i++)if(!vis[i])dfs(i);

        for(auto i : edges) {
            cout << i.F << " " << i.S << endl;
        }

        cout << "#" << Endl;

        for(int i = 1; i <= n; i++)x[i].clear();
        edges.clear();
    }




    return 0;
}
