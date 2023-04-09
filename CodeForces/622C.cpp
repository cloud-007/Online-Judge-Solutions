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

pair < int, int > tree[N * 3][2];

pair<int, int> retMn = {INT_MAX, 0};
pair<int, int>retMx = {-INT_MAX, 0};

void build(int node, int b, int e) {
    if(b == e) {
        tree[node][0].F = tree[node][1].F = a[b];
        tree[node][0].S = b, tree[node][1].S = b;
        return;
    }
    int mid = (b + e) >> 1, left = node * 2, right = left | 1;
    build(left, b, mid);
    build(right, mid + 1, e);
    if(tree[left][0].F < tree[right][0].F)tree[node][0] = tree[left][0];
    else tree[node][0] = tree[right][0];
    if(tree[left][1].F > tree[right][1].F)tree[node][1] = tree[left][1];
    else tree[node][1] = tree[right][1];
}

pair<int, int> query(int node, int b, int e, int i, int j, int type) {
    if(i > e || j < b)return type == 0 ? retMn : retMx;
    if(b >= i && e <= j)return tree[node][type];
    int left = node * 2;
    int right = left | 1;
    int mid = (b + e) / 2;
    pair<int, int> p = query(left, b, mid, i, j, type);
    pair<int, int> q = query(right, mid + 1, e, i, j, type);
    if(type == 0) {
        if(p.F < q.F)return p;
        else return q;
    } else {
        if(p.F > q.F)return p;
        else return q;
    }
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    int q; scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++)scanf("%d", &a[i]);
    build(1, 1, n);
    while(q--) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        pair<int, int> mn = query(1, 1, n, l, r, 0);
        pair<int, int> mx = query(1, 1, n, l, r, 1);
        if(mn.F != x)printf("%d\n", mn.S);
        else if(mx.F != x)printf("%d\n", mx.S);
        else printf("-1\n");
    }

    return 0;
}
