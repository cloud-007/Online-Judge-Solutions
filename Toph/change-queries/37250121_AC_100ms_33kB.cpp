/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N], Timer, st[N], en[N];
vector < int > x[N];

void dfs(int u, int p = -1) {
    st[u] = ++Timer;
    for(auto i : x[u])if(i != p)dfs(i, u);
    en[u] = Timer;
}

struct ST {
    ll t[4 * N];
    static const int inf = 1e9;
    ST() {
        memset(t, 0, sizeof t);
    }
    void build(int n, int b, int e) {
        if(b == e) {
            t[n] = a[b];
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
    ll query(int n, int b, int e, int i, int j) {
        if(b > j || e < i) return 0;
        if(b >= i && e <= j) return t[n];
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        ll L = query(l, b, mid, i, j);
        ll R = query(r, mid + 1, e, i, j);
        return L + R;
    }
} T;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    int q; cin >> n >> q;
    for(int i = 1; i <= n; i++)cin >> a[i];

    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        x[u].push_back(v);
        x[v].push_back(u);
    }

    dfs(1, -1);

    T.build(1, 1, n);

    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int node, cost; cin >> node >> cost;
            T.upd(1, 1, n, st[node], cost);
        } else {
            int node; cin >> node;
            cout << T.query(1, 1, n, st[node], en[node]) << endl;
        }
    }

    return 0;
}

