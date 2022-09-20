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
int n, k, q, l, r, mp[sz], tree[sz * 3];

void build(int node, int b, int e)
{
    if (b == e)
    {
        if(mp[b] >= k)tree[node] = 1;
        else tree[node] = 0;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    build(Left, b, mid);
    build(Right, mid + 1, e);
    tree[node] = tree[Left] + tree[Right];
}

int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0;
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2;
}

int main()
{
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n >> k >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> l >> r;
        mp[l]++, mp[r + 1]--;
    }
    for(int i = 1; i <= 200000; i++)mp[i] += mp[i - 1];
    build(1, 1, 200000);
    while(q--)
    {
        cin >> l >> r;
        cout << query(1, 1, 200000, l, r) << endl;
    }
    return 0;
}
