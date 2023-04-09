/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define cloud_007 ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int sz = 2e6 + 5, mod = 1e9 + 7;
ll tc, n, a[sz], dp[sz], pref[sz], dev[sz], ans[sz], mx = 0;

void pre() {
    dp[ 0 ] = 1;
    for(int i = 1; i < sz; i++)dp[i] = (dp[ i - 1 ] * 2ll) % mod;
}

void divisor(int x) {
    for(int i = 1; i * i <= x; i++) {
        if(x % i)continue;
        dev[i]++;
        if(i != (x / i))dev[(x / i)]++;
    }
}

int main() {
#ifdef cloud007
    freopen("in.txt", "r", stdin);
#endif // cloud007
    cloud_007;
    pre();
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        divisor(a[i]);
    }

    ll sum = 0;

    for(int i = mx; i > 1; i--) {
        ans[i] = (dev[i] * dp[dev[i] - 1]) % mod;
        for(int j = 2; i * j <= mx; j++) {
            ans[i] = (ans[ i ] - ans[ j * i ] + mod) % mod;
        }
        sum = (sum + i * ans[i]) % mod;
    }

    cout << sum << endl;

    return 0;
}
