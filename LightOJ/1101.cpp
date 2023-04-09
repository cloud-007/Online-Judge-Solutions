/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, cp;
int Level[N], rpos[N], heavy[N], a[N]; // Heavy == Special child, means node of MaxSubTreeSize;
int Parent[N], head[N], pos[N];
vector < pair < int, int >> x[N];

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
        t[n] = max(t[l], t[r]);
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
        t[n] = max(t[l], t[r]);
    }
    int query(int n, int b, int e, int i, int j) {
        if(b > j || e < i) return -inf;
        if(b >= i && e <= j) return t[n];
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        int L = query(l, b, mid, i, j);
        int R = query(r, mid + 1, e, i, j);
        return max(L, R);
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

int query(int u, int v) {
    if(u == v) return 0;
    int ans = INT_MIN;
    // cout<<"Initial Head of "<<u<<" and "<<v<<" is "<<head[u]<<" "<<head[v]<<endl;
    while(head[u] != head[v]) {
        // cout<<"Node = "<<u<<" "<<v<<endl;
        // cout<<"Level = "<<Level[u]<<" "<<Level[v]<<endl;
        // cout<<"Head "<<u<<" "<<head[u]<<" "<<v<<" "<<head[v]<<endl;
        if(Level[head[u]] > Level[head[v]]) swap(u, v);
        ans = max(ans, t.query(1, 1, n, pos[head[v]], pos[v]));
        // cout<<"QQ "<<v<<" "<<head[v]<<" "<<pos[head[v]]<<" "<<pos[v]<<endl;
        v = Parent[head[v]];
    }
    // cout<<"Head! "<<u<<" "<<head[u]<<" "<<v<<" "<<head[v]<<endl;
    if(u == v) return ans;

    if(pos[u] > pos[v]) swap(u, v);
    ans = max(ans, t.query(1, 1, n, pos[u] + 1, pos[v]));
    // cout<<"QQ! "<<pos[u] <<" "<<pos[v]<<endl;
    return ans;
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int find_set(int v) {
    if(v == Parent[v])
        return v;
    return Parent[v] = find_set(Parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(a != b) {
        Parent[b] = a;

    }
}

vector<Edge> edges;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        int m; cin >> n >> m;
        while(m--) {
            int u, v, c; cin >> u >> v >> c;
            edges.push_back({u, v, c});
        }
        sort(edges.begin(), edges.end());
        for(int i = 1; i <= n; i++)Parent[i] = i;

        for(auto i : edges) {
            if(find_set(i.u) != find_set(i.v)) {
                x[i.u].push_back({i.v, i.weight});
                x[i.v].push_back({i.u, i.weight});
                union_sets(i.u, i.v);
            }
        }

        memset(heavy, -1, sizeof heavy);
        cp = 0;
        dfs(1, 0, 0, 0);
        decom(1, 1);

        t.build(1, 1, n);

        cout << "Case " << casee++ << ":" << endl;

        int q; cin >> q;
        while(q--) {
            int u, v; cin >> u >> v;
            cout << query(u, v) << endl;
        }


        edges.clear();
        for(int i = 1; i <= n; i++)x[i].clear();
    }


    return 0;
}
