/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 50 + 5, mod = 100000007;
int tc, n, k, casee = 1, a[N], c[N], dp[51][21][1005];

int rec(int idx, int sum, int cnt) {
    if(idx > n)return 0;
    if(sum == k)return 1;
    int &ret = dp[idx][cnt][sum];
    if(~ret)return ret;
    ret = 0;
    if(cnt < c[idx] && a[idx] + sum <= k) {
        ret += rec(idx, a[idx] + sum, cnt + 1) % mod;
    }
    ret += rec(idx + 1, sum, 0) % mod;
    return ret % mod;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    ios_base::sync_with_stdio(false);
    cin.tie(0); //cout.tie(0);
    cin >> tc;
    while(tc--) {
        cin >> n >> k;
        for(int i = 1; i <= n; i++)cin >> a[i];
        for(int i = 1; i <= n; i++)cin >> c[i];
        memset(dp, -1, sizeof dp);
        cout << "Case " << casee++ << ": " << rec(1, 0, 0) << endl;
    }


    return 0;
}
