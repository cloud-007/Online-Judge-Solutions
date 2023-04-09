/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"
#define mx 1000005

struct info {
    ll prop, sum;
} tree[mx * 4];

int arr[mx], n, q, u, v, c;
char ty;

void init(int node, int b, int e) {
    if(b == e) {
        tree[node].sum = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].sum = tree[Left].sum + tree[Right].sum;
}

ll query(int node, int b, int e, int i, int j, ll carry = 0) {
    if(i > e || j < b)
        return 0;

    if(b >= i and e <= j)return tree[node].sum + carry * (e - b + 1);

    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;

    ll p1 = query(Left, b, mid, i, j, carry + tree[node].prop);
    ll p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}

void update(int node, int b, int e, int i, int j, ll x) {
    if(i > e || j < b)
        return;
    if(b >= i && e <= j) {
        tree[node].sum += ((e - b + 1) * x);
        tree[node].prop += x;
        return;
    }
    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> q >> c;
    for(int i = 1; i <= n; i++)arr[i] = c;
    init(1, 1, n);
    while(q--) {
        cin >> ty >> u;
        if(ty == 'Q') {
            cout << query(1, 1, n, u, u) << endl;
        } else {
            cin >> v >> c;
            update(1, 1, n, u, v, c);
        }
    }



    return 0;
}
