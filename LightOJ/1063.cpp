/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 10000 + 5;
int casee = 1, n, currentNode = 0, tin[N], low[N];
int timer = 0;
vector < int > x[N];
bool vis[N];
set < int > articulationPoint;

void dfs(int v, int p = -1) {
    vis[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;
    for(int to : x[v]) {
        if(to == p) continue;
        if(vis[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(low[to] >= tin[v] && p != -1)articulationPoint.insert(v);
            ++children;
        }
    }
    if(p == -1 && children > 1)articulationPoint.insert(v);
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int m; cin >> n >> m;
        while(m--) {
            int u, v; cin >> u >> v;
            x[u].push_back(v);
            x[v].push_back(u);
        }
        timer = 0;
        memset(vis, false, sizeof vis);
        memset(tin, -1, sizeof tin);
        memset(low, -1, sizeof low);

        for(int i = 1; i <= n; i++) {
            if(vis[i])continue;
            dfs(i);
        }

        cout << "Case " << casee++ << ": " << articulationPoint.size() << endl;

        for(int i = 1; i <= n; i++)x[i].clear();
        articulationPoint.clear();

    }


    return 0;
}
