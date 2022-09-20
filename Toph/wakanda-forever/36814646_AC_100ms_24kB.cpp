/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N], par[N];
vector < pair < int, int >> x[N];
vector < int > v;
bool vis[N];

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

vector < Edge > edges;

int find_set(int v) {
    if(v == par[v])return v;
    return par[v] = find_set(par[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(a != b) {
        par[b] = a;
    }
}


void dfs(int u) {
    vis[u] = true;
    v.push_back(u);
    for(auto i : x[u]) {
        if(vis[i.F])continue;
        dfs(i.F);
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    int m, d; cin >> n >> m >> d;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        par[i] = i;
    }
    while(m--) {
        int u, v, c; cin >> u >> v >> c;
        if(!a[u] || !a[v])continue;
        x[u].push_back({v, c});
        x[v].push_back({u, c});
    }

    int cnt = -1;
    ll Ans = 0;
    for(int i = 1; i <= n; i++) {
        if(vis[i] || a[i] == 0)continue;
        dfs(i); ++cnt;

        for(auto j: v){
            for(auto k: x[j]){
                edges.push_back({j, k.F, k.S});
            }
        }

        sort(edges.begin(), edges.end());

        for(Edge e : edges) {
            if(find_set(e.u) != find_set(e.v)) {
                Ans += e.weight;
                union_sets(e.u, e.v);
            }
        }

        edges.clear(); v.clear();
    }

    if(~cnt)Ans += cnt * d;
    cout << Ans << endl;

    return 0;
}
