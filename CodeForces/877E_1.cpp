/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N], arr[N], st[N], en[N], Time;
vector < int > x[N];

void dfs(int u, int p = -1) {
    st[u] = ++Time;
    arr[Time] = u;
    for(auto i : x[u]) {
        if(i == p)continue;
        dfs(i, u);
    }
    en[u] = Time;
}

struct ST {
#define lc (n << 1)
#define rc ((n << 1) | 1)
    long long t[4 * N], lazy[4 * N];
    ST() {
        memset(t, 0, sizeof t);
        memset(lazy, 0, sizeof lazy);
    }
    inline void push(int n, int b, int e) {
        if(lazy[n] == 0) return;
        t[n] = (e - b + 1) - t[n];
        if(b != e) {
            lazy[lc] ^= 1;
            lazy[rc] ^= 1;
        }
        lazy[n] = 0;
    }
    inline long long combine(long long a, long long b) {
        return a + b;
    }
    inline void pull(int n) {
        t[n] = t[lc] + t[rc];
    }
    void build(int n, int b, int e) {
        lazy[n] = 0;
        if(b == e) {
            t[n] = a[arr[b]];
            return;
        }
        int mid = (b + e) >> 1;
        build(lc, b, mid);
        build(rc, mid + 1, e);
        pull(n);
    }
    void upd(int n, int b, int e, int i, int j, long long v) {
        push(n, b, e);
        if(j < b || e < i) return;
        if(i <= b && e <= j) {
            lazy[n] = v; //set lazy
            push(n, b, e);
            return;
        }
        int mid = (b + e) >> 1;
        upd(lc, b, mid, i, j, v);
        upd(rc, mid + 1, e, i, j, v);
        pull(n);
    }
    long long query(int n, int b, int e, int i, int j) {
        push(n, b, e);
        if(i > e || b > j) return 0;  //return null
        if(i <= b && e <= j) return t[n];
        int mid = (b + e) >> 1;
        return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
    }
} t;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    for(int u = 2; u <= n; u++) {
        int v; cin >> v;
        x[u].push_back(v);
        x[v].push_back(u);
    }

    for(int i = 1; i <= n; i++)cin >> a[i];
    dfs(1);

    t.build(1, 1, n);

    int q; cin >> q;
    while(q--) {
        int v;
        string s; cin >> s >> v;
        //cout << s <<" "<<v<<endl;
        if(s == "get") {
            cout << t.query(1, 1, n, st[v], en[v]) << endl;
        } else {
            t.upd(1, 1, n, st[v], en[v], 1);
        }
    }


    return 0;
}
