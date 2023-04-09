/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 1e4 + 5;
int n, m, r, me, hos, cost[sz][sz], u, v, coss;
vector < int > x[sz];
ll dis[sz];

void bfs(int b) {
    priority_queue < pair < int, int > >q;
    q.push({0, b});
    dis[b] = 0;
    while(!q.empty()) {
        pair < int, int > y = q.top();
        int u = y.second;
        for(auto i : x[u]) {
            int a = i;
            if(dis[u] + cost[u][a] < dis[a]) {
                dis[a] = dis[u] + cost[u][a];
                q.push({-dis[a], a});
            }
        }
        q.pop();
    }
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> m >> r >> me >> hos;
    while(r--) {
        cin >> u >> v >> coss;
        x[u].push_back(v);
        x[v].push_back(u);
        cost[u][v] = cost[v][u] = coss;
    }

    for(int i = 1; i <= n; i++)dis[i] = 1e18;

    bfs(me);

    if(dis[hos] <= m) {
        cout << "alive " << dis[hos] << endl;
    } else cout << "died" << endl;

    return 0;
}
