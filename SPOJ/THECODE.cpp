/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 1e4;
int tc, n, d, a[sz], dp[sz], ans;
string s;

int rec(int idx, int mask) {
    if(mask == (1 << 10) - 1)return 0;
    if(idx == n)return 1e5;
    if(~dp[mask])return dp[mask];

    dp[mask] = min(rec(idx+1, mask), 1+rec(idx+1, mask|a[idx]));

    return dp[mask];
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> tc;
    while(tc--) {
        cin >> n >> d;
        for(int i = 0; i < n; i++) {
            cin >> s;
            int tot = 0;
            for(auto j : s)tot |= 1 << (j - '0');
            a[i] = tot;
        }
        memset(dp, -1, sizeof dp);
        ans = rec(0, 0);
        if(ans == 1e5)ans = -1;

        cout << ans << endl;
    }


    return 0;
}
