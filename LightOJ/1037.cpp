/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 12 + 5;
int tc, n, casee = 1, a[N], c[N][N];
ll dp[(1 << N)];

ll rec(int mask) {
    if(mask == (1 << n) - 1)return 0;
    ll &ret = dp[mask];
    if(~ret)return ret;
    ret = INT_MAX;

    for(int i = 0; i < n; i++) {
        if(mask & (1 << i))continue;
        int mx = 0;
        for(int j = 0; j < n; j++) {
            if(mask & (1 << j))mx = max(mx, c[j][i]);
        }
        mx = max(mx, 1);
        ret = min(ret, (a[i] / mx + (a[i] % mx > 0)) + rec(mask | (1 << i)));
    }

    return ret;

}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 0; i < n; i++)cin >> a[i];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                char x; cin >> x;
                c[i][j] = x - '0';
            }
        }
        memset(dp, -1, sizeof dp);
        cout << "Case " << casee++ << ": " << rec(0) << endl;
    }


    return 0;
}
