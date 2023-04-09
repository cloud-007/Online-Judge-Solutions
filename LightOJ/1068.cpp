/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1, a, k;
ll dp[32][82][82][2][2];
string b;

ll rec(int idx, int sum, int mod, bool isSmall, bool hasStarted) {
    if(idx >= n)return ((mod + sum) == 0 && hasStarted);
    ll &ret = dp[idx][sum][mod][isSmall][hasStarted];
    if(~ret)return ret;
    ret = 0;
    int lo = 0, hi = b[idx] - '0';
    if(isSmall)hi = 9;
    for(int i = lo; i <= hi; i++) {
        ret += rec(idx + 1, (sum + i) % k, ((mod * 10) + i) % k, isSmall | (i < hi), hasStarted | (i != 0));
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
        cin >> a  >> b >> k;
        memset(dp, -1, sizeof dp);
        if(k > 90) {
            cout << "Case " << casee++ << ": " << 0 << endl;
            continue;
        }
        n = b.size();
        ll Ans = rec(0, 0, 0, 0, 0);
        --a;
        if(a) {
            b = to_string(a);
            n = b.size();
            memset(dp, -1, sizeof dp);
            Ans -= rec(0, 0, 0, 0, 0);
        }
        cout << "Case " << casee++ << ": " << Ans << endl;
    }

    return 0;
}
