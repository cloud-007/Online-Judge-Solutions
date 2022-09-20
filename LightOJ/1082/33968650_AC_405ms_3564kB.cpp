/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N], tree[N * 3];

void build(int node, int b, int e) {
    if(b == e) {
        tree[node] = a[b];
        return;
    }
    int mid = (b + e) >> 1;
    int left = node * 2, right = node * 2 + 1;
    build(left, b, mid);
    build(right, mid + 1, e);
    tree[node] = min(tree[left], tree[right]);
}

int query(int node, int b, int e, int i, int j) {
    if(i > e || j < b)return INT_MAX;
    if(b >= i && e <= j)return tree[node];
    int mid = (b + e) >> 1;
    int left = node * 2, right = node * 2 + 1;
    return min(query(left, b, mid, i, j), query(right, mid + 1, e, i, j));
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {
        int q; cin >> n >> q;
        for(int i = 1; i <= n; i++)cin >> a[i];
        build(1, 1, n);
        cout << "Case " << casee++ << ":" << endl;
        while(q--) {
            int l, r; cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
        }
    }


    return 0;
}
