/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 300005;
int tc, n, m, s, t;
ll INF = 1000000000000000000LL, l;

vector < pair < int, int >> vp;
vector < pair < pair < int, int >, ll >> edge, ans;
vector < int > x[sz];
vector < ll > e[sz];

ll djk(int m) {

    for(int i = 1; i <= n; i++)x[i].clear(), e[i].clear();

    for(auto i : edge) {
        int u = i.F.F, v = i.F.S;
        ll w = i.S;
        x[u].push_back(v); e[u].push_back(w);
        x[v].push_back(u); e[v].push_back(w);
    }

    for(int i = 0; i < m; i++) {
        int u = vp[i].F, v = vp[i].S;
        x[u].push_back(v); e[u].push_back(1);
        x[v].push_back(u); e[v].push_back(1);
    }

    ll dis[1005];

    for(int i = 1; i <= n; i++)dis[i] = INF;
    dis[s] = 0;
    priority_queue < pair < ll, int >> pq;
    pq.push({0, s});
    while(!pq.empty()) {
        int u = pq.top().S;
        ll cur = -pq.top().F;
        pq.pop();
        if(cur != dis[u])continue;

        for(int i = 0; i < x[u].size(); i++) {
            int v = x[u][i];
            if(dis[u] + e[u][i] < dis[v]) {
                dis[v] = dis[u] + e[u][i];
                pq.push({-dis[v], v});
            }
        }
    }
    return dis[t];
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> m >> l >>  s >> t;
    ++s, ++t;

    for(int i = 1; i <= m; i++) {
        int u, v;
        ll w; cin >> u >> v >> w;
        ++u, ++v;
        if(w == 0)vp.push_back({u, v});
        else edge.push_back({{u, v}, w});
    }

    m = (int)vp.size();


    if(djk(0) < l || djk(m) > l) {
        cout << "NO" << Endl;
        exit(0);
    }

    int lo = 0, hi = m;

    while(lo < hi) {
        int mid = (lo + hi) >> 1;
        if(djk(mid) <= l)hi = mid;
        else lo = mid + 1;
    }

    ll Ans = djk(lo);

    for(int i = 0; i < vp.size(); i++) {
        if(i < lo - 1)ans.push_back({vp[i], 1});
        else if(i == lo - 1)ans.push_back({vp[i], l - Ans + 1});
        else ans.push_back({vp[i], INF});
    }

    for(auto i : edge)ans.push_back(i);

    cout << "YES" << endl;
    for(auto i : ans)cout << i.F.F - 1 << " " << i.F.S - 1 << " " << i.S << endl;


    return 0;
}
