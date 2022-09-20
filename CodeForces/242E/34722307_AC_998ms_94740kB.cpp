/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a[N], tree[N * 3][20], lazy[N * 3][20];



void propagate(int node, int b, int e, int curBit) {
    int Left = node * 2, Right = node * 2 + 1;
    tree[node][curBit] = (e - b + 1) - tree[node][curBit];
    if(b != e) {
        lazy[Left][curBit] ^= 1;
        lazy[Right][curBit] ^= 1;
    }
    lazy[node][curBit] = 0;
}

void build(int node, int b, int e, int curBit) {
    if(b == e) {
        if(a[b] & (1 << curBit)) {
            tree[node][curBit] = 1;
        }
        return;
    }
    int Left = node * 2; int Right = node * 2 + 1;
    int mid = (b + e) >> 1;
    build(Left, b, mid, curBit);
    build(Right, mid + 1, e, curBit);
    tree[node][curBit] = tree[Left][curBit] + tree[Right][curBit];
}

void update(int node, int b,  int e, int i, int j, int curBit) {
    int Left = node * 2; int Right = node * 2 + 1;
    int mid = (b + e) >> 1;
    if(lazy[node][curBit])propagate(node, b, e, curBit);
    if(b > j || e < i)return;
    if(b >= i && e <= j) {
        propagate(node, b, e, curBit);
        return;
    }
    update(Left, b, mid, i, j, curBit);
    update(Right, mid + 1, e, i, j, curBit);
    tree[node][curBit] = tree[Left][curBit] + tree[Right][curBit];
}

int query(int node, int b, int e, int i, int j, int curBit) {
    int  Left = node * 2; int Right = node * 2 + 1;
    int mid = (b + e) >> 1;
    if(lazy[node][curBit])propagate(node, b, e, curBit);
    if(b > j || e < i)return 0;
    if(b >= i && e <= j)return tree[node][curBit];
    int p = query(Left, b, mid, i, j, curBit);
    int q = query(Right, mid + 1, e, i, j, curBit);
    return p + q;
}



int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 0; i < 20; i++)build(1, 1, n, i);

    int q; cin >> q;
    while(q--) {

        int type, l, r;
        cin >> type >> l >> r;
        if(type == 1) {
            ll Ans = 0;
            for(int i = 0; i < 20; i++) {
                Ans += 1ll * query(1, 1, n, l, r, i) << i;
            }
            cout << Ans << endl;
        } else {
            int x; cin >> x;
            for(int i = 0; i < 20; i++) {
                if(x & (1 << i)) {
                    update(1, 1, n, l, r, i);
                }
            }
        }

    }

    return 0;
}
