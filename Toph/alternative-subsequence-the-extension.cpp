/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define endl "\n"
#define Endl "\n"

const int N = 2e5 + 5;
ll tc, n, casee = 1, a[N], dp[N][2];

ll rec(int idx, int pre) {
    if(idx > n)return 0;
    ll &ret = dp[idx][pre];
    if(~ret)return ret;
    ret = 0;
    ret = rec(idx + 1, pre);
    if((pre == 0 && a[idx] < 0) || (pre == 1 && a[idx] > 0)) {
        ret = max(ret, a[idx] + rec(idx + 1, !pre));
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
            cin >> a[i];
            dp[i][0] = dp[i][1] = -1;
        }
        cout << max(rec(1, 0), rec(1, 1)) << endl;
    }


    return 0;
}
