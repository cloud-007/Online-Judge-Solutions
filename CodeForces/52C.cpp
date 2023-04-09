/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(0);cin.tie(0)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e5 + 10, Q = 1e9;
const ll INF = 1e18;

ll Tree[sz * 3], Lazy[sz * 3], arr[sz];

void Propagate(int node, int b, int e) {
    if(Lazy[node]) {
        Lazy[node * 2] += Lazy[node], Tree[node * 2] += Lazy[node];
        Lazy[node * 2 + 1] += Lazy[node], Tree[node * 2 + 1] += Lazy[node];
        Lazy[node] = 0;
    }
}

void init(int node, int b, int e) {
    if(b == e) {
        Tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    Tree[node] = min(Tree[Left], Tree[Right]);
}

void Update(int node, int b, int e, int i, int j, int value) {
    if(j < b || e < i)return;
    if(b >= i && e <= j) {
        Tree[node] += value;
        Lazy[node] += value;
        return;
    }
    Propagate(node, b, e);
    int Left = node * 2, Right = Left | 1, mid = b + e >> 1;
    Update(Left, b, mid, i, j, value);
    Update(Right, mid + 1, e, i, j, value);
    Tree[node] = min(Tree[Left], Tree[Right]);
}

ll query(int node, int b, int e, int i, int j) {
    if(j < b || e < i)return INF;
    if(b >= i && e <= j) {
        return Tree[node];
    }
    int Left = node * 2, Right = Left + 1, mid = b + e >> 1;
    Propagate(node, b, e);
    return min(query(Left, b, mid, i, j), query(Right, mid + 1, e, i, j));
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    int n; cin >> n;
    for(int i = 1; i <= n; i++)cin >> arr[i];
    init(1, 1, n);
    int q; cin >> q;
    while(q--) {
        int lf, rf, v = Q;
        cin >> lf >> rf;
        if(cin.peek() != '\n')    cin >> v;
        lf++, rf++;
        if(v == Q) {
            if(lf <= rf) {
                cout << query(1, 1, n, lf, rf) << endl;
            } else {
                cout << min(query(1, 1, n, lf, n), query(1, 1, n, 1, rf)) << Endl;
            }
        } else {
            if(lf <= rf) {
                Update(1, 1, n, lf, rf, v);
            } else {
                Update(1, 1, n, lf, n, v);
                Update(1, 1, n, 1, rf, v);
            }
        }
    }


    return 0;
}
