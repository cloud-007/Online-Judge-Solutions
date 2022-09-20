/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

ll tc, n, casee = 1, a[22][22], dp[22][(1 << 22) + 5];
const int mod = 1e9 + 7;

ll rec(int idx, int mask) {
    if(mask == (1 << n) - 1)return 1;
    if(idx >= n)return 0;

    if(~dp[idx][mask])return dp[idx][mask];

    ll way = 0;

    for(int i = 0; i < n; i++) {
        if(mask & (1 << i))continue;
        if(a[idx][i] == 1)way += rec(idx + 1, mask | (1 << i)) % mod;
    }

    return dp[idx][mask] = (way + mod) % mod;
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    memset(dp, -1, sizeof dp);

    cout << rec(0, 0) << endl;



    return 0;
}
