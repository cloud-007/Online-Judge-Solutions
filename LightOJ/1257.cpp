/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 3e4 + 5;
int tc, n, casee = 1, dis[N], disP[N], disQ[N];
bool vis[N];
int mx, mxNode;
vector < pair < int, int >> x[N];

void dfs(int s, int d) {
    vis[s] = true;
    dis[s] = max(d, dis[s]);
    if(d > mx) {
        mx = d; mxNode = s;
    }
    for(auto i : x[s]) {
        if(vis[i.F])continue;
        dfs(i.F, d + i.S);
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {

        cin >> n;

        for(int i = 1; i < n; i++) {
            int u, v, c; cin >> u >> v >> c;
            x[u].push_back({v, c});
            x[v].push_back({u, c});
        }

        int p, q; mx = 0;

        dfs(0, 0);
        p = mxNode; mx = 0;
        memset(vis, false, sizeof vis);
        memset(dis, false, sizeof dis);

        dfs(p, 0);

        q = mxNode; mx = 0;
        for(int i = 0; i < n; i++)disP[i] = dis[i];

        memset(vis, false, sizeof vis);
        memset(dis, false, sizeof dis);

        dfs(q, 0);

        for(int i = 0; i < n; i++)disQ[i] = dis[i];

        cout << "Case " << casee++ << ":" << endl;
        for(int i = 0; i < n; i++) {
            cout << max(disP[i], disQ[i]) << endl;
        }

        for(int i = 0; i <= n; i++) {
            x[i].clear();
            vis[i] = disP[i] = disQ[i] = dis[i] = 0;
        }
    }


    return 0;
}
