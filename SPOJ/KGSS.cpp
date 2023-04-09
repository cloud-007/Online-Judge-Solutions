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
int tc, n, a[N];
pair < int, int > tree[N * 3];

void build(int node, int b, int e) {
    if(b == e) {
        tree[node] = {-INT_MAX, a[b]};
        return;
    }
    int left = node * 2, right = left + 1, mid = (b + e) / 2;
    build(left, b, mid);
    build(right, mid + 1, e);
    vector < int > v;
    v.push_back(tree[left].F);
    v.push_back(tree[right].F);
    v.push_back(tree[left].S);
    v.push_back(tree[right].S);
    sort(v.begin(), v.end());
    tree[node] = {v[2], v[3]};
    v.clear();
}

void update(int node, int b, int e, int i, int value) {
    if(i > e || i < b)return;
    if(b >= i && e <= i) {
        tree[node] = {-INT_MAX, value};
        return;
    }
    int left = node * 2, right = left + 1, mid = (b + e) / 2;
    update(left, b, mid, i, value);
    update(right, mid + 1, e, i, value);
    vector < int > v;
    v.push_back(tree[left].F);
    v.push_back(tree[right].F);
    v.push_back(tree[left].S);
    v.push_back(tree[right].S);
    sort(v.begin(), v.end());
    tree[node] = {v[2], v[3]};
    v.clear();
}

pair < int, int > query(int node, int b, int e, int i, int j) {
    if(i > e || j < b)
        return {-1e7, -1e7};
    if(b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    pair < int, int > p1 = query(Left, b, mid, i, j);
    pair < int, int > p2 = query(Right, mid + 1, e, i, j);
    vector < int > v;
    v.push_back(p1.F);
    v.push_back(p2.F);
    v.push_back(p1.S);
    v.push_back(p2.S);
    sort(v.begin(), v.end());
    Left = v[2], Right = v[3]; v.clear();
    return {Left, Right};
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> a[i];
    build(1, 1, n);
    int q; cin >> q;
    while(q--) {
        char c; int i, j;
        cin >> c >> i >> j;
        if(c == 'U') {
            update(1, 1, n, i, j);
        } else {
            pair < int, int > ans = query(1, 1, n, i, j);
            cout << ans.F + ans.S << endl;
        }
    }


    return 0;
}
