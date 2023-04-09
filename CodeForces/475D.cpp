/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 3e5 + 5, M = 1e6 + 5;
int tc, n, casee = 1, a[N], table[N][25];
int Log[M];

void makeSparseTable(int n) {
    for(int i = 0; i < n; i++)table[i][0] = a[i];
    for(int i = 2; i <= n; i++)Log[i] = Log[i / 2] + 1;
    for(int j = 1; j < 24; j++) {
        for(int i = 0; i + (1 << j) <= n; i++) {
            table[i][j] = __gcd(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r, int n) {
    int dis = r - l + 1;
    dis = 32 - __builtin_clz(dis) - 1;
    int x = __gcd(table[l][dis], table[r - (1 << dis) + 1][dis]);
    return x;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> n;
    map < int, ll > mp;

    for(int i = 0; i < n; i++)cin >> a[i];

    makeSparseTable(n);

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int id = j;
            int l = j, r = n - 1;
            int gd = query(i, j, n);
            while(l <= r) {
                int mid  = (l + r) >> 1;
                if(query(i, mid, n) == gd) {
                    id = mid, l = mid + 1;
                } else r = mid - 1;
            }
            mp[gd] += (ll)(id - j + 1);
            j = id;
        }
    }

    int q; cin >> q;
    while(q--) {
        int x; cin >> x;
        cout << mp[x] << endl;
    }



    return 0;
}
