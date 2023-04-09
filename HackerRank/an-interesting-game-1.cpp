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
        tree[node] = {a[b], b};
        return;
    }
    int left = node * 2, right = node * 2 + 1, mid = (b + e) >> 1;
    build(left, b, mid);
    build(right, mid + 1, e);
    if(tree[left].F > tree[right].F)tree[node] = tree[left];
    else tree[node] = tree[right];
}

pair < int, int > query(int node, int b, int e, int i, int j) {
    if(i > e || j < b)return {0, 0};
    if(b >= i && e <= j)return tree[node];
    int left = node * 2, right = node * 2 + 1, mid = (b + e) >> 1;
    pair < int, int > p = query(left, b, mid, i, j);
    pair < int, int > q = query(right, mid + 1, e, i, j);
    if(p.F > q.F)return p;
    else return q;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 1; i <= n; i++)cin >> a[i];
        build(1, 1, n);
        int id = n, cnt = 0;
        while(id >= 1) {
            pair < int, int > cur = query(1, 1, n, 1, id);
            ++cnt;
            id = cur.S - 1;
        }
        cout << (cnt & 1 ? "BOB" : "ANDY") << endl;
    }


    return 0;
}
