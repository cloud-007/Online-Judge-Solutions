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
    int t[4 * N];
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
        t[n] = min(t[l], t[r]);
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
        t[n] = min(t[l], t[r]);
    }
    int query(int n, int b, int e, int i, int j) {
        if(b > j || e < i) return inf;
        if(b >= i && e <= j) return t[n];
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        int L = query(l, b, mid, i, j);
        int R = query(r, mid + 1, e, i, j);
        return min(L, R);
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
        cin >> n;
        for(int i = 1; i <= n; i++)cin >> a[i];
        t.build(1, 1, n);

        int mx = 0;

        for(int i = 1; i <= n; i++) {
            int now = a[i];
            if(i < n) {
                int l = i + 1, r = n, id = -1;
                while(l <= r) {
                    int mid = (l + r) >> 1;
                    int cur = t.query(1, 1, n, l, mid);
                    if(cur >= a[i]) {
                        l = mid + 1;
                        id = mid;
                    } else r = mid - 1;
                }
                if(~id)now += (id - i) * a[i];
            }
            if(i > 1) {
                int l = 1, r = i - 1, id = -1;
                while(l <= r) {
                    int mid = (l + r) >> 1;
                    int cur = t.query(1, 1, n, mid, r);
                    if(cur >= a[i]) {
                        r = mid - 1;
                        id = mid;
                    } else l = mid + 1;
                }
                if(~id)now += (i - id) * a[i];
            }
            mx = max(mx, now);
        }
        cout << "Case " << casee++ << ": " << mx << endl;

    }


    return 0;
}
