/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 10 + 5;
int tc, n, base, k, casee = 1, a[N];
string s;
ll dp[(1 << N)][25];

int check(char c) {
    if(c >= '0' && c <= '9')return c - '0';
    else return c - 'A' + 10;
}

ll rec(int mask, int mod) {
    if(mask == (1 << n) - 1)return mod == 0;
    ll &ret = dp[mask][mod];
    if(~ret)return ret;
    ret = 0;
    for(int i = 0; i < n; i++) {
        if(mask & (1 << i))continue;
        ret += rec(mask | (1 << i), (mod * base + check(s[i])) % k);
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
        cin >> base >> k >> s;
        n = s.size();
        memset(dp, -1, sizeof dp);
        cout << "Case " << casee++ << ": " << rec(0, 0) << endl;
    }


    return 0;
}
