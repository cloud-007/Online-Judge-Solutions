/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 1e4 + 5, mod = 10000007;
int tc, n, casee = 1, dp[N];

int a, b, c, d, e, f;
int fn(int n) {
    if(n == 0) return a;
    if(n == 1) return b;
    if(n == 2) return c;
    if(n == 3) return d;
    if(n == 4) return e;
    if(n == 5) return f;

    int &ret = dp[n];
    if(~ret)return ret;
    ret = 0;
    ret = fn(n - 1) % mod + fn(n - 2) % mod + fn(n - 3) % mod + fn(n - 4) % mod + fn(n - 5) % mod + fn(n - 6) % mod;
    ret %= mod;
    if(ret < 0)ret = (ret + mod) % mod;
    return ret;
}

int main() {

#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007

    int n, cases;
    scanf("%d", &cases);
    for(int caseno = 1; caseno <= cases; ++caseno) {
        memset(dp, -1, sizeof dp);
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %d\n", caseno, fn(n) % mod);
    }
    return 0;
}
