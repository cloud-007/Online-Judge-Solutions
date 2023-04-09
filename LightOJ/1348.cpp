/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5, LG = 18;
int tc, n, casee = 1, cp;
int Level[N], rpos[N], heavy[N], a[N]; // Heavy == Special child, means node of MaxSubTreeSize;
int Parent[N], head[N], pos[N];
vector < pair < int, int >> x[N];
pair < int, int > edges[N];
int par[N][LG + 1], dep[N], sz[N];


struct ST {
    int t[4 * N];
    static const int inf = 1e9;
    ST() {
        memset(t, 0, sizeof t);
    }
    void build(int n, int b, int e) {
        if(b == e) {
            t[n] = a[rpos[b]];
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        t[n] = t[l] + t[r];
    }
    void upd(int n, int b, int e, int i, int x) {
        if(b > i || e < i) return;
        if(b == e && b == i) {
            t[n] = x;
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        upd(l, b, mid, i, x);
        upd(r, mid + 1, e, i, x);
        t[n] = t[l] + t[r];
    }
    int query(int n, int b, int e, int i, int j) {
        if(b > j || e < i) return 0;
        if(b >= i && e <= j) return t[n];
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        int L = query(l, b, mid, i, j);
        int R = query(r, mid + 1, e, i, j);
        return L + R;
    }
} t;

int dfs(int u, int p, int h, int d) {
    int msz = 0, vsz;
    Level[u] = h, Parent[u] = p;
    sz[u] = 1;
    par[u][0] = p;
    dep[u] = dep[p] + 1;
    for(int i = 1; i <= LG; i++)
        par[u][i] = par[par[u][i - 1]][i - 1];

    for(auto it : x[u]) {
        if(it.first == p) continue;
        sz[u] += (vsz = dfs(it.first, u, h + 1, it.second));
        if(msz < vsz) {
            msz = vsz;
            heavy[u] = it.first;
        }
    }
    return sz[u];
}

void decom(int u, int p) {
    head[u] = p;
    pos[u] = cp;
    rpos[cp++] = u;

    if(~heavy[u]) decom(heavy[u], p);

    for(auto &it : x[u]) {
        if(it.first != Parent[u] and it.first != heavy[u])
            decom(it.first, it.first);
    }
}

int query(int u, int v) {
    if(u == v)return 0;
    int ans = 0;
    while(head[u] != head[v]) {
        if(Level[head[u]] > Level[head[v]]) swap(u, v);
        ans += t.query(1, 1, n, pos[head[v]], pos[v]);
        v = Parent[head[v]];
    }
    if(u == v) {
        return ans;
    }

    if(pos[u] > pos[v]) swap(u, v);
    ans += t.query(1, 1, n, pos[u] + 1, pos[v]);
    return ans;
}

int lca(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    for(int k = LG; k >= 0; k--)
        if(dep[par[u][k]] >= dep[v]) u =
                par[u][k];
    if(u == v) return u;
    for(int k = LG; k >= 0; k--)
        if(par[u][k] != par[v][k])
            u = par[u][k], v = par[v][k];
    return par[u][0];
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
        for(int i = 1; i <= n; i++)cin >> a[i];
        for(int i = 1; i < n; i++) {
            int u, v; cin >> u >> v; ++u; ++v;
            x[u].push_back({v, a[v]});
            x[v].push_back({u, a[u]});
        }

        memset(heavy, -1, sizeof heavy);

        cp = 1;
        dfs(1, 0, 0, a[1]);
        decom(1, 1);

        t.build(1, 1, n);

        cout << "Case " << casee++ << ":" << endl;
        int q; cin >> q;
        while(q--) {
            int type; cin >> type;
            if(type == 0) {
                int u, v; cin >> u >> v; ++u; ++v;
                int Lca = lca(u, v);
                cout << query(u, v) + t.query(1, 1, n, pos[Lca], pos[Lca]) << endl;
            } else {
                int u, val; cin >> u >> val; ++u;
                t.upd(1, 1, n, pos[u], val);
                a[u] = val;
            }
        }

        for(int i = 1; i <= n; i++)x[i].clear();
    }


    return 0;
}
