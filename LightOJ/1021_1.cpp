/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 20 + 5;
int tc, n, base, k, casee = 1, a[N];
ll dp[N][(1 << 16) + 5];

ll rec(int mask, int mod) {
    if(mask == (1 << n) - 1)return mod == 0;
    ll &ret = dp[mod][mask];
    if(~ret)return ret;
    ret = 0;
    for(int i = 0; i < n; i++) {
        if(mask & (1 << i))continue;
        ret += rec(mask | (1 << i), (mod * base + a[i]) % k);
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
        string s; cin >> base >> k >> s;
        n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] >= '0' && s[i] <= '9')a[i] = s[i] - '0';
            else a[i] = s[i] - 'A' + 10;
        }

        memset(dp, -1, sizeof dp);

        cout << "Case " << casee++ << ": " << rec(0, 0) << endl;
    }


    return 0;
}
