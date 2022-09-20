/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 100 + 5;
int tc, n, casee = 1, dis[N][2];
bool vis[N][2];
vector < int > x[N];

void bfs(int u, int type) {
    queue < int > q;
    dis[u][type] = 0;
    vis[u][type] = true;
    q.push(u);
    while(!q.empty()) {
        u = q.front(); q.pop();
        for(auto i : x[u]) {
            if(vis[i][type])continue;
            vis[i][type] = true;
            dis[i][type] = dis[u][type] + 1;
            q.push(i);
        }
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {
        int r; cin >> n >> r;
        while(r--) {
            int u, v; cin >> u >> v;
            x[u].push_back(v);
            x[v].push_back(u);
        }

        int s, d; cin >> s >> d;

        for(int i = 0; i <= n; i++)dis[i][0] = dis[i][1] = INT_MAX;
        memset(vis, false, sizeof vis);

        bfs(s, 0);
        bfs(d, 1);

        int Ans = dis[s][1];

        for(int i = 0; i < n; i++) {
            if(i == s || i == d)continue;
            Ans = max(Ans, dis[i][0] + dis[i][1]);
        }

        cout << "Case " << casee++ << ": " << Ans << endl;

        for(int i = 0; i <= n; i++)x[i].clear();

    }


    return 0;
}
