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

pair < int, int > reduceFraction(int x, int y) {
    int d; d = __gcd(x, y);
    x = x / d; y = y / d;
    return {x, y};
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
        if(lazy[n] == -1) return;
        t[n] = lazy[n] * (e - b + 1);
        if(b != e) {
            lazy[lc] = lazy[n];
            lazy[rc] = lazy[n];
        }
        lazy[n] = -1;
    }
    inline long long combine(long long a, long long b) {
        return a + b;
    }
    inline void pull(int n) {
        t[n] = t[lc] + t[rc];
    }
    void build(int n, int b, int e) {
        lazy[n] = -1;
        if(b == e) {
            t[n] = a[b];
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
    cin >> tc;
    while(tc--) {
        int q; cin >> n >> q;
        t.build(1, 1, n);
        cout << "Case " << casee++ << ":" << endl;
        while(q--) {
            int type; cin >> type;
            if(type == 1) {
                int l, r, val; cin >> l >> r >> val;
                t.upd(1, 1, n, ++l, ++r, val);
            } else {
                int l, r; cin >> l >> r;
                int cur = t.query(1, 1, n, ++l, ++r);
                int len = r - l + 1;
                if(cur % len == 0) {
                    cout << cur / len << endl;
                } else {
                    pair < int, int > p = reduceFraction(cur, len);
                    cout << p.F << "/" << p.S << endl;
                }
            }
        }
    }


    return 0;
}
