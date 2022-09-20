/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1e5 + 5;
int tc, n, a[N], k;
ll Bit[N][13];

void update(int x, int y, ll v) {
    while(x < N) {
        Bit[x][y] += v;
        x += x & (-x);
    }
}

ll Query(int x, int y) {
    ll ret = 0;
    while(x > 0) {
        ret += Bit[x][y];
        x -= x & (-x);
    }
    return ret;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)cin >> a[i]; ++k;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= min(i + 1, k); ++j) {
            if(j == 1)update(a[i], 1, 1);
            else update(a[i], j, Query(a[i] - 1, j - 1));
        }
    }

    cout << Query(n, k) << endl;


    return 0;
}
