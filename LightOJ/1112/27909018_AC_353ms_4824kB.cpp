/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(NULL)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 1e5 + 5;
int tc, n, q, ty, l, r, a[sz], casee = 1;
ll tree[sz * 3];

void build(int node, int b, int e) {
    if(b == e) {
        tree[node] = a[b];
        return;
    }
    int mid = (b + e) / 2;
    build(node * 2, b, mid);
    build(node * 2 + 1, mid + 1, e);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int b, int e, int i, int j) {
    if(i > e || j < b)return 0;
    if(b >= i && e <= j)return tree[node];
    int mid = (b + e) / 2;
    return query(node * 2, b, mid, i, j) + query(node * 2 + 1, mid + 1, e, i, j);
}

void update(int node, int b, int e, int id, int type, int new_value) {
    if(id > e || id < b)return;
    if(b >= id && e <= id) {
        if(type)tree[node] += new_value;
        else tree[node] = 0;
        return;
    }
    int mid = (b + e) / 2;
    update(node * 2, b, mid, id, type, new_value);
    update(node * 2 + 1, mid + 1, e, id, type, new_value);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}


int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    scanf("%d", &tc);
    while(tc--) {
        memset(tree, 0, sizeof tree);
        scanf("%d %d", &n, &q);
        for(int i = 1; i <= n; i++)scanf("%d", &a[i]);
        build(1, 1, n);
        printf("Case %d:\n", casee++);
        while(q--) {
            scanf("%d%d", &ty, &l);
            l++;
            if(ty == 1) {
                printf("%lld\n", query(1, 1, n, l, l));
                update(1, 1, n, l, 0, 0);
            } else if(ty == 2) {
                scanf("%d", &r);
                update(1, 1, n, l, 1, r);
            } else {
                scanf("%d", &r);
                r++;
                printf("%lld\n", query(1, 1, n, l, r));
            }
        }
    }

    return 0;
}
