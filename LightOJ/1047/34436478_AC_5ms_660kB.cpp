/*One touch and i IGNITE*/
#include<bits/stdc++.h>
using namespace std;
#define To_Infinity_And_Beyond ios_base::sync_with_stdio(false),cin.tie(0)
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
    ret = 1e5;

    for(int i = 0; i <= 2; i++) {
        if(pre == i)continue;
        int add = i == 0 ? r[idx] : i == 1 ? g[idx] : b[idx];
        ret = min(ret, add + rec(idx + 1, i));
    }

    return ret;

}

int main() {
#ifdef cloud_007
    freopen("in.txt", "r", stdin);
#endif // cloud_007
    To_Infinity_And_Beyond;
    cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 1; i <= n; i++)cin >> r[i] >> g[i] >> b[i];

        memset(dp, -1, sizeof dp);

        cout << "Case " << casee++ << ": " << rec(1, -1) << endl;

    }


    return 0;
}
