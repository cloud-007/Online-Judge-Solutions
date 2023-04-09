/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 20 + 5;
int tc, n, casee = 1, r[N], g[N], b[N], dp[N][4];

int rec(int idx, int pre) {
    if(idx > n)return 0;
    int &ret = dp[idx][pre];
    if(~ret)return ret;
    ret = INT_MAX;
    if(idx == 1) {
        ret = min(ret, r[idx] + rec(idx + 1, 1));
        ret = min(ret, g[idx] + rec(idx + 1, 2));
        ret = min(ret, b[idx] + rec(idx + 1, 3));
    } else {
        if(pre == 1) {
            ret = min(ret, g[idx] + rec(idx + 1, 2));
            ret = min(ret, b[idx] + rec(idx + 1, 3));
        } else if(pre == 2) {
            ret = min(ret, r[idx] + rec(idx + 1, 1));
            ret = min(ret, b[idx] + rec(idx + 1, 3));
        } else {
            ret = min(ret, r[idx] + rec(idx + 1, 1));
            ret = min(ret, g[idx] + rec(idx + 1, 2));
        }
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
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> r[i] >> g[i] >> b[i];
        }
        memset(dp, -1, sizeof dp);
        cout << "Case " << casee++ << ": " << rec(1, 0) << endl;
    }


    return 0;
}
