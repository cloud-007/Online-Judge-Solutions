/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e3 + 5;
int tc, n, k, m, casee = 1, a[N], dis[N];
bool vis[N];
vector < int > x[N];

void dfs(int u) {
    vis[u] = true; dis[u]++;
    for(auto i : x[u]) {
        if(vis[i])continue;
        dfs(i);
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {
        cin >> k >> n >> m;
        for(int i = 1; i <= k; i++)cin >> a[i];
        while(m--) {
            int u, v; cin >> u >> v;
            x[u].push_back(v);
        }

        for(int i = 1; i <= k; i++) {
            memset(vis, false, sizeof vis);
            dfs(a[i]);
        }

        int Ans = 0;

        for(int i = 1; i <= n; i++) {
            Ans += dis[i] == k;
        }

        cout << "Case " << casee++ << ": " << Ans << endl;


        memset(vis, false, sizeof vis);
        memset(dis, 0, sizeof dis);
        for(int i = 1; i <= n; i++)x[i].clear();
    }


    return 0;
}
