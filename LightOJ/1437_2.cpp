/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 500 + 5;
int tc, n, casee = 1, dis[N];
bool vis[N];
vector < int > x[N];

int bfs(int u) {
    queue < pair<int, int>> q;
    q.push({u, u});
    dis[u] = 0; vis[u] = true;
    int cur = 505;
    while(!q.empty()) {
        u = q.front().F;
        int par = q.front().S; q.pop();
        for(auto i : x[u]) {
            if(vis[i] && i != par) {
                cur = min(cur, dis[u] + dis[i] + 1);
                continue;
            } else if(vis[i])continue;
            vis[i] = true;
            dis[i] = dis[u] + 1;
            q.push({i, u});
        }
    }
    return cur;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        int m; cin >>  n >> m;
        while(m--) {
            int u, v; cin >> u >> v;
            ++u; ++v;
            x[u].push_back(v);
            x[v].push_back(u);
        }

        int Ans = 505;

        for(int i = 1; i <= n; i++) {
            memset(vis, false, sizeof vis);
            memset(dis, false, sizeof dis);
            Ans = min(Ans, bfs(i));
        }

        cout << "Case " << casee++ << ": " << (Ans == 505 ? "impossible" : to_string(Ans)) << endl;


        for(int i = 1; i <= n; i++)x[i].clear();
    }

    return 0;
}
