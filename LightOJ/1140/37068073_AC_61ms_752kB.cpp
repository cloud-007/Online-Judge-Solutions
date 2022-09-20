/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
int tc, n, casee = 1;
ll dp[11][2][2], dp1[11][2];
string x, y;

ll Count(int idx, bool isSmall) {
    if(idx == y.size())return 1;
    ll &ret = dp1[idx][isSmall];
    if(~ret)return ret;
    ret = 0;
    int lo = 0, hi = y[idx] - '0';
    if(isSmall) hi = 9;
    for(int i = lo; i <= hi; i++) {
        ret += Count(idx + 1, isSmall | (i < hi));
    }
    return ret;
}

ll rec(int idx, bool isSmall, bool hasStarted) {
    if(idx == y.size())return 0;
    ll &ret = dp[idx][isSmall][hasStarted];
    if(~ret)return ret;
    ret = 0;
    int lo = 0, hi = y[idx] - '0';
    if(isSmall)hi = 9;
    for(int i = lo; i <= hi; i++) {
        ret += rec(idx + 1, isSmall | (i < hi), hasStarted | (i != 0));
        if(hasStarted && i == 0)ret += Count(idx + 1, isSmall | (i < hi));
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
        cin >> x >> y;
        memset(dp, -1, sizeof dp);
        memset(dp1, -1, sizeof dp1);
        ll Ans = rec(0, false, false);
        int now = stoi(x);
        --now;
        y = to_string(max(0, now));
        memset(dp, -1, sizeof dp);
        memset(dp1, -1, sizeof dp1);
        if(x != "0")Ans -= rec(0, false, false);
        else Ans++;
        cout << "Case " << casee++ << ": " << Ans << endl;
    }


    return 0;
}
