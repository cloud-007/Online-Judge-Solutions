/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define cloud_007 ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

#define mx 200005
int arr[mx], tree[mx * 3], tc, n, q, u, v, casee = 1, type;
string s;
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
    tree[node] = tree[Left] + tree[Right];
}
int query(int node, int b, int e, int i, int j) {
    if(i > e | j < b)
        return 0;
    if(b >= i && e <= j)return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2;
}
void update(int node, int b, int e, int i, int newvalue) {
    if(i > e || i < b)
        return;
    if(b >= i && e <= i) {
        tree[node] = newvalue;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    while(cin >> n && n) {
        for(int i = 1; i <= n; i++)cin >> arr[i];
        init(1, 1, n);
        if(casee > 1)cout << endl;
        cout << "Case " << casee++ << ":" << endl;
        while(cin >> s && s != "END") {
            cin >> u >> v;
            if(s == "M") {
                cout << query(1, 1, n, u, v) << endl;
            } else {
                update(1, 1, n, u, v);
            }
        }
    }


    return 0;
}
