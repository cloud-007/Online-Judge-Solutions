/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N];
vector < pair < int, int >> x[N];
ll dis[N];

void bfs(int u) {
    priority_queue < pair < ll, int >> pq;
    for(int i = 1; i <= n; i++)dis[i] = 1e18;
    dis[u] = 0;
    pq.push({0, u});
    while(pq.size()) {
        ll cost = -pq.top().F; u = pq.top().S; pq.pop();

        for(auto i : x[u]) {
            ll newCost = cost + i.S;
            if(dis[i.F] > newCost) {
                dis[i.F] = newCost;
                pq.push({-newCost, i.F});
            }
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
        int r, s, d; cin >> n >> r >> s  >> d;
        while(r--) {
            int u, v, c; cin >> u >> v >> c;
            x[u].push_back({v, c + 12});
            x[v].push_back({u, c + 12});
        }
        bfs(s);
        cout << dis[d] << endl;
        for(int i = 1; i <= n; i++)x[i].clear();
    }


    return 0;
}
