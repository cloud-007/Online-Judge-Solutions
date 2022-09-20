/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e5 + 5;
int tc, n, a[sz], Time = 0, Tree[sz * 3], Lazy[sz * 3];
pair < int, int > Range[sz];
vector < int > x[sz];

void dfs(int u, int par) {
    Range[u].F = ++Time;
    for(auto i : x[u]) {
        if(i != par) {
            dfs(i, u);
        }
    }
    Range[u].S = Time;
}

void Propagate(int node, int b, int e) {
    if(Lazy[node]) {
        Tree[node] = (e - b + 1) - Tree[node];
        if(b != e) {
            Lazy[node * 2] ^= 1, Lazy[node * 2 + 1] ^= 1;
        }
        Lazy[node] = 0;
    }
}

void Update(int node, int b, int e, int i, int j) {
    Propagate(node, b, e);
    if(b > j || e < i)return;
    if(b >= i && e <= j) {
        Lazy[node] = 1;
        Propagate(node, b, e);
        return;
    }
    int mid = b + e >> 1, Left = node * 2, Right = Left | 1;
    Update(Left, b, mid, i, j);
    Update(Right, mid + 1, e, i, j);
    Tree[node] = Tree[Right] + Tree[Left];
}

int Query(int node, int b, int e, int i, int j) {
    Propagate(node, b, e);
    if(b > j || e < i)return 0;
    if(b >= i && e <= j)return Tree[node];
    int mid = b + e >> 1, Left = node * 2, Right = Left | 1;
    return Query(Left, b, mid, i, j) + Query(Right, mid + 1, e, i, j);
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n;
    for(int i = 2; i <= n; i++) {
        int v; cin >> v;
        x[v].push_back(i);
    }

    dfs(1, -1);

    for(int i = 1; i <= n; i++) {
        int u ; cin >> u;
        if(u)Update(1, 1, n, Range[i].F, Range[i].F);
    }

    int q; cin >> q;
    while(q--) {
        string s;
        int u; cin >> s >> u;
        if(s == "pow")Update(1, 1, n, Range[u].F, Range[u].S);
        else cout << Query(1, 1, n, Range[u].F, Range[u].S) << Endl;
    }


    return 0;
}
