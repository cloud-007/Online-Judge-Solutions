/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, dis[N];
vector < pair < int, int >> x[N];
bool vis[N];

void dfs(int u) {
    vis[u] = true;
    for(auto [i, cost] : x[u]) {
        if(!vis[i]) {
            dis[i] = dis[u] + cost;
            dfs(i);
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
        cin >> n;
        for(int i = 1; i < n; i++) {
            int u, v, c; cin >> u >> v >> c ;
            ++u, ++v;
            x[u].push_back({v, c});
            x[v].push_back({u, c});
        }
        memset(vis, false, sizeof vis);
        dis[1] = 0;
        dfs(1);
        int mx = 0, st = -1;
        memset(vis, false, sizeof vis);

        for(int i = 1; i <= n; i++) {
            if(dis[i] > mx) {
                mx = dis[i]; st = i;
            }
        }
        dis[st] = 0;
        dfs(st);
        for(int i = 1; i <= n; i++) {
            if(dis[i] > mx) {
                mx = dis[i]; st = i;
            }
        }
        cout << "Case " << casee++ << ": " << mx << endl;

        for(int i = 1; i <= n; i++) {
            x[i].clear();
        }

    }


    return 0;
}
