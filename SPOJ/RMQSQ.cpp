/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1e5 + 5;
int arr[N], tree[N * 3], tc, n, q, u, v, casee = 1, type;

void init(int node, int b, int e) {
    if(b == e) {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = min(tree[Left], tree[Right]);
}

int query(int node, int b, int e, int i, int j) {
    if(i > e || j < b)
        return INT_MAX;
    if(b >= i && e <= j)return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return min(p1,  p2);
}


int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> arr[i];
    cin >> q;
    memset(tree, 0, sizeof tree);
    init(1, 1, n);
    while(q--) {
        cin >> u >> v;
        cout << query(1, 1, n, ++u, ++v) << endl;
    }


    return 0;
}
