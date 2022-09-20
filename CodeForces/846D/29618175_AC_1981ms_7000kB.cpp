/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 505;
int tc, n, m, k, q, x, y, t, vis[sz][sz], b[sz][sz], tree[sz][sz * 4];

set < pair < int, int >> st;

struct R {
    int x, y, time;
    bool operator<(R a)const {
        if(time == a.time) {
            if(x == a.x)return y < a.y;
            return x < a.x;
        }
        return time < a.time;
    }
};

vector < R > v;

int bit[sz][sz], ans = INT_MAX;


void build(int node, int bb, int e, int idx) {
    if(bb == e) {
        tree[idx][node] = b[idx][bb];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (bb + e) / 2;
    build(Left, bb, mid, idx);
    build(Right, mid + 1, e, idx);
    tree[idx][node] = max(tree[idx][Left], tree[idx][Right]);
}

int query(int node, int bb, int e, int i, int j, int idx) {
    if(i > e || j < bb)
        return -INT_MAX;
    if(bb >= i && e <= j)return tree[idx][node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (bb + e) / 2;
    int p1 = query(Left, bb, mid, i, j, idx);
    int p2 = query(Right, mid + 1, e, i, j, idx);
    return max(p1, p2);
}

void update(int x, int y, int val) {
    for(; x < sz; x += x & -x)
        for(int j = y; j < sz; j += j & -j)
            bit[x][j] += val;
}

int get(int x, int y) {
    ll ans = 0;
    for(; x > 0 ; x -= x & -x)
        for(int j = y ; j > 0 ; j -= j & -j)
            ans += bit[x][j];
    return ans ;
}

int get(int x1, int y1, int x2, int y2) {
    return get(x2, y2) - get(x1 - 1, y2) - get(x2, y1
            - 1) + get(x1 - 1, y1 - 1) ;
}

void check() {
    for(int i = 1; i <= n - k + 1; i++) {
        for(int j = 1; j <= m - k + 1; j++) {
            int sum = get(i, j, i + k - 1, j + k - 1);
            if(sum == k * k) {
                int mx = 0, yy = j;
                for(int xx = i; xx <= i + k - 1; xx++) {
                    mx = max(mx, query(1, 1, m, yy, yy + k - 1, xx));
                }
                ans = min(ans, mx);
            }
        }
    }
}


int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> m >> k >> q;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            b[i][j] = INT_MAX;
        }
    }

    while(q--) {
        cin >> x >> y >> t;
        b[x][y] = min(b[x][y], t);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(b[i][j] != INT_MAX)update(i, j, 1);
            if(b[i][j] == INT_MAX)b[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; i++) {
        build(1, 1, m, i);
    }

    check();

    if(ans == INT_MAX)ans = -1;

    cout << ans << endl;

    return 0;
}
