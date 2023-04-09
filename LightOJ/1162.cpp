/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1e5 + 5;
int tc, n, casee = 1, cp;
int Level[N], rpos[N], heavy[N], a[N]; // Heavy == Special child, means node of MaxSubTreeSize;
int Parent[N], head[N], pos[N];
vector < pair < int, int >> x[N];

struct ST {
    int t[3 * N][2];
    static const int inf = 1e9;
    ST() {
        memset(t, 0, sizeof t);
    }
    void build(int n, int b, int e) {
        if(b == e) {
            t[n][0] = t[n][1] = a[rpos[b]];
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        t[n][1] = max(t[l][1], t[r][1]);
        t[n][0] = min(t[l][0], t[r][0]);
    }
    void upd(int n, int b, int e, int i, int x) {
        if(b > i || e < i) return;
        if(b == e && b == i) {
            t[n][0] = t[n][1] = x;
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        upd(l, b, mid, i, x);
        upd(r, mid + 1, e, i, x);
        t[n][1] = max(t[l][1], t[r][1]);
        t[n][0] = min(t[l][0], t[r][0]);
    }
    pair<int, int> query(int n, int b, int e, int i, int j) {
        if(b > j || e < i) return {-INT_MAX, INT_MAX};
        if(b >= i && e <= j) return {t[n][1], t[n][0]};
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        pair<int, int> L = query(l, b, mid, i, j);
        pair<int, int> R = query(r, mid + 1, e, i, j);
        return {max(L.F, R.F), min(L.S, R.S)};
    }
} t;

int dfs(int u, int p, int h, int d) {
    int sz = 1, msz = 0, vsz;
    Level[u] = h, Parent[u] = p, a[u] = d;

    for(auto it : x[u]) {
        if(it.first == p) continue;
        sz += (vsz = dfs(it.first, u, h + 1, it.second));
        if(msz < vsz) {
            msz = vsz;
            heavy[u] = it.first;
        }
    }
    return sz;
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

pair<int, int> query(int u, int v) {
    if(u == v) return {INT_MIN, INT_MAX};
    pair<int, int > Ans = {INT_MIN, INT_MAX};
    // cout<<"Initial Head of "<<u<<" and "<<v<<" is "<<head[u]<<" "<<head[v]<<endl;
    while(head[u] != head[v]) {
        // cout<<"Node = "<<u<<" "<<v<<endl;
        // cout<<"Level = "<<Level[u]<<" "<<Level[v]<<endl;
        // cout<<"Head "<<u<<" "<<head[u]<<" "<<v<<" "<<head[v]<<endl;
        if(Level[head[u]] > Level[head[v]]) swap(u, v);
        pair < int, int > p = t.query(1, 1, n, pos[head[v]], pos[v]);
        Ans.F = max(Ans.F, p.F);
        Ans.S = min(Ans.S, p.S);
        // cout<<"QQ "<<v<<" "<<head[v]<<" "<<pos[head[v]]<<" "<<pos[v]<<endl;
        v = Parent[head[v]];
    }
    // cout<<"Head! "<<u<<" "<<head[u]<<" "<<v<<" "<<head[v]<<endl;
    if(u == v) return Ans;

    if(pos[u] > pos[v]) swap(u, v);
    pair < int, int > p = t.query(1, 1, n, pos[u] + 1, pos[v]);
    Ans.F = max(Ans.F, p.F);
    Ans.S = min(Ans.S, p.S);
    // cout<<"QQ! "<<pos[u] <<" "<<pos[v]<<endl;
    return Ans;
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
            int u, v, c; cin >> u >> v >> c;
            x[u].push_back({v, c});
            x[v].push_back({u, c});
        }
        cp = 1;

        memset(heavy, -1, sizeof heavy);

        dfs(1, 0, 0, 0);
        decom(1, 0);
        t.build(1, 1, n);

        cout << "Case " << casee++ << ":" << endl;

        int q; cin >> q;
        while(q--) {
            int u, v; cin >> u >> v;
            pair < int, int > Ans = query(u, v);
            cout << Ans.S << " " << Ans.F << endl;
        }
        for(int i=1;i<=n;i++)x[i].clear();
    }


    return 0;
}
