/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1e6 + 5;
int tc, n, casee = 1, a[N];

struct ST {
    int t[3 * N];
    static const int inf = 1e9;
    ST() {
        memset(t, 0, sizeof t);
    }
    int sum(int L, int R) {
        return L + R;
    }
    void build(int n, int b, int e) {
        if(b == e) {
            t[n] = a[b];
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        t[n] = sum(t[l], t[r]);
    }
    void upd(int n, int b, int e, int i, int x) {
        if(b > i || e < i) return;
        if(b == e && b == i) {
            t[n] += x;
            return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        upd(l, b, mid, i, x);
        upd(r, mid + 1, e, i, x);
        t[n] = sum(t[l], t[r]);
    }
    int query(int n, int b, int e, int i, int j) {
        if(b > j || e < i) return 0;
        if(b >= i && e <= j) return t[n];
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        int L = query(l, b, mid, i, j);
        int R = query(r, mid + 1, e, i, j);
        return sum(L, R);
    }
} t;

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    int q; cin >> n >> q;
    t.build(1, 1, n);

    while(q--) {
        string s; cin >> s;
        if(s == "find") {
            int l, r ; cin >> l >> r;
            cout << t.query(1, 1, n, l, r) << endl;
        } else {
            int id, val; cin >> id >> val;
            t.upd(1, 1, n, id, val);
        }
    }


    return 0;
}
