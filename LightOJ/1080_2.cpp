/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 cin.tie(0), cout.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"
#define i64 int64_t

int tc, q, l, r, n, casee = 1;
string s;
char ty;

struct info {
    i64 prop, sum;
} tree[100005 * 3];

void init() {
    for(int i = 0; i < 100005 * 3; i++)
        tree[i].sum = tree[i].prop = 0;
}

void build(int node, int b, int e) {
    if(b == e) {
        tree[node].sum = 0;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;
    build(left, b, mid);
    build(right, mid + 1, e);
    tree[node].sum = tree[left].sum + tree[right].sum;
}

int query(int node, int b, int e, int i, int j, int carry = 0) {
    if(i > e || j < b)
        return 0;

    if(b >= i and e <= j)
        return tree[node].sum + carry * (e - b + 1);

    int left = node << 1;
    int right = (node << 1) + 1;
    int mid = (b + e) >> 1;

    int p1 = query(left, b, mid, i, j, carry + tree[node].prop);
    int p2 = query(right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}
void update(int node, int b, int e, int i, int j, i64 x) {
    if(i > e || j < b)
        return;
    if(b >= i && e <= j) {
        tree[node].sum += ((e - b + 1) * x);
        tree[node].prop += x;
        return;
    }
    int left = node * 2;
    int right = (node * 2) + 1;
    int mid = (b + e) / 2;
    update(left, b, mid, i, j, x);
    update(right, mid + 1, e, i, j, x);
    tree[node].sum = tree[left].sum + tree[right].sum + (e - b + 1) * tree[node].prop;
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        memset(tree, 0, sizeof tree);
        cin >> s >> q;
        s = "#" + s;
        n = s.size();
        build(1, 1, n);
        cout << "Case " << casee++ << ":" << endl;
        while(q--) {
            cin >> ty;
            if(ty == 'I') {
                cin >> l >> r;
                update(1, 1, n, l, r, 1);
            } else {
                cin >> l;
                int val = query(1, 1, n, l, l);
                if(val & 1) {
                    if(s[l] == '1')cout << 0 << endl;
                    else cout << 1 << endl;
                } else cout << s[l] << endl;
            }
        }
    }

    return 0;
}
