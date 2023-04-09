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

struct ST {
#define lc (n << 1)
#define rc ((n << 1) | 1)
    long long t[4 * N][3], lazy[4 * N];
    ST() {
        memset(t, 0, sizeof t);
        memset(lazy, 0, sizeof lazy);
    }
    inline void push(int n, int b, int e) {
        if(lazy[n] == 0) return;
        if(lazy[n] == 1) {
            t[n][2] = t[n][1];
            t[n][1] = t[n][0];
            t[n][0] = (e - b + 1) - (t[n][1] + t[n][2]);
        } else {
            t[n][1] = t[n][2];
            t[n][2] = t[n][0];
            t[n][0] = (e - b + 1) - (t[n][2] + t[n][1]);
        }
        if(b != e) {
            lazy[lc] += lazy[n];
            lazy[rc] += lazy[n];
            lazy[lc] %= 3;
            lazy[rc] %= 3;
        }
        lazy[n] = 0;
    }
    inline long long combine(long long a, long long b) {
        return a + b;
    }
    inline void pull(int n, int i) {
        t[n][i] = t[lc][i] + t[rc][i];
    }
    void build(int n, int b, int e) {
        lazy[n] = 0;
        if(b == e) {
            t[n][0] = 1;
            t[n][1] = t[n][2] = 0;
            return;
        }
        int mid = (b + e) >> 1;
        build(lc, b, mid);
        build(rc, mid + 1, e);
        pull(n, 0); pull(n, 1); pull(n, 2);
    }
    void upd(int n, int b, int e, int i, int j, long long v) {
        push(n, b, e);
        if(j < b || e < i) return;
        if(i <= b && e <= j) {
            lazy[n]++; //set lazy
            push(n, b, e);
            return;
        }
        int mid = (b + e) >> 1;
        upd(lc, b, mid, i, j, v);
        upd(rc, mid + 1, e, i, j, v);
        pull(n, 0); pull(n, 1); pull(n, 2);
    }
    long long query(int n, int b, int e, int i, int j) {
        push(n, b, e);
        if(i > e || b > j) return 0;  //return null
        if(i <= b && e <= j) return t[n][0];
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
            int type, l, r; cin >> type >> l >> r;
            if(type == 0) {
                t.upd(1, 1, n, ++l, ++r, 1);
            } else {
                cout << t.query(1, 1, n, ++l, ++r) << endl;
            }
        }
    }


    return 0;
}
