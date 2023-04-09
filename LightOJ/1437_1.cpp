/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 500 + 5;
int tc, n, casee = 1, a[N], dis[N], par[N];
vector < int > x[N];

int findShortestCycle(int u) {
    int Ans = INT_MAX;
    queue < int > q;
    for(int i = 0; i <= n; i++)dis[i] = INT_MAX;
    memset(par, -1, sizeof par);
    q.push(u); dis[u] = 0;
    while(!q.empty()) {
        u = q.front(); q.pop();
        for(auto i : x[u]) {
            if(dis[i] == INT_MAX) {
                dis[i] = dis[u] + 1;
                par[i] = u;
                q.push(i);
            } else if(par[u] != i && par[i] != u) {
                Ans = min(Ans, dis[u] + dis[i] + 1);
            }
        }
    }
    return Ans;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {
        int m; cin >> n >> m;
        while(m--) {
            int u, v; cin >> u >> v;
            x[u].push_back(v);
            x[v].push_back(u);
        }

        int Ans = INT_MAX;

        for(int i = 0; i <= n; i++) {
            Ans = min(Ans, findShortestCycle(i));
        }

        cout << "Case " << casee++ << ": " << (Ans == INT_MAX ? "impossible" : to_string(Ans)) << endl;

        for(int i = 0; i <= n; i++)x[i].clear();

    }


    return 0;
}
