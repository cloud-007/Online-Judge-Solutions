/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 50 + 5, mod = 1e8 + 7;
int tc, n, k, casee = 1, a[N], c[N], dp[N][N][1005];

int rec(int idx, int cnt, int sum) {
    if(sum > k)return 0;

    if(sum == k) {
        return 1;
    }

    if(idx > n)return 0;
    int &ret = dp[idx][cnt][sum];
    if(~ret)return ret;
    ret = 0;

    if(cnt < c[idx]) {
        ret += rec(idx, cnt + 1, sum + a[idx]);
        ret %= mod;
    }

    ret += rec(idx + 1, 0, sum);

    ret %= mod;

    return ret;
}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
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
