/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 20;
int tc, n, a[sz], dp[(1 << sz) + 5], sum = 0, ans = INT_MAX;

void rec(int mask, int sum, int sum1) {
    ans = min(ans, abs(sum - sum1));
    if(mask == (1 << n) - 1)return ;
    if(~dp[mask])return;

    for(int i = 0; i < n; i++) {
        if(mask & (1 << i))continue;
        rec(mask | (1 << i), sum + a[i], sum1 - a[i]);
    }
    dp[mask] =1;
    return ;
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    cin >> n;
    for(int i = 0; i < n; i++)cin >> a[i], sum += a[i];

    // cout << sum << endl;

    memset(dp, -1, sizeof dp);

    rec(0, 0, sum);

    cout << ans << endl;


    return 0;
}
